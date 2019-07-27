/***********************************************************
Name: Diana Lozano
Assignment: 07
Purpose: This is the input output read file header.
***********************************************************/
#ifndef IOFILE_H
#define IOFILE_H

#include "graph.h"

#include <iostream>     /* cout, endl */
#include <fstream> 
// #include <iomanip>

using namespace std;

bool isValidFile(int argc, char** argv);
int getMatrixSize(string filename);
bool isGraphWeighted(string filename);
void createMatrixFrom(string filename, Graph *matrix); 

#endif /* IOFILE_H */
