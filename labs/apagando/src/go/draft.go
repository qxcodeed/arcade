package main
import "fmt"
func main() {
	// @DROP
    var qtd int
    fmt.Scan(&qtd)

    fila := make([]int, qtd)

    for i := range fila{
        var j int
        fmt.Scan(&j)
        fila[i] = j
    }

    var qtdRemover int

    fmt.Scan(&qtdRemover)

    remover := make(map[int] int)

    for i := 0; i < qtdRemover; i++{
        var j int
        fmt.Scan(&j)

        remover[j] = j
    }

    for i, e := range fila{
        if remover[e] == e{
            fila[i] = 0
        }
    }

    for i := range fila{
        if fila[i] != 0{
            fmt.Printf("%d ", fila[i])
        }
    }

    fmt.Println()
    
}
