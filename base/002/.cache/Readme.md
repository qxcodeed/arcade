## @002 L2 - {human} distance create

![](https://raw.githubusercontent.com/qxcodefup/arcade/master/base/002/cover.jpg)

Tente criar um gerador de problemas Limite. Você pode seguir a seguinte sequência:

- Utilize argc e argv para receber o tamanho da string e o valor de limite desejado.

```
./solver 8 4

problema: 42..0..3. 4
resposta: 423104231
```
- Inicie a string com todos os valores vazios.
- Gere uma solução para essa string vazia, mas ao invés de testar os números sequencialmente de 0 a D em cada posição, coloque-os em um vetor e os embaralhe.
- Crie uma lista com todas as posições válidas da resposta e embaralhe.
    - para cada posição
        - se remover esse index, gerar apenas uma única solução para o problema, remova o index



<!--FILTER solver.cpp cpp-->
```cpp
const char EMPTY = '.';

//metodo genérico para formatar um container como texto
template <class T>
std::string fmt(T data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? ", " : "") << *it;
    ss << "]";
    return ss.str();
}

//gera um vector generico de [beg, end[
template <class T>
std::vector<T> range(T _beg, T _end) {
    std::vector<T> output;
    for (char c = _beg; c < _end; c++)
        output.push_back(c);
    return output;
}

//embaralha e retorna um vetor generico
template <class T>
std::vector<T> shuffle(std::vector<T> vet) {
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

struct Problem {
    std::string data;
    int lim;
    std::vector<int> holes; //posicoes a preencher

    Problem(std::string data, int lim) { ... }

    //se posso colocar esse valor em data[index]
    bool fit(int index, char value) { ... }

    //tenta resolver o problema recursivamente retornando na primeira solução encontrada
    bool solve(int hindex) { ... }

    //tenta resoler o problema recursivamente contando quantas soluções existem
    int count_solutions(int hindex) { ... }

    //verifica se remover essa posição, gera uma única solução
    bool can_remove(int index) { ... }

    //pega a lista de todas as posições e embaralha
    //para cada posição, se removê-la gera um problema com única solução
    //então remova
    void fill_holes() { ... }
};


int main(int argc, char * argv[]) {
    srand(time(0));
    int size { 5 }, lim { 3 };
    if (argc < 3) {
        puts("Passe size e lim como argumentos");
        return 1;
    }
    std::istringstream(argv[1]) >> size;
    std::istringstream(argv[2]) >> lim;
    std::cout << size << ' ' << lim << '\n';

    Problem prob(std::string(size, EMPTY), lim);
    prob.solve(0);
    std::cout << prob.data << "\n";
    prob.fill_holes();
    std::cout << prob.data << '\n';
}
```
<!--FILTER_END-->