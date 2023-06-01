#include "graph.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(){
    std::string filePath = R"(/home/bmac/matheusnz/Documentos/ep3demac0323/example.txt)";
    std::ifstream inputFile(filePath);
    std::vector<int> vec;
    int vertNum;
    int edgeNum;
    if (!inputFile.is_open()) {
        std::cout << "Falha ao abrir o arquivo de texto" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            int number = stoi(word);
            vec.push_back(number);
        }
    }
    vertNum = vec[0];
    edgeNum = vec[1];
    Graph graph = GRAPHinit(vec[0]);
    for (int i = 3; i < edgeNum; ++i){
        GRAPHinsertArc(graph, vec[i], vec[i+1]);
    }
}