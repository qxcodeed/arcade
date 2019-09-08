#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "lib.hpp"

using namespace std;
#define PROF

#ifdef PROF
bool find_path(Node * node, int value, string &path, string tag = " "){
    if(node == nullptr)
        return false;
    path += tag;
    if(node->value == value){
        path += "x";
        return true;
    }
    if(find_path(node->left, value, path, "l") || find_path(node->right, value, path, "r"))
        return true;
    path.pop_back();
    return false;
}
#else
#endif

string find(Node * root, int value){
#ifdef PROF
    string path;
    find_path(root, value, path, ">");
    if(path.back() == 'x')
        return path;
    return "value not fount";
#else
    return "";
#endif
}
