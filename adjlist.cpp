#include <bits/stdc++.h>
using namespace std;
 
int createGraph(string filename)
{
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            table.put(word);
        }
    }
    // n is the number of vertices
    // m is the number of edges
    vertex n;
    int  m;
    cin >> n >> m;
    int adjMat[n + 1][n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << std::endl;
    }
 
    return 0;
}