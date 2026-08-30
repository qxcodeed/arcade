# @subconjuntos

Dado um conjunto $S$, podemos definir o conjunto de todos os subconjuntos de S, denotado por $\mathcal{P}(S)$, de maneira recursiva:

$
\mathcal{P}(S) = 
\begin{cases}
\{\emptyset\}, S = \emptyset\\
\mathcal{P}(S') \cup \{ B \cup \{x\} |B \in \mathcal{P}(S')\}             , S = S' \cup \{x\}
\end{cases} 
$




No exemplo acima, estamos imprimindo todos os números em ordem decrescente de 4 até 1. Neste exemplo, vamos considerar que o caso base acontece quando o valor de n é igual a 0. A ação fundamental será imprimir um número e depois resolver o mesmo problema para o número anterior.

```c
void countDown(int n){
	if(n == 0){
		return ;
	}else{
		cout << n << endl;
		countDown(n-1);
	}
}	
``` 

Considere agora o seguinte padrão de impressão:

```
4
3
2
1
1
2
3
4
```

Esse padrão pode ser reproduzido pelo seguinte programa:

```c
void countDownUp(int n){
	if(n == 0){
		return ;
	}else{
		cout << n << endl;
		countDownUp(n-1);
		cout << n << endl;
	}
}
```


Já o padrão de impressão:

```
wladimir
ladimir
adimir
dimir
imir
mir
ir
r
```

O padrão pode ser reproduzido pelo seguinte programa:


```c
void printTower(char * s){
	if(*s == '\0'){
		return;
	}else{
		printf("%s\n", s);
		printTower(s+1);
	}
}
```

Faça um program que imprima todos os sufixos de uma palavra do menor sufixo até o maior.


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
r
ir
mir
imir
dimir
adimir
ladimir
wladimir
```

