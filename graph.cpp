/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is where all the graph functions are defined.
***********************************************************/

#include "graph.h"

//CONSTRUCTOR
Graph::Graph(string filename)
{
    is_weighted = isGraphWeighted(filename);
}

Graph::~Graph()
{

}

bool Graph::getGraphType()
{
    return is_weighted;
}

bool Graph::isGraphWeighted(string filename) {
    fstream file;
    file.open(filename);

    char first_char = file.peek();
    int first_char_int = static_cast<int>(first_char);
    
    //files start with X or 0, integer X == 88, 0 == 48
    bool is_weighted_graph = first_char_int == 48 ? true : false;
    
    file.close();

    return is_weighted_graph;
}


void Graph::BFS(int start_index)
{
    queue<int> myqueue;
    vector<bool> visited;
    bool is_weighted_graph = getGraphType();
    int matrix_size = adj_matrix[0].size();
    int start_pos = 0;
    
    if (!is_weighted_graph) {
        matrix_size -= 1;
        start_pos = 1;
    }

    cout << "--- Starting Breadth First Search ---" << endl;
    cout << "Index of starting vertex: " << start_index << endl;

    //mark all vertices as unvisited
    for (int i = 0; i < matrix_size; i++)
        visited.push_back(false);

    int start_vertex = (is_weighted_graph ? start_index : (start_index + 1));
    myqueue.push(start_vertex);
    visited[start_vertex] = true;

    while (!myqueue.empty()) {
        int vertex = myqueue.front();
        myqueue.pop();
        
        cout << "\t" << (is_weighted_graph ? vertex : (vertex-1)) << endl;
        
        // Loop through adj_matrix[vertex] to find neighbors
        for (int i = start_pos; i < adj_matrix[0].size(); i++) {
            int neighbor = i;
            int edge = adj_matrix[vertex][i];
            
            if((edge >= 49) && (edge <= 57)) {
                //enqueue neighbor if it hasn't been visited
                if (!visited[neighbor]) {
                    myqueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    cout << "--- End of Breadth First Search ---" << endl;
}

void Graph::DFSHelper(int index, vector<bool> *visited)
{
    bool is_weighted_graph = getGraphType();
    int graph_index = index;
    int matrix_row_size = adj_matrix[graph_index].size();
    int start_pos = 0;

    cout << "\t" << (is_weighted_graph ? graph_index : (graph_index-1)) << endl;
    (*visited)[graph_index] = true;

    if (!is_weighted_graph) {
        start_pos = 1;
    }


    // Loop through adj_matrix to find neighbors
    for (int i = start_pos; i < matrix_row_size; i++) {
        int first_neighbor = i;
        int edge = adj_matrix[graph_index][i];
        
        if((edge >= 49) && (edge <= 57)) {
            //enqueue neighbor if it hasn't been visited
            if (!(*visited)[first_neighbor]) {
                DFSHelper(first_neighbor, visited);
            } 
        }
    }

}

void Graph::DFS(int start_index)
{
    bool is_weighted_graph = getGraphType();
    int matrix_size = adj_matrix.size();
    int start_vertex = start_index;
    
    if (!is_weighted_graph) {
        matrix_size -= 1;
        start_vertex += 1;
    }

    vector<bool> *visited = new vector<bool>(matrix_size);
    cout << "matrix size " << matrix_size << endl;

    //mark all vertices as unvisited
    for (int i = 0; i < matrix_size; i++)
        (*visited)[i] = false;

    cout << "--- Starting Depth First Search ---" << endl;
    cout << "Index of starting vertex: " << start_index << endl;

    DFSHelper(start_vertex, visited);

    cout << "--- End of Depth First Search ---" << endl;
}


void Graph::ShowMatrix()
{    
    cout << "--------- Adjacency Matrix ---------" << endl;
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            bool newline = false;
            bool startline = false;
            int item = adj_matrix[i][j];

            if (j == adj_matrix[i].size()-1) 
                newline = true;
            if (j == 0)
                startline = true;

            cout << (startline ? "\t" : "")
                 << char(item)
                 << " " << (newline ? "\n" : "");
        }
    }
    cout << "-------------------------------------" << endl;
}