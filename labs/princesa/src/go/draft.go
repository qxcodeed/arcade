// DEL!

package main

import "fmt"


type Nodo struct {
    valor int
    proximo *Nodo
}

type ListaEncadeada struct {
    cabeca *Nodo
}

func CriaLista()(*ListaEncadeada){
    lista := ListaEncadeada{}
    return &lista
}

func PopulaLista(c *ListaEncadeada, t int) {
    var ultimo *Nodo

    for i := 1; i <= t; i++ {
        novo := &Nodo{valor: i}

        if c.cabeca == nil {
            c.cabeca = novo
            ultimo = novo
        } else {
            ultimo.proximo = novo
            ultimo = novo
        }
    }

    if ultimo != nil {
        ultimo.proximo = c.cabeca
    }
}



func ExibeElementosDaLista(c *ListaEncadeada, espada int){
    temp := c.cabeca
    fmt.Print("[")
    qtd := 0
    for{
        if temp == c.cabeca && qtd != 0{
            break
        }
        if(temp.valor == espada){
            fmt.Printf(" %d>", temp.valor)
        }else{
            
            fmt.Printf(" %d", temp.valor)
        }
        temp = temp.proximo

        qtd++
    }
    fmt.Print(" ]\n")
}

func MataUmDaLista(c *ListaEncadeada, espada *int) {
    
    anterior := c.cabeca

    for anterior.proximo.valor != *espada {
        anterior = anterior.proximo
    }

    atual := anterior.proximo

    eliminado := atual.proximo

    if eliminado == c.cabeca {
        c.cabeca = eliminado.proximo
    }

    atual.proximo = eliminado.proximo

    *espada = atual.proximo.valor
}


func ContaElementosLista(c *ListaEncadeada) int {
    qtd := 0
    temp := c.cabeca
    if temp == nil {
        return 0
    }

    for {
        qtd++
        temp = temp.proximo
        if temp == c.cabeca {
            break
        }
    }

    return qtd
}


func main(){

    var lista = CriaLista()
    var q int
    var espada int

    fmt.Scan(&q)
    fmt.Scan(&espada)
    PopulaLista(lista, q)
       
   for{
        qtd := ContaElementosLista(lista)
        if qtd == 1{
            ExibeElementosDaLista(lista, espada)
            break
        }
        ExibeElementosDaLista(lista, espada)
        MataUmDaLista(lista, &espada)
   }

      
}