#include "graph.h"

void add_edge(graph& g, vertex source, vertex dest){
  g[source].push_back(dest);
}

//shows adjacency list for the given graph
void print_graph(graph& g){
    for (auto& value : g) { //auto& determines the type for us, in this case it is the pair: vertex (string), list<edge>
        vertex v = value.first;
        list<edge> adjacentVertices = value.second;
        list<edge>::iterator it = adjacentVertices.begin();
         
        cout << "from[" << v << "]";
          
        while (it != adjacentVertices.end()) {
            cout << " -> " << (*it);
            it++;
        }
         
        cout << endl;
    }
}

//finds and returns (if existing) the shortest path from start to end.
path find_path(graph& g, vertex start, vertex end){

  //track vertices already visited, if we go back to them, it is either a loop or not the shortest path, so we can ignore them the second time
  unordered_set<vertex> visited(g.size()); //at most, we visit each vertex once
  
  //we will do BFS and follow each path from the source, tracking what we did
  queue<path> q;
  
  //track the path followed from each vertex, starting from the given one
  //for each vertex reachable from the start
  for(edge nextVertex : g[start]){
    //track each reachable vertex
    queue<vertex> nextVertices;
    nextVertices.push(nextVertex);
    
    //remember the path we are taking
    path p = make_pair(start, nextVertices);
    
    //if the end is immediately found, return
    if(nextVertex == end){
      return p;
    }
        
    //otherwise add each path to our queue
    q.push(p);
  }
  
  visited.insert(start); //start is always already visited
  
  //walk the paths until we either find the destination or have visited all reachable vertices
  while(!q.empty()){
    //get the first path and remove it from the queue
    path p = q.front();
    q.pop();
    
    //check where can we go from here
    //if we already visited a place, discard it, it is a loop or not the shortest path
    //if we reach the destination, return the path we took, which will be the shortest
    
    //continue walking from the last place we arrived in the current path
    for(const edge& nextVertex : g[p.second.back()]){
    
      //if we did not visit this yet
      if(visited.find(nextVertex) == visited.end()){
      
        //mark as visited
        visited.insert(nextVertex);
        
        //add this new vertex to the current path and push the new path back in the queue
        queue<vertex> next_path = p.second;
        next_path.push(nextVertex);
        path new_path = make_pair(p.first, next_path);
        
        //if we reached the destination, we stop and return the path
        if(nextVertex == end){
          return new_path;
        }
        
        //otherwise continue walking down this path at the next iteration
        q.push(new_path);
      }
      
      //if we already visited this vertex, we do nothing and ignore this new path
    }
  }
  
  //if we reached this place, the queue is now empty, and we have no more vertices to visit, but also did not reach the destination, so return empty
  queue<vertex> empty;
  return make_pair("", empty);

}

void removeEdge(graph myGraph, const vertex& sourceVertex, const edge& destinationVertex) {
    auto it = myGraph.find(sourceVertex);
    if (it != myGraph.end()) {
        std::list<edge>& adjacentVertices = it->second;
        adjacentVertices.remove(destinationVertex);
    }
}

void print_path(const path& p){
    if(p.first.empty()){
      cout << "No path found";
    } else {
      queue<vertex> path_to_dest = p.second;
      
      cout << "Path to destination is: " << endl;
      cout << p.first << endl;
      
      while(!path_to_dest.empty()){
        cout << path_to_dest.front() << endl;
        path_to_dest.pop();
      }
    }
}

bool dfs(const graph& myGraph, const vertex& currentVertex, const vertex& targetVertex, std::unordered_set<vertex>& visitedVertices) {
    if (currentVertex == targetVertex) return true;
    visitedVertices.insert(currentVertex);
    const auto& adjacentVertices = myGraph.at(currentVertex);
    for (const auto& adjacentVertex : adjacentVertices) {
        if (visitedVertices.find(adjacentVertex) == visitedVertices.end()) {
            if (dfs(myGraph, adjacentVertex, targetVertex, visitedVertices)) return true;
        }
    }
    visitedVertices.erase(currentVertex);
    return false;
}

bool isCircuitPresent(const graph& myGraph, const vertex& startVertex, const vertex& targetVertex) {
    std::unordered_set<vertex> visitedVertices;
    return dfs(myGraph, startVertex, targetVertex, visitedVertices);
}

void checkEdgesInCircuit(const graph& myGraph) {
    for (const auto& vertexPair : myGraph) {
        vertex currentVertex = vertexPair.first;
        const auto& adjacentVertices = vertexPair.second;

        for (const auto& adjacentVertex : adjacentVertices) {
            if (isCircuitPresent(myGraph, adjacentVertex, currentVertex)) {
                std::cout << "Edge: " << currentVertex << " -> " << adjacentVertex << " is in a circuit." << std::endl;
                removeEdge(myGraph, currentVertex, adjacentVertex);
            } else {
                std::cout << "Edge: " << currentVertex << " -> " << adjacentVertex << " is not in a circuit." << std::endl;
            }
        }
    }
}