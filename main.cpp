/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"
#include "iofile.h"
#include "graph.h"

int main(int argc, char** argv) {

    bool canCreateMatrix = isValidFile(argc, argv);
    string filename = argv[1];
    if (!canCreateMatrix) {
        cout << filename << " could not be opened.\n";
    }

    //create graph with size of matrixSize
    Graph myGraph = Graph(getMatrixSize(filename));

    createMatrixFrom(filename, &myGraph);
    myGraph.showMatrix();
}