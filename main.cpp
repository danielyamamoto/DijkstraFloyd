/*
Imprime con el algoritmo de Dijkstra la distancia del nodo i al nodo j 
para todos los nodos, y luego, la matriz resultado del algoritmo de Floyd.

Autores:
Yusdivia Molina 
Daniel Yamamoto
Héctor Noyola

Fecha de modificación: 01/10/2021
*/

#include <fstream>
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

// Complejidad O(n^2)
vector<vector<int>> readFile(string file) {
    vector<vector<int>> board;
    vector<int> tmp;
    string row, num;

    fstream f;
    f.open(file);
    getline(f, row);
    
    for (int i = 0; i < stoi(row); i++) {
        for (int j = 0; j < stoi(row); j++) {
            f >> num;
            tmp.push_back(stoi(num));
        }
        board.push_back(tmp);
        tmp.clear();
    }
    f.close();
    return board;
}

int main() {
    // Primer TXT
    cout << "Primer parte || TXT 1\n";
    vector<vector<int>> matrix = readFile("in.txt");
    Graph g(matrix);

    cout << "\nDijkstra\n";    
    for(int i = 0; i < matrix.size(); i++) {
        g.Dijkstra(i);
    }

    cout << "\nFloyd\n";
    g.Floyd();
    
    // Segundo TXT
    cout << "\nSegunda parte || TXT 2\n" ;
    vector<vector<int>> matrix2 = readFile("in2.txt");
    Graph g2(matrix2);

    cout << "\nDijkstra\n";    
    for(int i = 0; i < matrix2.size(); i++) {
        g2.Dijkstra(i);
    }

    cout << "\nFloyd\n";
    g2.Floyd();
}