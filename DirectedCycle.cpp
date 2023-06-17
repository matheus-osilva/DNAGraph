#include "DirectedCycle.h"

//Digraph functions

Digraph::Digraph(int V) {
    this->V = V;
    this->E = 0;
    adj.resize(V);
    for (int v = 0; v < V; v++) {
        adj[v] = std::vector<int>();
    }
}

int Digraph::getV() {
    return V;
}

int Digraph::getE() {
    return E;
}

void Digraph::addEdge(int v, int w) {
    adj[v].push_back(w);
    E++;
}

void Digraph::removeEdge(int v, int w) {
    auto it = std::find(adj[v].begin(), adj[v].end(), w);
    if (it != adj[v].end()) {
        adj[v].erase(it);
        E--;
    }
}

std::vector<int> Digraph::getadj(int v) {
    return adj[v];
}

Digraph Digraph::reverse() {
    Digraph R(V);
    for (int v = 0; v < V; v++) {
        for (int w : adj[v]) {
            R.addEdge(w, v);
        }
    }
    return R;
}

void Digraph::print() {
    std::cout << "Vertices:\n";
    for (int v = 0; v < V; v++) {
        std::cout << v << ": ";
        for (int w : adj[v]) {
            std::cout << w << " ";
        }
        std::cout << "\n";
    }
}

//DirectedCycle Functions

DirectedCycle::DirectedCycle(Digraph G)
{
    onStack = new bool[G.getV()];
    edgeTo = new int[G.getV()];
    marked = new bool[G.getV()];
    for (int v = 0; v < G.getV(); v++){
        if (!marked[v]) dfs(G, v);
    }

}
void DirectedCycle::dfs(Digraph G, int v)
{
    onStack[v] = true;
    marked[v] = true;
    for (int w : G.getadj(v))
        if (this->hasCycle()) return;
        else if (!marked[w])
        {
            edgeTo[w] = v;
            dfs(G, w);
        }
        else if (onStack[w])
        {
            cycle = std::stack<int>();
            for (int x = v; x != w; x = edgeTo[x]) cycle.push(x);
            cycle.push(w);
            cycle.push(v);
        }
    onStack[v] = false;
}
bool DirectedCycle::hasCycle()
{
    return !cycle.empty();
}
std::stack<int> DirectedCycle::getcycle()
{
    return cycle;
}