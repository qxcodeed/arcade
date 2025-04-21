package main

import (
	"fmt"
	"math"
	"os"
)

type Pen struct {
	X           float64
	Y           float64
	color       string
	strokeWidth int
	heading     float64
	isDown      bool
	elements    []string
	width       int
	height      int
}

func NewPen(width, height int) *Pen {
	return &Pen{
		X:           float64(width) / 2,
		Y:           float64(height) / 2,
		color:       "rgb(0,0,0)",
		strokeWidth: 1,
		heading:     0,
		isDown:      true,
		elements:    []string{},
		width:       width,
		height:      height,
	}
}

func (p *Pen) SetPosition(x, y float64) {
	p.X = x
	p.Y = y
}

func (p *Pen) SetColor(r, g, b int) {
	p.color = fmt.Sprintf("rgb(%d,%d,%d)", r, g, b)
}

func (p *Pen) SetStrokeWidth(strokeWidth int) {
	p.strokeWidth = strokeWidth
}
func (p *Pen) SetHeading(heading float64) {
	p.heading = heading
}
func (p *Pen) SetDown(isDown bool) {
	p.isDown = isDown
}
func (p *Pen) Move(x, y float64) {
	if p.isDown {
		p.elements = append(p.elements, fmt.Sprintf(
			"<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" stroke-width=\"%d\" />",
			p.X, p.Y, x, y, p.color, p.strokeWidth))
	}
	p.X = x
	p.Y = y
}

func (p *Pen) DrawCircle(radius float64) {
	if p.isDown {
		p.elements = append(p.elements, fmt.Sprintf(
			"<circle cx=\"%f\" cy=\"%f\" r=\"%f\" stroke=\"%s\" fill=\"none\" stroke-width=\"%d\" />",
			p.X, p.Y, radius, p.color, p.strokeWidth))
	}
}

func (p *Pen) Walk(distance float64) {
	newX := p.X + distance*math.Cos(p.heading*math.Pi/180)
	newY := p.Y - distance*math.Sin(p.heading*math.Pi/180)
	p.Move(newX, newY)
}

func (p *Pen) Rotate(angle float64) {
	p.heading += angle
	if p.heading >= 360 {
		p.heading -= 360
	} else if p.heading < 0 {
		p.heading += 360
	}
}

func (p *Pen) SaveToFile(filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	_, err = file.WriteString(fmt.Sprintf("<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", p.width, p.height))
	if err != nil {
		return err
	}

	// draw the background
	_, _ = file.WriteString(fmt.Sprintf("<rect width=\"%d\" height=\"%d\" fill=\"white\" />\n", p.width, p.height))

	for _, element := range p.elements {
		_, err = file.WriteString(element + "\n")
		if err != nil {
			return err
		}
	}

	_, err = file.WriteString("</svg>")
	return err
}
