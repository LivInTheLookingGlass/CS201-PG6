#ifndef _head_
#define _head_
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main();
string getInput();
int getFileSize(string file);
int getRecordCount(string file);
void sort(string file, int recNum, int recSize);

#endif
