/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"
#include "graph.h"

int main(int argc, char** argv) {

    int argCount = argc - 1; //1st argument doesn't count (executable file)
    bool hasParam = argCount >= 1;
    fstream file;
    string csvline;
    string data;
    string strId;

    if (!hasParam) 
        return 0;

    string fileName = argv[1];
    cout << fileName << " FILENAME" << endl;
    file.open(fileName);

    if (!file) {
        cout << fileName << " could not be opened.\n";
        return 0;
    }
    
    char firstChar = file.peek();
    int firstCharInt = static_cast<int>(firstChar);
    
    //TODO -- first char X == 88, x == 120, 0 == 48?
    bool isWeightedGraph = firstCharInt == 48 ? true : false;
    int matrixSize = 0;
    string line;

    if (isWeightedGraph) {
        matrixSize = (line.length() / 2);
    } else {
        getline(file,line, '\n'); //truncate first line
        matrixSize = (line.length() / 2) - 1; //comma + letters/2 - 1
    }
    
    //create graph with size of matrixSize
    Graph myGraph = Graph(matrixSize);

    //fill myGraph with values
    int startPos = isWeightedGraph ? 0 : 1;
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
                // cout << "ch: " << line[i] << " int: " << num << endl;
                // Create a vector to represent a row, and add it to the adjList.
                row.push_back(num); //convert to int
            }

        }
        myGraph.adjMatrix.push_back(row);
            
    }
    file.close();
    myGraph.showMatrix();
}