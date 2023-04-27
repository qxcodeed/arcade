## @024 L3 - bank

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/024/cover.jpg)

Neste trabalho, nós simularemos o atendimento em um banco. O nosso banco tem clientes que estão sendo atendidos no caixa, clientes na espera na fila e clientes na fila de saída. Cada cliente tem um nível de paciência (quantidade de tempo que ele pode esperar na fila) e uma quantidade de documentos a serem processados no caixa.

## Guia

Você deve implementar o seguinte código seguindo as instruções em cada função. Observe que várias funções já estão implementadas. Você pode criar métodos auxiliares se precisar. Se atente a implementar onde está com o `{ ... }`.

<!--FILTER solver.cpp cpp-->
```cpp
struct Client {
    string name {""};
    int docs {0};
    int patience { 0 };
    Client(string name, int docs, int patience) { ... }
    string str() { ... }
};

struct Bank {
    vector<Client*> tellers;    //caixas
    list<Client*> queue_in;     //fila de entrada
    list<Client*> queue_out;    //fila de saida
    int docs_gain {0};          //documentos processados
    int docs_lost {0};          //documentos perdidos
    int tics {0};               //quantidade de tempo que passou

    //  Roda o algoritmo de passagem de tempo
    void tic() {
        tics++;
        empty_queue_out();
        for (int i = 0; i < (int) tellers.size(); i++)
            process_teller(i);
        decrease_patience();
    }

    //  iniciliza os caixas com um vetor de nulls
    Bank(int teller_size) { ... }

    // deleta qualquer cliente que tenha sobrado no banco
    ~Bank() { ... }

    //  cria o cliente e insere na fila de entrada
    void arrive(std::string name, int docs, int patience) { ... }

    //  esta vazio se não tem ninguém no banco
    bool empty() { ... }

    //  Retirar todos os clientes da fila de saída
    //
    //  para cada cliente da fila de saida, 
    //      this->docs_lost incrementa dos documentos não processado
    //      chame o delete para cada um deles
    void empty_queue_out() { ... }

    //  Processar caixa
    //
    //  se o caixa tem algum cliente
    //      se o cliente do caixa tiver algum documento para processar
    //          incrementa em um this->docs_gain
    //          decrementa em um os documentos do cliente
    //      senão
    //          move o cliente para fila de saída
    //  senão
    //      se tem alguem na fila de espera
    //          move o primeiro da fila de espera para o caixa
    void process_teller(int index) { ... }


    //  Processar fila de entrada
    //
    //  para cada cliente da fila de entrada
    //      se a paciencia dele for maior que zero
    //          decremente em um o valor da paciencia
    //      senão
    //          mova para fila de saida
    void decrease_patience() { ... }

    //continua chamando tic até todos os clientes terem ido embora
    void finish() { ... }

    //gera uma string com os dados dos banco
    std::string str() { ... }
};

int main() {
    Bank banco(3);

    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end") {
            break;
        }else if (cmd == "show") {
            std::cout << banco.str() << "\n";
        } else if (cmd == "in") {
            string name { };
            int docs { }, patience { };
            ss >> name >> docs >> patience;
            banco.arrive(name, docs, patience);
        } else if (cmd == "init") {
            int size { };
            ss >> size;
            banco = Bank(size);
        } else if (cmd == "tic") {
            banco.tic();
        } else if (cmd == "finish") {
            banco.finish();
        } else {
            cout << "fail: command not found\n";
        }
    }
}
```
<!--FILTER_END-->

## Testes

```bash
#__case init
# inicia a quantidade de caixas 
$init 3

# mostra os caixas, a fila de entrada e a fila de saída
$show
[][][]
in  :{}
out :{}
gain:0 lost:0

#__case in
# O comando 'in' adiciona um cliente na fila
# in _nome _acoes _paciencia
$in Ai 4 6
$in Bo 2 3
$in Ce 3 8
$in Di 3 5
$in Em 3 2

$show
[][][]
in  :{Ai:4:6 Bo:2:3 Ce:3:8 Di:3:5 Em:3:2}
out :{}
gain:0 lost:0


#__case tic
# O comando 'tic' faz passar um intervalo de tempo
$tic

$show
[Ai:4:6][Bo:2:3][Ce:3:8]
in  :{Di:3:4 Em:3:1}
out :{}
gain:0 lost:0

#__case tic2
$tic

$show
[Ai:3:6][Bo:1:3][Ce:2:8]
in  :{Di:3:3 Em:3:0}
out :{}
gain:3 lost:0

#__case tic 3
$tic

$in Fa 4 5

$show
[Ai:2:6][Bo:0:3][Ce:1:8]
in  :{Di:3:2 Fa:4:5}
out :{Em:3:0}
gain:6 lost:0

#__case tic 4
$tic
$show
[Ai:1:6][][Ce:0:8]
in  :{Di:3:1 Fa:4:4}
out :{Bo:0:3}
gain:8 lost:3

$tic
$show
[Ai:0:6][Di:3:1][]
in  :{Fa:4:3}
out :{Ce:0:8}
gain:9 lost:3

#__case tic 5
$tic
$show
[][Di:2:1][Fa:4:3]
in  :{}
out :{Ai:0:6}
gain:10 lost:3

$tic
$show
[][Di:1:1][Fa:3:3]
in  :{}
out :{}
gain:12 lost:3

$tic
$show
[][Di:0:1][Fa:2:3]
in  :{}
out :{}
gain:14 lost:3

$tic
$show
[][][Fa:1:3]
in  :{}
out :{Di:0:1}
gain:15 lost:3

$tic
$show
[][][Fa:0:3]
in  :{}
out :{}
gain:16 lost:3

$tic
$show
[][][]
in  :{}
out :{Fa:0:3}
gain:16 lost:3

$tic
$show
[][][]
in  :{}
out :{}
gain:16 lost:3

# end termina a simulação
$end
```

