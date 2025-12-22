/*
ID: rjleal21
TASK: runround
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

int N;
int digits;

int digitcount(int n);
bool isunique(int n);
bool isrunaround(int n);

int main() {
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	fin >> N;
	digits = digitcount(N);

	vector<int> uniqueNums;

	for (int n = N + 1; n < pow(10, digits + 1); n++) {
		digits = digitcount(n);
		if (isunique(n) && isrunaround(n)) {
			fout << n << endl;
			return 0;
		}
	}

	return 0;
}

int digitcount(int n) {
	int count = 0;
	int nnew = n;
	while (nnew != 0) {
		count++;
		nnew /= 10;
	}
	return count;
}

bool isunique(int n) {
	int nnew = n;
	vector<int> digits;
	while (nnew != 0) {
		if ((nnew % 10 == 0) || find(digits.begin(), digits.end(), nnew % 10) != digits.end()) return false;
		digits.push_back(nnew % 10);
		nnew /= 10;
	}
	return true;
}

bool isrunaround(int n) {
	vector<int> vecdigits;
	vector<int> indices;
	indices.push_back(0);
	int nnew = n;
	while (nnew != 0) {
		vecdigits.insert(vecdigits.begin(), nnew % 10);
		nnew /= 10;
	}
	int index = 0;
	for (int i = 0; i < digits - 1; i++) {
		index += vecdigits[index];
		index %= digits;
		if (find(indices.begin(), indices.end(), index) == indices.end()) {
			indices.push_back(index);
		}
		else return false;
	}
	index += vecdigits[index];
	index %= digits;
	if (index == 0) {
		return true;
	}
	return false;
}