#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

typedef string vertex; //the label of this vertex

typedef vertex edge; //edge contains destination vertex

typedef unordered_map<vertex, list<edge>> graph; //graph is for each source vertex, list of adjacent (destination) vertices

typedef pair<vertex, queue<vertex>> path; //we use this to track the path followed from a given vertex while going to the destination

//functions
void add_edge(graph& g, vertex source, vertex dest);
void print_graph(graph& g);
void checkEdgesInCircuit(const graph& myGraph);
path find_path(graph& g, vertex start, vertex end);










