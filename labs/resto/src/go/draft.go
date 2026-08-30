// DEL!
package main
import "fmt"

func Empilha(v int){
    if v == 0{
        return
    }

    q := v/2
    r := v%2

    Empilha(q)

    fmt.Printf("%d %d\n", q,r)
}


func main() {
    var v int

    fmt.Scan(&v)

    Empilha(v)
}
