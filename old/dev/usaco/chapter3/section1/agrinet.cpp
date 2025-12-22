/*
ID: rjleal21
TASK: agrinet
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
#include <iomanip>

using namespace std;

#define INF 214748364
#define PTS 100

int N;
int dists[PTS][PTS];
int shortest[PTS];
bool inside[PTS];

int main() {
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");

	int i, j, k, treesize = 0, tempshortest, cost = 0;

	fin >> N;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			fin >> dists[i][j];
		}
		shortest[i] = INF;
		inside[i] = false;
	}
	shortest[0] = 0;
	inside[0] = true;
	treesize++;
	while (treesize < N) {
		tempshortest = INF;
		for (i = 0; i < N; i++) if (!inside[i]) {
			for (j = 0; j < N; j++) if (inside[j] && (dists[j][i] < shortest[i])) shortest[i] = dists[j][i];
			if (tempshortest > shortest[i]) { tempshortest = shortest[i]; k = i; }
		}

		cost += tempshortest;
		inside[k] = true;
		treesize++;
	}

	fout << cost << endl;

	return 0;
}