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

void CreateMatrixFrom(string filename, Graph *matrix) {
    
    fstream file;
    file.open(filename);

    string line;

    //fill matrix with values
    while(getline(file, line))
    {   
        //create a vector to represent a row, and add it to the adjList.
        vector<int> row;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ',') {
                row.push_back(line[i]);
            } 
        }
        matrix->adj_matrix.push_back(row);
    }
    file.close();
}