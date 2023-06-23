#include "createedges.h"
#include "dna.h"
#include "SymbolGraph.h"
#include "Digraph.h"
#include <string>

using namespace std;

int main()
{
    cout << "Bem-vindo ao simulador de sequenciamento genetico!" << endl;
    cout << "Feito por Matheus Oliveira da Silva, num USP 13696262" << endl;
    cout << "Algoritmos e Estrutura de Dados Exercicio Programa 3" << endl;
    cout << "Essa simulacao contem dois modos:" << endl;
    while(true){
        string sequence;
        vector<string> pieces;
        int numPieces, minSize, maxSize, edgeParam, mode = 10;
        cout << "Insira a sequencia do DNA (insira sair para encerrar o programa): " << endl;
        cin >> sequence;
        if (sequence == "sair") break;
        cout << "Insira o numero de pedacos que a sequencia sera dividida: " << endl;
        cin >> numPieces;
        cout << "Insira o tamanho minimo de cada pedaco: " << endl;
        cin >> minSize;
        cout << "Insira o tamanho maximo de cada pedaco: " << endl;
        cin >> maxSize;
        cout << "Insira o parametro de construcao dos arcos (k): " << endl;
        cin >> edgeParam;
        pieces = splitdna(sequence, numPieces, minSize, maxSize);
        createfile(pieces, edgeParam);
        SymbolGraph sgraph = SymbolGraph("edges.txt", " ");
        Digraph graph = sgraph.getGraph();
        int counter = 1;
        for (int v = 0; v < graph.getV(); v++) {
            for (int w : graph.getadj(v)) {
                if(graph.isEdgeInCircuit(v, w)) {
                    graph.removeEdge(v, w);
                }
                counter++;
            }
        }
        sgraph.print();
        graph.print();
        vector<vector<int>> longestPaths;
        longestPaths.push_back(graph.longestPath(0));
        int cont = 0;

        for (int v = 1; v < graph.getV(); v++) {
            vector<int> path = graph.longestPath(v);
            if (path.size() > longestPaths[cont].size()) {
                longestPaths.clear();
                longestPaths.push_back(path);
                cont = 0;
            } else if (path.size() == longestPaths[cont].size()) {
                longestPaths.push_back(path);
                cont++;
            }
        }
        cout << "Maior(es) caminho(s) usando o indice como referencia: " << endl;
        for (int i = 0; i < longestPaths.size(); i++)
        {
            for (int j = 0; j < longestPaths[i].size(); j++)
            {
                std::cout << longestPaths[i][j] << "->";
            }
            std::cout << std::endl;
        }
        
        cout << "Maior(es) caminho(s) concatenado, resultado final: " << endl;
        vector<vector<string>> stringPaths;
        stringPaths.reserve(longestPaths.size());
        for (const auto& longestPath : longestPaths) {
            stringPaths.push_back(sgraph.mapIntToString(longestPath));
        }
        for (const auto& path : stringPaths) {
            for (auto it = path.begin(); it != path.end(); ++it) {
                const auto& piece = *it;
                if (it != path.end() - 1) {
                    cout << removeSuffixIfMatched(piece, *(it + 1), edgeParam);
                } else {
                    cout << piece;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
