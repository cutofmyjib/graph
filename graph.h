/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the graph header file.
***********************************************************/

#include <iostream>     /* cout, endl */
#include <queue>
#include <vector>

using namespace std;

//this is a directive that prevents .h files from being included more than once
#ifndef GRAPH_H
#define GRAPH_H

class Graph
{  
public:
    vector< vector<int> > adj_matrix; //2D array (matrix)
    Graph();
    ~Graph();
    void BFS(int start_index);
    void ShowMatrix();
};

#endif //GRAPH_H