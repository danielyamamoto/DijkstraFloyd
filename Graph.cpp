#include "Graph.h"

// Constructor del grafo
// Complejidad O(n^2)
Graph::Graph(vector<vector<int>> v) {
    vertex = v.size();
    vector<int> temp;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            temp.push_back(v[i][j]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
}

// Imprime la matriz
// Complejidad O(n^2)
void Graph::printMatrix() {
    for(auto &v: matrix) {
        for (auto &w: v) {
            cout << w << " ";
        }
        cout << "\n";
    }
}

// Complejidad O(1)
void Graph::addEdge(int x, int y, int z) {
    Edge e(x, y, z);
    edgeList.push_back(e);
    matrix[x][y] = z;
}

// Obtiene los nodos vecinos
// Complejidad O(n)
vector<int> Graph::getNeighbors(int u) {
    vector<int> neighbors;
    for (int i = 0; i < matrix[u].size(); i++) {
        if (matrix[u][i] > 0) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

// Obtiene la distancia mínima entre uno A y uno B
// Complejidad O(n)
int Graph::getMin(vector<int> q, vector<bool> &v) {
    int minDist = 1000;
    int res = -1;
    for (int i = 0; i < q.size(); i++) {
        if (q[i] < minDist && !v[i]) {
            minDist = q[i];
            res = i;
        }
    }
    v[res] = true;
    return res;
}

// Complejidad O(1)
int Graph::getLength(int source, int destination) {
    return matrix[source][destination];
}

// Complejidad O(|V|+|E|log|V|)
void Graph::Dijkstra(int source) {
    vector<int> q;             // Vértices
    vector<int> distances;     // Distancias
    vector<int> prevs;         // Previos
    vector<bool> visited;      // Nodos que se usaron
    
    for (int i = 0; i < vertex; i++) {
        prevs.push_back(-1);
        // Inicializa las distancias con un valor muy grande
        distances.push_back(1000);
        q.push_back(i);
        visited.push_back(false);
    }
    
    distances[source] = 0;
    
    while(!q.empty()) {
        int u = getMin(distances, visited);
        // Complejidad remove O(n)
        // Liga: https://newbedev.com/time-complexity-of-removing-items-in-vectors-and-deque
        q.erase(std::remove(q.begin(), q.end(), u), q.end()); 
        vector<int> neighbors = getNeighbors(u);
        vector<int>::iterator v;

        for(v = neighbors.begin(); v != neighbors.end(); v++) {
          // complejidad find O(n)
          // https://medium.com/@gx578007/searching-vector-set-and-unordered-set-6649d1aa7752
            if (find(q.begin(), q.end(), (*v)) != q.end()) {
                int alt = distances[u] + getLength(u, (*v));
                if (alt < distances[(*v)]) {
                    distances[*v] = alt;
                    prevs[(*v)] = u;
                }
            }
        }
    }

    // Imprime la distancia entre nodos 
    for (int i = 0; i < vertex; i++) {
        if (source+1 != i+1) {     
            cout << "node " << source+1 << " to node " << i+1 << ": " << distances[i] << "\n";
        }
    }
}

// Complejidad O(|V|^2)
void Graph::printFloyd(vector<vector<int>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (auto &x: m[i]) {
            // Agrega un 0 a los números x <= 9 para hacer la matriz "cuadrada", sino se desfaza
            if (x <= 9) { cout << "0" << x << " "; }
            else { cout << x << " "; } 
        }
        cout << "\n";
    }
}

// Complejidad O(|V|^3)
void Graph::Floyd() {
    vector<vector<int>> dist = matrix;
    for (int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++){
            if(dist[i][j] <= 0){
                dist[i][j] = 1000;
            }
        }
        dist[i][i] = 0;
    }
    
    for (int k = 0; k < vertex; k++) {
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                if (dist[i][j] > dist[i][k]+dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Imprime la matriz de resultados
    printFloyd(dist); // Complejidad O(n^2)
}