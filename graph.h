/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the graph header file.
***********************************************************/

#include <fstream> 
#include <iostream>     /* cout, endl */
#include <queue>
#include <stack>
#include <vector>

using namespace std;

//this is a directive that prevents .h files from being included more than once
#ifndef GRAPH_H
#define GRAPH_H

class Graph
{  
private:
    void DFSHelper(int index, vector <bool> *visited); 
    bool is_weighted;
public:
    vector< vector<int> > adj_matrix; //2D array (matrix)
    Graph(string filename);
    ~Graph();
    void BFS(int start_index);
    void DFS(int start_index);
    void ShowMatrix();
    bool GetGraphType();
    bool IsGraphWeighted(string filename);
};

#endif //GRAPH_H