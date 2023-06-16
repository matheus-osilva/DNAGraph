#include "createedges.h"


/* return the lower size of two strings */
int lowerSize(string one, string two){
    int lower = -1;
    if (one.size() <= two.size()){
        lower = one.size();
    } 
    else lower = two.size();
    return lower;
}

/*match function return if there is a two or more elements in the end of string one matching
  the beginning of string two, check first the max number of matching letters
*/
bool match(string one, string two, int edgeParam){
    int lower = lowerSize(one, two);
    int i = one.size() - lower;
    int j = lower;
    while (i <= one.size() - 1 && j >= edgeParam)
    {
        if (one.substr(i, string::npos) == two.substr(0, j)) return true;
        i += 1;
        j -= 1;
    }
    return false;
}

void createfile(vector<string> pieces, int edgeParam){
    string text;
    stringstream aux;
    string aux2;
    int aux10 = 0;
    int numVertices = pieces.size();
    vector<string> edges; // Index of edge connections 0 -> 1, 2 -> 3, 4 -> 5 ...
    for (int i = 0; i < numVertices; ++i){
        for (int j = 0; j < numVertices; ++j){
            if (i != j && match(pieces[i], pieces[j], edgeParam)){
                aux10 += 1;
                edges.push_back(pieces[i]);
                edges.push_back(pieces[j]);
            }
        }
    }
    aux << numVertices;
    aux >> aux2;
    /*text.append(aux2);
    text.append(" ");*/
    aux.clear();
    aux << edges.size() / 2;
    aux >> aux2;
    /*text.append(aux2);
    text.append("\n");*/
    for (int i = 0; i < edges.size() - 1; i += 2){
        text.append(edges[i]);
        text.append(" ");
        text.append(edges[i+1]);
        text.append("\n");
    }
    ofstream file("edges.txt");
    file << text;
    file.close();
}
