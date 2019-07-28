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

using namespace std;

bool IsValidFile(int argc, char** argv);
int GetMatrixSize(string filename);
bool isGraphWeighted(string filename);
void CreateMatrixFrom(string filename, Graph *matrix); 

#endif /* IOFILE_H */
