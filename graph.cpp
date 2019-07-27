/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is where all the graph functions are defined.
***********************************************************/

#include "graph.h"

//CONSTRUCTOR
Graph::Graph(int SIZE)
{
    //matrix of dimensions SIZE * SIZE, all elements = 0.
    for (int i = 0; i < SIZE; i++)
        adj_matrix.resize(SIZE);
}

Graph::~Graph()
{

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