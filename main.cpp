/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"

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

    string line;

    // int matrixSize = 0;
    // if (isWeightedGraph) {
    //     matrixSize = (line.length() / 2);
    // } else {
    //     matrixSize = (line.length() / 2) - 1; //comma + letters/2 - 1
    // }
    // cout << matrixSize << endl;
    
    //create graph with size of matrixSize
    while(getline(file, line, '\n'))
    {   
        cout << (isWeightedGraph ? "is weighted" : "not weighted") << endl;
        int startPos = isWeightedGraph ? 0 : 1;
        for (int i = startPos; i < line.length(); i++) 
        {
            if (line[i] != ',') {
                cout << line[i] << endl;
            }
        }
        cout <<  "---end line---" << endl;
    }

    file.close();

}