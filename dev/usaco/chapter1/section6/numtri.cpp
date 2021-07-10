/*
ID: rjleal21
TASK: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <tuple>

using namespace std;

int R;
vector<vector<int>> numtri;

int main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	fin >> R;
	int temp;
	for (int i = 1; i <= R; i++) {
		vector<int> row;
		for (int j = 0; j < i; j++) {
			fin >> temp;
			row.push_back(temp);
		}
		numtri.push_back(row);
	}
	for (int i = R - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			temp = (numtri[i+1][j] > numtri[i+1][j+1]) ? (numtri[i+1][j]) : (numtri[i+1][j+1]);
			numtri[i][j] += temp;
		}
	}
	fout << numtri[0][0] << endl;
	return 0;
}