#include "graph.cpp"
#include "createedges.cpp"
#include <string>

using namespace std;

int main()
{
    match("testando", "matheus", 2);
    string pieces;
    int numPieces, minSize, maxSize;
    int numVertices, numEdges;
    int edgeParam;


    cout << "Enter the Number of Vertices" << endl;
    cin >> numVertices;
      
    cout << "Enter the Number of Edges" << endl;
    cin >> numEdges;
    
    //initialize empty graph for our vertices
    graph g(numVertices);
    
    vertex source, dest;
    
    //add edges and create vertices as needed  
    for (int i = 0; i < numEdges; i++) {
        cout << "Enter the source vertex" << endl;
        cin >> source;
        cout << "Enter the destination vertex" << endl;
        cin >> dest;
        add_edge(g, source, dest);
    }
    
    cout << "The Adjacency List is:" << endl;
    print_graph(g);
      
    cout << "Enter the start vertex" << endl;
    cin >> source;
      
    cout << "Enter the end vertex" << endl;
    cin >> dest;
    
    path p = find_path(g, source, dest);
    
    print_path(p);
     
    return 0;
}
