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
    Graph mygraph = Graph(filename);
    CreateMatrixFrom(filename, &mygraph);

    mygraph.ShowMatrix();
    cout << endl;

    //traverse the graph Breadth First
    mygraph.BFS(0);
    cout << endl;
    
    //traverse the graph Depth First
    mygraph.DFS(5);
    cout << endl;

    cout << "Number of vertices: " << mygraph.GetTotalVertices() << endl;
    cout << endl;

    cout << "Number of edges: " << mygraph.GetTotalEdges() << endl;
    cout << endl;

    cout << "Is the graph connected? " << (mygraph.IsConnected() ? "true" : "false") << endl;
    cout << endl;

}