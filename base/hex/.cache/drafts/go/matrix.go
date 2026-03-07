package main

import (
	"fmt"
	"math"
	"math/rand/v2"
	"os"
)

type Pos struct {
	L int
	C int
}

func NewPos(l, c int) Pos {
	return Pos{L: l, C: c}
}

func (v Pos) GetHexNeighbors() []Pos {
	delta := 1
	if v.L%2 == 0 {
		delta = 0
	}
	return []Pos{
		{v.L - 1, delta + v.C - 1}, // up left
		{v.L - 1, delta + v.C},     // up right
		{v.L, v.C + 1},             // right
		{v.L + 1, delta + v.C},     // down right
		{v.L + 1, delta + v.C - 1}, // down left
		{v.L, v.C - 1},             // left
	}
}

func (v Pos) GetSquareNeighbors() []Pos {
	return []Pos{
		{v.L - 1, v.C}, // up
		{v.L, v.C + 1}, // right
		{v.L + 1, v.C}, // down
		{v.L, v.C - 1}, // left
	}
}

type Matrix struct {
	NL   int
	NC   int
	Info [][]rune
}

func NewMatrix(nl, nc int, color rune) *Matrix {
	matrix := Matrix{
		NL:   nl,
		NC:   nc,
		Info: make([][]rune, nl),
	}
	for l := range matrix.Info {
		matrix.Info[l] = make([]rune, nc)
		for c := range matrix.Info[l] {
			matrix.Info[l][c] = color // default color
		}
	}
	return &matrix
}

func (m *Matrix) Contains(pos Pos) bool {
	return pos.L >= 0 && pos.L < m.NL && pos.C >= 0 && pos.C < m.NC
}

func (m *Matrix) Get(pos Pos) rune {
	if m.Contains(pos) {
		return m.Info[pos.L][pos.C]
	}
	return ' '
}

func (m *Matrix) Set(pos Pos, color rune) {
	if m.Contains(pos) {
		m.Info[pos.L][pos.C] = color
	}
}

func Shuffle[T any](slice []T) []T {
	other := make([]T, len(slice))
	copy(other, slice)

	rand.Shuffle(len(other), func(i, j int) {
		other[i], other[j] = other[j], other[i]
	})
	return other
}

func getColor(c rune) string {
	colorCodeMap := map[rune]string{
		'r': "red", 'g': "green", 'b': "blue", 'w': "white", 'k': "black", 'y': "yellow",
		'o': "orange", 'p': "purple", 'm': "magenta", 'c': "cyan",
	}
	if color, ok := colorCodeMap[c]; ok {
		return color
	}
	return ""
}

func (m *Matrix) SaveSquareGrid(filename string) {
	a := 30.0 // tamanho do lado do quadrado
	// Cálculo aproximado da largura e altura do SVG
	svgWidth := float64(m.NC) * a
	svgHeight := float64(m.NL) * a
	// Cria (ou sobrescreve) o arquivo grid.svg
	file, err := os.Create(filename)
	if err != nil {
		panic(err)
	}
	defer file.Close()
	// Cabeçalho do SVG
	fmt.Fprintf(file, `<svg xmlns="http://www.w3.org/2000/svg" width="%f" height="%f">`+"\n", svgWidth, svgHeight)
	// Geração dos quadrados com preenchimento branco
	for i := range m.NL {
		for j := range m.NC {
			// Fórmula para o centro do quadrado:
			cx := float64(j)*a + a/2
			cy := float64(i)*a + a/2
			// Adiciona o retângulo SVG para o quadrado com preenchimento branco
			color := getColor(m.Get(Pos{i, j}))
			if color == "" {
				color = "white"
			}
			fmt.Fprintf(file, `<rect x="%f" y="%f" width="%f" height="%f" stroke="black" fill="%s"/>`+"\n", cx-a/2, cy-a/2, a, a, color)
		}
	}
	// Fecha o SVG
	fmt.Fprintln(file, "</svg>")
}

func (m *Matrix) SaveHexGrid(filename string) {

	nl := m.NL // número de linhas
	nc := m.NC // número de colunas
	a := 30.0  // tamanho do lado do hexágono
	// Para hexágonos pointy top:
	// - A distância horizontal entre os centros é: sqrt(3)*a
	// - A distância vertical entre os centros é: 1.5*a
	// Cálculo aproximado da largura e altura do SVG
	svgWidth := math.Sqrt(3)*a*float64(nc) + math.Sqrt(3)/2*a
	svgHeight := 1.5*a*float64(nl-1) + 2*a
	// Cria (ou sobrescreve) o arquivo grid.svg
	file, err := os.Create(filename)
	if err != nil {
		panic(err)
	}
	defer file.Close()
	// Cabeçalho do SVG
	fmt.Fprintf(file, `<svg xmlns="http://www.w3.org/2000/svg" width="%f" height="%f">`+"\n", svgWidth, svgHeight)
	// Geração dos hexágonos com preenchimento branco
	// Cria um grande rect branco para cobrir o fundo
	fmt.Fprintf(file, `<rect x="0" y="0" width="%f" height="%f" fill="black"/>`+"\n", svgWidth, svgHeight)
	for i := range nl {
		for j := range nc {
			// Fórmula para o centro do hexágono:
			// Em linhas ímpares (começando em 0), deslocamos o centro para a direita em (sqrt(3)/2*a)
			cx := float64(j) * math.Sqrt(3) * a
			if i%2 == 1 {
				cx += math.Sqrt(3) / 2 * a
			}
			// Ajuste vertical: desloca o grid para baixo em "a" para evitar corte superior
			cy := float64(i)*1.5*a + a
			// Calcula os 6 vértices do hexágono
			points := ""
			for k := range 6 {
				angle := math.Pi/6 + float64(k)*math.Pi/3 // ângulo inicial de 30° (π/6)
				x := cx + a*math.Cos(angle) + a*math.Sqrt(3)/2
				y := cy + a*math.Sin(angle)
				points += fmt.Sprintf("%f,%f ", x, y)
			}
			// Adiciona o polígono SVG para o hexágono com preenchimento branco
			color := getColor(m.Get(Pos{i, j}))
			if color == "" {
				color = "white"
			}
			fmt.Fprintf(file, `<polygon points="%s" stroke="black" fill="%s"/>`+"\n", points, color)
		}
	}

	// Fecha o SVG
	fmt.Fprintln(file, "</svg>")
}
