/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the input output read file cpp.
***********************************************************/
#include "iofile.h"

bool IsValidFile(int argc, char** argv) {
    
    int arg_count = argc - 1; //1st argument doesn't count (executable file)
    bool has_param = arg_count >= 1;
    bool is_valid = true;
    fstream file;

    if (!has_param) 
        is_valid = false;

    string filename = argv[1];
    file.open(filename);

    if (!file) {
        is_valid = false;
    }

    return is_valid;
}

int GetMatrixSize(string filename) {
    fstream file;
    file.open(filename);

    bool is_weighted_graph = isGraphWeighted(filename);
    int matrix_size = 0;
    string line;

    if (is_weighted_graph) {
        matrix_size = (line.length() / 2);
    } else {
        matrix_size = (line.length() / 2) - 1; //comma + letters/2 - 1
    }
    
    return matrix_size;
    file.close();
}

bool isGraphWeighted(string filename) {
    fstream file;
    file.open(filename);

    char first_char = file.peek();
    int first_char_int = static_cast<int>(first_char);
    
    //files start with X or 0, integer X == 88, 0 == 48
    bool is_weighted_graph = first_char_int == 48 ? true : false;
    
    file.close();

    return is_weighted_graph;
}

void CreateMatrixFrom(string filename, Graph *matrix) {
    
    fstream file;
    file.open(filename);

    bool is_weighted_graph = isGraphWeighted(filename);
    int start_pos;
    string line;

    if (is_weighted_graph) {
        start_pos = 0;
    } else {
        start_pos = 1;
        getline(file,line, '\n'); //truncate first line
    }

    //fill matrix with values
    while(getline(file, line))
    {   
        vector<int> row;
        for (int i = start_pos; i < line.length(); i++) {
            if (line[i] != ',') {
                int num;
                if (line[i] == '0')
                    num = 0;
                else if (line[i] == '1')
                    num = 1;
                else
                    num = -1;

                // Create a vector to represent a row, and add it to the adjList.
                row.push_back(num); //convert to int
            }

        }
        matrix->adj_matrix.push_back(row);
    }
    file.close();
}