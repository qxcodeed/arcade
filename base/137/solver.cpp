#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

// char WALL = '█';
char WALL = '#';

struct Pos {
    int l, c;
    Pos(int l, int c): l(l), c(c){}
    bool operator==(Pos pos) { return pos.l == l && pos.c == c; }
    bool operator!=(Pos pos) { return !(*this==pos); }
    std::vector<Pos> get_neib() {
        return { Pos { l, c - 1 }, Pos { l - 1, c }, Pos { l, c + 1 }, Pos { l + 1, c } };
    }
    std::vector<Pos> get_diag() {
        return { Pos { l - 1, c - 1 }, Pos { l - 1, c + 1 }, 
                 Pos { l + 1, c + 1 }, Pos { l + 1, c - 1 }};
    }
};

template <class T>
T shuffle(T container) {
    std::random_shuffle(begin(container), end(container));
    return container;
}

struct Mapa {
    int nl {0}, nc {0};
    std::vector<std::string> data;
    Mapa(int nl, int nc, char def): nl(nl), nc(nc), data(nl, std::string(nc, def)) {}
    char& operator[](Pos pos) { return data[pos.l][pos.c]; }
    bool inside(Pos pos) { return !(pos.l < 0 || pos.l >= nl || pos.c < 0 || pos.c >= nc); }
    bool check(Pos pos, char value) { return inside(pos) && (*this)[pos] == value; }
    std::string str() {
        std::stringstream ss;
        for (int l = 0; l < nl; l++) {
            for (int c = 0; c < nc; c++)
                ss << (data[l][c] == WALL ? "█" : std::string(1, data[l][c]));
            ss << '\n';
        }
        return ss.str();
    }
};

auto exists = [](auto vet, auto value) { 
    return std::find(begin(vet), end(vet), value) != end(vet); 
};

void destroy(Mapa& mat, Pos pos, Pos from) {
    // is possible solution
    if (!mat.check(pos, WALL))              // nao eh parede
        return;
    
    for (auto neib : pos.get_neib())
        if (neib != from && !mat.check(neib, WALL)) //tem algum vizinho que não seja a origem que esteja furado
            return;

    //tem alguma diagonal, que não seja vizinha da origem, que esteja aberta
    for (auto neib : pos.get_diag())
        if (!exists(from.get_neib(), neib) && !mat.check(neib, WALL))
            return;
    
    mat[pos] = ' ';
    for (Pos neib : shuffle(pos.get_neib()))
        destroy(mat, neib, pos);
}

int main(int argc, char * argv[]) {
    int nl {15}, nc {80};
    if (argc > 2) {
        std::istringstream(argv[1]) >> nl;
        std::istringstream(argv[2]) >> nc;
    }
    Mapa mat(nl, nc, WALL);
    destroy(mat, Pos(1, 1), Pos(1, 1));
    std::cout << mat.str();
}
