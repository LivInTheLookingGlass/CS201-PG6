#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Header.h"

using namespace std;


int main()	{
	string file;
	file = getInput();
	int size = getFileSize(file);
	int recNum = getRecordCount(file);
	int recSize = (size - 4) / recNum;
	sort(file, recNum, recSize);
	return 0;
}

string getInput()	{
	cout << "What file would you like to analyze?" << endl;
	string file;
	getline(cin, file);
	return file;
}

int getFileSize(string file)	{
	fstream fst(file, ios::in | ios::binary | ios::out);
	int beg = fst.tellg();
	fst.seekg(ios::end);
	int x = fst.tellg();
	fst.close();
	return x-beg;
}

int getRecordCount(string file)	{
	fstream fst(file, ios::in | ios::binary | ios::out);
	fst.seekp(ios::beg);
	string y = "    ";
	for (int c = 0; c < 4; c++) fst.get(y[c]);
	int x = atoi(y.c_str());
	fst.close();
	return x;
}

void sort(string file, int recNum, int recSize)	{
	fstream fsta(file, ios::in | ios::binary | ios::out);
	fstream fstb(file, ios::in | ios::binary | ios::out);
	int d = recNum;
	while (d < 1)	{
		d = (d == 2) ? 1 : (d % 2 == 1) ? (d + 1) / 2 : (d % 4 == 0) ? d / 2 + 1 : d / 2 + 2;
		for (int i = d; i < recNum; i++)	{
			for (int j = i - d; j >= 0; j -= d)	{
				fsta.seekg(ios::beg + 4 + i*recSize);
				fstb.seekg(ios::beg + 4 + j*recSize);
				string a, b;
				for (int c = 0; c < recSize; c++)	{
					a.append(" ");
					b.append(" ");
					fsta.get(a[c]);
					fstb.get(b[c]);
				}
				if (a > b)	{
					fsta.seekp(ios::beg + 4 + i*recSize);
					fstb.seekp(ios::beg + 4 + j*recSize);
					for (int c = 0; c < recSize; c++) fsta.put(b[c]);
					for (int c = 0; c < recSize; c++) fstb.put(a[c]);

				}
			}
		}
	}
	fsta.close();
	fstb.close();
}
