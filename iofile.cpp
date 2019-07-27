/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the input output read file cpp.
***********************************************************/
#include "iofile.h"

bool isValidFile(int argc, char** argv) {
    
    int argCount = argc - 1; //1st argument doesn't count (executable file)
    bool hasParam = argCount >= 1;
    bool isValid = true;
    fstream file;

    if (!hasParam) 
        isValid = false;

    string fileName = argv[1];
    file.open(fileName);

    if (!file) {
        isValid = false;
    }

    return isValid;
}

int getMatrixSize(string filename) {
    fstream file;
    file.open(filename);

    bool isWeightedGraph = isGraphWeighted(filename);
    int matrixSize = 0;
    string line;

    if (isWeightedGraph) {
        matrixSize = (line.length() / 2);
    } else {
        matrixSize = (line.length() / 2) - 1; //comma + letters/2 - 1
    }
    
    return matrixSize;
    file.close();
}

bool isGraphWeighted(string filename) {
    fstream file;
    file.open(filename);

    char firstChar = file.peek();
    int firstCharInt = static_cast<int>(firstChar);
    
    //files start with X or 0, integer X == 88, 0 == 48
    bool isWeightedGraph = firstCharInt == 48 ? true : false;
    
    file.close();

    return isWeightedGraph;
}

void createMatrixFrom(string filename, Graph *matrix) {
    
    fstream file;
    file.open(filename);

    bool isWeightedGraph = isGraphWeighted(filename);
    int startPos;
    string line;

    if (isWeightedGraph) {
        startPos = 0;
    } else {
        startPos = 1;
        getline(file,line, '\n'); //truncate first line
    }

    //fill matrix with values
    while(getline(file, line))
    {   
        vector<int> row;
        for (int i = startPos; i < line.length(); i++) {
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
        matrix->adjMatrix.push_back(row);
    }
    file.close();
}