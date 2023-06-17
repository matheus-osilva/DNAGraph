#ifndef DNAGRAPH_GRAPHS_H
#define DNAGRAPH_GRAPHS_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>


class Digraph {
private:
    int V;
    int E;
    std::vector<std::vector<int>> adj;

public:
    Digraph(int V);

    int getV();

    int getE();

    void addEdge(int v, int w);

    void removeEdge(int v, int w);

    std::vector<int> getadj(int v);

    Digraph reverse();

    void print();

};

#endif // DNAGRAPH_GRAPHS_H
