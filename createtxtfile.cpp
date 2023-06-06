#include <string>
#include <vector>

using namespace std;

string createfile(vector<string> pieces, int numPieces, int minSize, int maxSize, int edgeParam){
    string text;
    int numVertices = pieces.size();
    vector<string> edges; // Index of edge connections 0 -> 1, 2 -> 3, 4 -> 5 ...
    for (int i = 0; i < numVertices; ++i){
        for (int j = 0; j < numVertices; ++j){
            if (match(pieces[i], pieces[j], edgeParam)){
                edges.push_back(pieces[i]);
                edges.push_back(pieces[j]);
            }
        }
    }
}

bool match(string one, string two, int edgeParam){
    int i = one.size() - edgeParam;
    int j = edgeParam;
    while (i >= 0 && j < two.size())
    {
        std::cout << "one: " << one.substr(i, string::npos) << "  two: " << two.substr(0, j) << std::endl;
        if (one.substr(i, string::npos) == two.substr(0, j)) return true;
        i -= 1;
        j += 1;
    }
    
}