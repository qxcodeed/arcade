#pragma once

#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef pair<size_t, size_t> Pos;

vector<Pos> get_neib(Pos p);

bool inside(vector<string> &mat, Pos p);

void queimar(vector<string> &mat, size_t l, size_t c);
