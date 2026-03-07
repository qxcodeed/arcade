package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Vector2d struct {
	X float64
	Y float64
}

// parses a point with (4.5123,3.12) string format
func NewVector2dFromSerial(serial string) Vector2d {
	serial = serial[1 : len(serial)-1]
	var parts []string = strings.Split(serial, ",")
	X, _ := strconv.ParseFloat(parts[0], 64)
	Y, _ := strconv.ParseFloat(parts[1], 64)
	return Vector2d{X: X, Y: Y}
}

func (p Vector2d) Dist(q Vector2d) float64 {
	return (p.X-q.X)*(p.X-q.X) + (p.Y-q.Y)*(p.Y-q.Y)
}

func (p Vector2d) String() string {
	return "(" + fmt.Sprintf("%.0f", p.X) + "," + fmt.Sprintf("%.0f", p.Y) + ")"
}

type Circle struct {
	Center Vector2d
	Radius float64
}

func (c Circle) String() string {
	return "Circle: " + c.Center.String() + ", Radius: " + fmt.Sprintf("%.0f", c.Radius)
}

func (c Circle) RelationWithPoint(p Vector2d) string {
	if c.Center.Dist(p) < c.Radius {
		return "inside"
	}
	return "outside"
}

// options: inside, intersect, outside
func (c Circle) RelationWithCircle(c2 Circle) string {
	dist := c.Center.Dist(c2.Center)

	switch {
	case dist > c.Radius+c2.Radius:
		return "outside"
	case dist < min(c2.Radius, c.Radius):
		return "inside"
	}
	return "intersect"
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("$")
		if !scanner.Scan() {
			break
		}
		line := scanner.Text()
		args := strings.Split(line, " ")
		fmt.Println(line)

		switch args[0] {
		case "dist":
			
		}
	}
}
