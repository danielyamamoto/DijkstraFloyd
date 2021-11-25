#include "Edge.h"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertex;
    vector<vector<int> >matrix;
  
public: 
    Graph(vector<vector<int>> v);
    void printMatrix();
    vector<Edge> edgeList;
    void addEdge(int x, int y, int z); 
    void Dijkstra(int source);
    int getMin(vector<int> d, vector<bool> &v);
    int getLength(int source, int destination);
    void remove(vector<int> q, int u);
    vector<int> getNeighbors(int u);
    void Floyd();
    void printFloyd(vector<vector<int>>);
};
