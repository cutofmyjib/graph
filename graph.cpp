/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is where all the graph functions are defined.
***********************************************************/

#include "graph.h"

//CONSTRUCTOR
Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::BFS()
{
    queue<int> myqueue;
    vector<bool> visited;
    int matrix_size = adj_matrix[0].size();

    //mark all vertices as unvisited
    for (int i = 0; i < matrix_size; i++)
        visited.push_back(false);

    int start_vertex = 0;
    myqueue.push(start_vertex);
    visited[start_vertex] = true;

    while (!myqueue.empty()) {
        int vertex = myqueue.front();
        myqueue.pop();
        
        cout << vertex << " <-vertex" << endl;
        
        // Loop through adj_matrix[vertex] to find neighbors
        for (int i = 0; i < adj_matrix[0].size(); i++) {
            int neighbor = i;
            int edge = adj_matrix[vertex][i];
            
            if(edge == 1) {
                //enqueue neighbor if it hasn't been visited
                if (!visited[neighbor]) {
                    
                    myqueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    cout << "BFS Done" << endl;
}

void Graph::ShowMatrix()
{
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            bool newline = false;
            if (j == adj_matrix[i].size()-1) 
                newline = true;

            cout << adj_matrix[i][j] << " " << (newline ? "\n" : "");
        }
    }
}