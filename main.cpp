#include "graph.cpp"
#include "createedges.cpp"
#include "dna.cpp"
#include <string>

using namespace std;

int main()
{
    string sequence;
    vector<string> pieces;
    int numPieces, minSize, maxSize, edgeParam;
    /*cout << "Enter the DNA sequence: " << endl;
    cin >> sequence;
    cout << "Enter the number of pieces the sequence will be splitted: " << endl;
    cin >> numPieces;
    cout << "Enter the minimum size of each piece: " << endl;
    cin >> minSize;
    cout << "Enter the maximum size of each piece: " << endl;
    cin >> maxSize;
    cout << "Enter the parameter to build the edges (k): " << endl;
    cin >> edgeParam;
    */
    sequence = "ACTCGTAAATACATAACGATAC";
    numPieces = 12;
    minSize = 4;
    maxSize = 6;
    edgeParam = 2;

    pieces = splitdna(sequence, numPieces, minSize, maxSize);
    createfile(pieces, edgeParam);

    string myText;
    string myWord;
    int numVertices, numEdges;
    numVertices = numPieces;
    ifstream MyReadFile("edges.txt");
    getline(MyReadFile, myText);
    myWord = myText.substr(myText.find(" "), myText.find("/") - 1);
    numEdges = stoi(myWord);

    //initialize empty graph for our vertices
    graph g(numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        g[pieces[i]].clear();
    }
    
    
    vertex source, dest;
    

    //add edges and create vertices as needed  
    for (int i = 0; i < numEdges; i++) {
        getline(MyReadFile, myText);
        source = myText.substr(0, myText.find(" "));
        dest = myText.substr(myText.find(" ") + 1, myText.find("\n"));
        add_edge(g, source, dest);
    }
    
    cout << "The Adjacency List is:" << endl;
    print_graph(g);
      
    /*
    cout << "Enter the start vertex" << endl;
    cin >> source;
      
    cout << "Enter the end vertex" << endl;
    cin >> dest;
    
    path p = find_path(g, source, dest);
    
    print_path(p);
    */
   
    checkEdgesInCircuit(g);

    return 0;
}
