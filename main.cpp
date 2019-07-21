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
    
    char firstChar = file.get();
    int firstCharInt = static_cast<int>(firstChar);
    //TODO -- first char X == 88, x == 120, 0 == 48
    cout << (firstCharInt == 48 ? "weighted graph" : "unweighted graph" ) << endl;

    string line;
    getline(file, line, '\n');

    int matrixSize = (line.length() / 2) - 1; //comma + letters/2 - 1
    cout << line << " length: " << matrixSize << endl;
    
    //create graph with size of matrixSize

    while(getline(file, line, '\n'))
    {
        for (int i = 2; i < line.length(); i++) 
        {
            if (line[i] != ',') {
                cout << line[i] << endl;
            }
        }
        cout <<  "---end line---" << endl;
    }

    file.close();

}