## #list 2. Lista Simulação Fila Bancária
## @qxcode

![](__capa.jpg)

```cpp
struct Client{
    string id;
    int docs;
    int pac; 
};

struct Banco{
    vector<Client*> caixas;
    list<Client*> fila_entrada;
    queue<Client*> fila_saida;
};

```

```
para todos os clientes na fila de saida
    remova cliente do banco
para todos os caixas
    se existe um cliente
        se o cliente tem documentos
            processe um documento desse cliente
        senao
            mova cliente para fila de saida
    senao
        se houver clientes na fila de entrada
            pegue um cliente da fila de entrada
para todos os clientes da fila de entrada
    se paciencia maior que zero
        decremente um na paciencia
    senao
        ponha na fila de saida
```


```bash
#__case one
# inicia a quantidade de caixas 
$init 3

# mostra os caixas, a fila de entrada e a filha de saída
$show
[][][]
in :{ }
out:{ }

# O comando 'in' aciona um cliente na fila
# in _nome _acoes _paciencia
$in Ai 4 6
$in Bo 2 3
$in Ce 3 8
$in Di 3 5
$in Em 3 2

$show
[][][]
in :{ Ai:4:6 Bo:2:3 Ce:3:8 Di:3:5 Em:3:2 }
out:{ }

# O comando 'tic' faz passar um intervalo de tempo. 
$tic

$show
[Ai:4:6][Bo:2:3][Ce:3:8]
in :{ Di:3:4 Em:3:1 }
out:{ }

$tic

$show
[Ai:3:6][Bo:1:3][Ce:2:8]
in :{ Di:3:3 Em:3:0 }
out:{ }

$tic

$in Fa 4 5

$show
[Ai:2:6][Bo:0:3][Ce:1:8]
in :{ Di:3:2 Fa:4:5 }
out:{ Em:3:0 }

$tic
$show
[Ai:1:6][][Ce:0:8]
in :{ Di:3:1 Fa:4:4 }
out:{ Bo:0:3 }

$tic
$show
[Ai:0:6][Di:3:1][]
in :{ Fa:4:3 }
out:{ Ce:0:8 }

$tic
$show
[][Di:2:1][Fa:4:3]
in :{ }
out:{ Ai:0:6 }

$tic
$show
[][Di:1:1][Fa:3:3]
in :{ }
out:{ }

$tic
$show
[][Di:0:1][Fa:2:3]
in :{ }
out:{ }

$tic
$show
[][][Fa:1:3]
in :{ }
out:{ Di:0:1 }

$tic
$show
[][][Fa:0:3]
in :{ }
out:{ }

$tic
$show
[][][]
in :{ }
out:{ Fa:0:3 }

$tic
$show
[][][]
in :{ }
out:{ }

# se existirem clientes ainda no banco, continue passando o tempo até esvaziar o banco
# mostra quantos documentos foram processados pelo banco
# mostra quantos documentos foram perdidos pelo banco com clientes
# que desistiram
$finish
received: 16
lost: 5
tics: 6

# end termina a simulacao
$end
```


# Parte 2

- Dado o valor de um dia de trabalho do caixa
- Calcule a quantidade ideal de caixas para maximizar o lucro.
- documentos_recebidos - total_caixas * 100











