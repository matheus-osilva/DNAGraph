#include "Digraph.h"

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
