/*
ID: rjleal21
TASK: hamming
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

int N, B, D;
int MaxValue;
vector<int> Codes;

int HammingDistance(int i, int d);

int main() {
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	fin >> N >> B >> D;
	Codes.push_back(0);
	MaxValue = 1 << B;
	bool condition = true;
	for (int i = 1; i < MaxValue; i++) {
		condition = true;
		for (int code : Codes) if (HammingDistance(i, code) < D) {
			condition = false;
			break;
		}
		if (condition) { 
			Codes.push_back(i);
			if (Codes.size() == N) break;
		}
	}
	condition = true;
	int i = 0;
	for (int n : Codes) {
		i++;
		fout << n;
		if (i % 10 == 0) {
			fout << endl;
		}
		else if (i != Codes.size()) {
			fout << " ";
		}
		if ((i == Codes.size()) && (i % 10 != 0)) { 
			fout << endl;
		}
	}
	return 0;
}

int HammingDistance(int i, int d) {
	int distance = 0;
	int XOrValue = i ^ d;
	for (int i = 1; i < MaxValue; i <<= 1) if ((i & XOrValue) != 0) {
		distance++;
	}
	return distance;
}