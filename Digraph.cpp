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

bool Digraph::isEdgeInCircuit(int u, int v) {
    std::vector<bool> visited(V, false);
    std::stack<int> stack;
    visited[v] = true;
    stack.push(v);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        for (int neighbor : adj[current]) {
            if (neighbor == u) {
                return true;  // Found a path from v to u
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }

    return false;  // No path from v to u
}
