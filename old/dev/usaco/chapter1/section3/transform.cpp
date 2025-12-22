/*
ID: rjleal21
TASK: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	int N;
	fin >> N;
	bool parity = (N % 2 == 0) ? true : false;
	vector<vector<char>> before;
	vector<vector<char>> after;
	for (int i = 0; i < N; i++) {
		string line;
		fin >> line;
		vector<char> linevector(line.begin(), line.end());
		before.push_back(linevector);
	}
	for (int i = 0; i < N; i++) {
		string line;
		fin >> line;
		vector<char> linevector(line.begin(), line.end());
		after.push_back(linevector);
	}
	bool condition = true;	
	vector<vector<char>> afterrot;
	for (int i = 0; i < N; i++) {
		vector<char> firstrow;
		for (int j = 0; j < N; j++) firstrow.push_back(after[j][N - i - 1]);
		afterrot.push_back(firstrow);
	}
	condition = true;
	for (int i = 0; i < N; i++) {
		if (before[i] != afterrot[i]) {
			condition = false;
			break;
		}
	}
	if (condition) { //270 degree
		fout << "1" << endl;
		return 0;
	}
	vector<vector<char>> beforerot;
	for (int i = 0; i < N; i++) {
		vector<char> firstrow;
		for (int j = 0; j < N; j++) firstrow.push_back(before[j][N - i - 1]);
		beforerot.push_back(firstrow);
	}
	condition = true;
	for (int i = 0; i < N; i++) {
		if (beforerot[i] != after[i]) {
			condition = false;
			break;
		}
	}
	if (condition) { //90 degree
		fout << "3" << endl;
		return 0;
	}
	condition = true;
	vector<vector<char>> beforerotrot;
	for (int i = 0; i < N; i++) {
		vector<char> firstrow;
		for (int j = 0; j < N; j++) firstrow.push_back(beforerot[j][N - i - 1]);
		beforerotrot.push_back(firstrow);
	}
	for (int i = 0; i < N; i++) {
		if (beforerotrot[i] != after[i]) {
			condition = false;
			break;
		}
	}
	if (condition) { //180 degree
		fout << "2" << endl;
		return 0;
	}
	condition = true;
	for (int i = 0; i < N; i++) {
		if (before[i] != after[i]) {
			condition = false;
			break;
		}
	}
	if (condition) { //Identical
		fout << "6" << endl;
		return 0;
	}
	condition = true;
	for (int i = 0; i < N; i++) {
		if (before[i] != after[N - i - 1]) {
			condition = false;
			break;
		}
	}
	if (condition) { //Combo -reflect and 180
		vector<vector<char>> rot1;
		vector<vector<char>> rot2;
		for (int i = 0; i < N; i++) {
			vector<char> firstrow;
			for (int j = 0; j < N; j++) firstrow.push_back(before[j][N - i - 1]);
			rot1.push_back(firstrow);
		}
		for (int i = 0; i < N; i++) {
			vector<char> firstrow;
			for (int j = 0; j < N; j++) firstrow.push_back(rot1[j][N - i - 1]);
			rot2.push_back(firstrow);
		}
		for (int i = 0; i < N; i++) {
			if (rot2[i] != after[i]) {
				condition = false;
				break;
			}
		}
		if (condition) { //180 degree
			fout << "2" << endl;
			return 0;
		}
		fout << "5" << endl;
		return 0;
	}
	condition = true;
	for (int i = 0; i < N; i++) {
		reverse(before[i].begin(), before[i].end());
		if (before[i] != after[i]) condition = false;
	}
	for (int i = 0; i < N; i++) {
		if (before[i] != after[i]) {
			condition = false;
			break;
		}
	}
	if (condition) { //Reflect only
		fout << "4" << endl;
		return 0;
	}
	beforerot.clear();
	for (int i = 0; i < N; i++) {
		vector<char> firstrow;
		for (int j = 0; j < N; j++) firstrow.push_back(before[j][N - i - 1]);
		beforerot.push_back(firstrow);
	}
	condition = true;
	for (int i = 0; i < N; i++) {
		if (beforerot[i] != after[i]) {
			condition = false;
			break;
		}
	}
	if (condition) { //Combo -reflect and 90
		fout << "5" << endl;
		return 0;
	}
	condition = true;
	for (int i = 0; i < N; i++) {
		if (before[i] != afterrot[i]) {
			condition = false;
			break;
		}
	}
	if (condition) { //Combo -reflect and 270
		fout << "5" << endl;
		return 0;
	}

	fout << "7" << endl; //invalid
	return 0;
}