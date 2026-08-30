#include <iostream>
#include <fstream>

using namespace std;

void exemplo_arquivos(){
    ifstream arq("nomes.txt");
    if(!arq.is_open()){
        cout << "nao achei o arquivo" << endl;
        return;
    }

    string fruta;
    int soma = 0;
    while(arq >> fruta){
        int qtd;
        arq >> qtd;
        soma += qtd;
        cout << qtd << " " << fruta << endl;
    }
    arq.close();
}

int main()
{
    exemplo_arquivos();
    return 0;
}

