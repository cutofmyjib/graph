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
    int matrix_size = adj_matrix[0].size();

    cout << "--- Starting Breadth First Search ---" << endl;
    cout << "Index of starting vertex: " << start_index << endl;

    //mark all vertices as unvisited
    for (int i = 0; i < matrix_size; i++)
        visited.push_back(false);

    int start_vertex = start_index;
    myqueue.push(start_vertex);
    visited[start_vertex] = true;

    while (!myqueue.empty()) {
        int vertex = myqueue.front();
        myqueue.pop();
        
        cout << "\t" << vertex << endl;
        
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
    cout << "--- End of Breadth First Search ---" << endl;
}

void Graph::DFSHelper(int index, vector<bool> *visited)
{
    (*visited)[index] = true;

    cout << "\t" << index << endl;

    // Loop through adj_matrix to find neighbors
    for (int i = 0; i < adj_matrix[index].size(); i++) {
        int first_neighbor = i;
        int edge = adj_matrix[index][i];
        // cout<< edge << " <-edge" << endl;
        if(edge == 1) {
            //enqueue neighbor if it hasn't been visited
            if (!(*visited)[first_neighbor]) {
                DFSHelper(first_neighbor, visited);
            } 
        }
    }

}

void Graph::DFS(int start_index)
{
    int matrix_size = adj_matrix.size();
    vector<bool> *visited = new vector<bool>(matrix_size);

    //mark all vertices as unvisited
    for (int i = 0; i < matrix_size; i++)
        (*visited)[i] = false;

    cout << "--- Starting Depth First Search ---" << endl;
    cout << "Index of starting vertex: " << start_index << endl;

    DFSHelper(start_index, visited);

    cout << "--- End of Depth First Search ---" << endl;
}


void Graph::ShowMatrix()
{
    bool is_weighted_graph = getGraphType();
    
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