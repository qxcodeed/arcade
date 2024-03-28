# Imprimindo @diagonal

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/diagonal/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed diagonal`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

Faça um programa que recebe uma palavra com até 100 caracteres e imprime a palavra em diagonal.

**Entrada**

A entrada é composta por uma única linha contendo uma palavra com até 100 caracteres.

**Saída**

A saída é composta por `n` linhas sendo `n` o tamanho da palavra lida. 

**Exemplo de Entrada**
```
wladimir
```

**Exemplo de Saída**
```
w
 l
  a
   d
    i
     m
      i
       r
```

Dica:

```c
void diagonal(char * s, int k){
	if(*s == '\0'){
		return;
	}else{
		//imprima k caracteres
		//imprima o primeiro caractere de s e pule a linha
		//faça a chamada recursiva
	}
}
```


