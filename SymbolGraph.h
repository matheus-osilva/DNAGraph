#ifndef DNAGRAPH_SYMBOLGRAPH_H
#define DNAGRAPH_SYMBOLGRAPH_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Digraph.h"

class SymbolGraph {
private:
    std::unordered_map<std::string, int> st; // String -> index
    std::vector<std::string> keys; // index -> String
    Digraph G = Digraph(st.size());

public:
    SymbolGraph(const std::string& stream, const std::string& sp);

    bool contains(const std::string& s);

    int index(const std::string& s);

    std::string name(int v);

    Digraph getGraph();

    void print();
};

#endif // DNAGRAPH_SYMBOLGRAPH_H
