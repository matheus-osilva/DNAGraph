
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

std::vector<int> Digraph::longestPath(int s) {
    std::stack<int> Stack;
    std::vector<int> dist(V, std::numeric_limits<int>::min());
    std::vector<int> prev(V, -1);

    // Mark all the vertices as not visited
    std::vector<bool> visited(V, false);

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    // Initialize distances to all vertices as infinite and
    // distance to source as 0
    dist[s] = 0;

    // Process vertices in topological order
    while (Stack.empty() == false) {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();

        // Update distances of all adjacent vertices
        for (int v : adj[u]) {
            if (dist[u] != std::numeric_limits<int>::min()) {
                if (dist[v] < dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    prev[v] = u;
                }
            }
        }
    }

    // Find the vertex with the maximum distance
    int maxDistVertex = s;
    for (int i = 0; i < V; i++) {
        if (dist[i] > dist[maxDistVertex]) {
            maxDistVertex = i;
        }
    }

    // Reconstruct the longest path
    std::vector<int> longestPath;
    int current = maxDistVertex;
    while (current != -1) {
        longestPath.push_back(current);
        current = prev[current];
    }

    std::reverse(longestPath.begin(), longestPath.end());
    return longestPath;
}

void Digraph::topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
    visited[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, Stack);
        }
    }

    Stack.push(v);
}
/*
std::vector<int> Digraph::getLongestPath(int source) {
    std::vector<int> dist(V, std::numeric_limits<int>::min());
    std::vector<int> prev(V, -1);
    std::stack<int> stack;
    std::vector<bool> visited(V, false);

    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            topologicalSortUtil(v, visited, stack);
        }
    }

    dist[source] = 0;

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (dist[current] != std::numeric_limits<int>::min()) {
            for (int neighbor : adj[current]) {
                if (dist[current] + 1 > dist[neighbor]) {
                    dist[neighbor] = dist[current] + 1;
                    prev[neighbor] = current;
                }
            }
        }
    }

    // Reconstruct the longest path
    std::vector<int> longestPath;
    int current = V - 1;
    while (current != -1) {
        longestPath.push_back(current);
        current = prev[current];
    }

    std::reverse(longestPath.begin(), longestPath.end());
    return longestPath;
}

void Digraph::topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& stack) {
    visited[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, stack);
        }
    }

    stack.push(v);
}*/