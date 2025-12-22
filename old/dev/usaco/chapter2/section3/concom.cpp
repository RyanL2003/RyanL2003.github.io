/*
ID: rjleal21
TASK: concom
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
#include <bitset>

using namespace std;

int N, C = 0;
const int MCOM = 101;

int ownspercents[MCOM][MCOM]; //percents from 0->100% that i owns j
int controls[MCOM][MCOM]; //either 1s or 0s if i controls j

void addcontroller(int i, int j);
void addowner(int i, int j, int p);

int main() {
	ifstream fin("concom.in");
	ofstream fout("concom.out");

	fin >> N;

	for (int i = 1; i < MCOM; i++) controls[i][i] = 1;

	int I, J, P;
	while (fin >> I >> J >> P) {
		addowner(I, J, P);
	}

	for (int i = 1; i < MCOM; i++) {
		for (int j = 1; j < MCOM; j++) {
			if ((i != j) && (controls[i][j] == 1)) {
				fout << i << " " << j << endl;
			}
		}
	}

	return 0;
}

void addcontroller(int i, int j) {
	if (controls[i][j] == 1) return;
	int k;
	controls[i][j] = 1;
	for (k = 1; k < MCOM; k++) {
		ownspercents[i][k] += ownspercents[j][k];
	}
	for (k = 1; k < MCOM; k++) {
		if (controls[k][i]) addcontroller(k,j);
	}
	for (k = 1; k < MCOM; k++) {
		if (ownspercents[i][k] > 50) addcontroller(i,k);
	}
	return;
}

void addowner(int i, int j, int p) {
	int k;

	for (k = 1; k < MCOM; k++) {
		if (controls[k][i] == 1) ownspercents[k][j] += p;
	}
	for (k = 1; k < MCOM; k++) {
		if (ownspercents[k][j] > 50) addcontroller(k,j);
	}
	return;
}