/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"
#include "iofile.h"
#include "graph.h"

int main(int argc, char** argv) {

    bool can_create_matrix = IsValidFile(argc, argv);
    string filename = argv[1];
    if (!can_create_matrix) {
        cout << filename << " could not be opened.\n";
    }

    //create graph, create adj. matrix from input file
    Graph mygraph = Graph();
    CreateMatrixFrom(filename, &mygraph);
    mygraph.ShowMatrix();
    
    //traverse the graph Breadth First
    mygraph.BFS(0);
    
    //traverse the graph Depth First
    mygraph.DFS(5);

}