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
        adjMatrix.resize(SIZE);
}

Graph::~Graph()
{

}

void Graph::showMatrix()
{
    for (int i = 0; i < adjMatrix.size(); i++) 
    {
        for (int j = 0; j < adjMatrix[i].size(); j++) 
        {
            bool newline = false;
            if (j == adjMatrix[i].size()-1) 
                newline = true;

            cout << adjMatrix[i][j] << " " << (newline ? "\n" : "");
        }
    }
}