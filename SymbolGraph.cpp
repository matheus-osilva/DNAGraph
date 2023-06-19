#include "SymbolGraph.h"

SymbolGraph::SymbolGraph(const std::string& stream, const std::string& sp) {
    std::ifstream inputFile(stream);
    std::string line;

    // First pass: builds the index
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;

        while (std::getline(iss, word, sp[0])) {
            if (st.find(word) == st.end()) // if the word is not in the map
                st[word] = st.size(); // associate it with a new index
        }
    }

    keys.resize(st.size());

    // Inverted index to get string keys as an array
    for (const auto& entry : st) {
        keys[entry.second] = entry.first;
    }

    G = Digraph(st.size());

    // Second pass: builds the graph
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg); // reset file pointer to the beginning

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;
        std::getline(iss, word, sp[0]);
        int v = st[word]; // first vertex

        while (std::getline(iss, word, sp[0])) {
            G.addEdge(v, st[word]); // connect the first vertex to all others on the line
        }
    }

    inputFile.close();
}

bool SymbolGraph::contains(const std::string& s) {
    return st.find(s) != st.end();
}

int SymbolGraph::index(const std::string& s) {
    return st[s];
}

std::string SymbolGraph::name(int v) {
    return keys[v];
}

Digraph SymbolGraph::getGraph() {
    return G;
}
void SymbolGraph::print() {
    std::cout << "Index Map:\n";
    for (const auto& entry : st) {
        std::cout << entry.first << " -> " << entry.second << "\n";
    }

    std::cout << "\nKeys:\n";
    for (int i = 0; i < keys.size(); i++) {
        std::cout << i << " -> " << keys[i] << "\n";
    }
}
/*void SymbolGraph::removeCycles() {
    Digraph G = getGraph();
    for (int v = 0; v < G.getV(); ++v) {
        DirectedCycle dc = DirectedCycle(G, v);
    }
}*/
