package main

import (
	"fmt"
	"math/rand"
)

func randInt(min, max int) int {
	return min + rand.Intn(max-min+1)
}

func tree(p *Pen, tam float64) {
	fator := 0.75
	ang := 35.0

	if tam < 10 {
		if randInt(0, 10) < 1 {
			p.SetColor(255, 0, 0)
			p.DrawCircle(tam)
		}
		return
	}
	p.SetColor(randInt(0, 255), randInt(0, 255), randInt(0, 255))
	p.SetStrokeWidth(int(tam / 10))
	p.Walk(tam)
	p.Rotate(-ang)
	tree(p, tam*fator)
	p.Rotate(2 * ang)
	tree(p, tam*fator)
	p.Rotate(-ang)
	p.Walk(-tam)
}

func main() {
	pen := NewPen(500, 500)
	pen.SetColor(255, 0, 0)
	pen.SetPosition(250, 500)
	pen.SetHeading(90)
	tree(pen, 100)
	pen.SaveToFile("tree.svg")
	fmt.Println("SVG file created successfully.")
}
