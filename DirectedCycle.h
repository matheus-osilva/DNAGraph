#ifndef DNAGRAPH_DIRECTEDCYCLE_H
#define DNAGRAPH_DIRECTEDCYCLE_H

#include <vector>
#include <stack>
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

class DirectedCycle
{
private:
    bool *marked;
    int *edgeTo;
    std::stack<int> cycle; // vertices on a cycle (if one exists)
    bool *onStack; // vertices on recursive call stack
public:
    DirectedCycle(Digraph G);
    void dfs(Digraph G, int v);
    bool hasCycle();
    std::stack<int> getcycle();
};

#endif // DNAGRAPH_DIRECTEDCYCLE_H
