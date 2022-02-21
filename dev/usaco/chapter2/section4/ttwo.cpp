/*
ID: rjleal21
TASK: ttwo
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

const int GSIZE = 12;
int N, C = 0;
pair<int, int> cowinit;
pair<int, int> farminit;
pair<int, int> cowpos;
pair<int, int> farmpos;
int d1 = 0, d2 = 0;

int grid[GSIZE][GSIZE];
int ltcow[4][GSIZE][GSIZE];
int ltfarm[4][GSIZE][GSIZE];
bool hcow[4][GSIZE][GSIZE];
bool hfarm[4][GSIZE][GSIZE];

void move(pair<int, int>& loc, int& dir);

int main() {
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");

	for (int i = 0; i < GSIZE; i++)
		for (int j = 0; j < GSIZE; j++) {
			grid[i][j] = 1; 
			for (int k = 0; k < 4; k++){
				hcow[k][i][j] = false;
				hfarm[k][i][j] = false;
			}
		}
	string temp;
	for (int i = 1; i <= 10; i++) {
		fin >> temp;
		for (int j = 1; j <= 10; j++) {
			if ((temp[j-1] != 'F') && (temp[j-1] != 'C')) {
				grid[j][i] = (temp[j-1] == '*') ? (1) : (0);
			}
			else if (temp[j-1] == 'F') {
				farmpos = make_pair(j,i);
				farminit = make_pair(j, i);
				grid[j][i] = (temp[j - 1] == '*') ? (1) : (0);
			}
			else {
				cowpos = make_pair(j,i);
				cowinit = make_pair(j, i);
				grid[j][i] = (temp[j - 1] == '*') ? (1) : (0);
			}
		}
	}

	int time = 0;
	int met = 0;
	while (met == 0) {
		time++;
		move(cowpos, d1);
		move(farmpos, d2);
		if (cowpos == farmpos) met = 1;
		else if (
			(hcow[d1][cowpos.first][cowpos.second] == true) && (hfarm[d2][farmpos.first][farmpos.second] == true)/* &&
			(ltcow[d1][cowpos.first][cowpos.second] == ltfarm[d2][farmpos.first][farmpos.second])*/) {
			bool isrecursed = true;
			for (int i = 1; i <= 10; i++) {
				for (int j = 1; j <= 10; j++) {
					if ((hcow[0][i][j]) || (hcow[1][i][j]) || (hcow[2][i][j]) || (hcow[3][i][j])) {
						if ((hfarm[0][i][j]) || (hfarm[1][i][j]) || (hfarm[2][i][j]) || (hfarm[3][i][j])) {
							isrecursed = false;
							break;
						}
					}
				}
				if (!isrecursed) break;
			}
			if (isrecursed) {
				time = 0; met = 1;
			}
			else if ((ltcow[d1][cowpos.first][cowpos.second] == ltfarm[d2][farmpos.first][farmpos.second])) {
				time = 0; met = 1;
			}
		}
		ltcow[d1][cowpos.first][cowpos.second] = time;
		ltfarm[d2][farmpos.first][farmpos.second] = time;
		hcow[d1][cowpos.first][cowpos.second] = true;
		hfarm[d2][farmpos.first][farmpos.second] = true;
	}

	fout << time << endl;

	return 0;
}

void move(pair<int,int>& loc, int& dir) {
	switch (dir) {
	case 0:
		if (grid[loc.first][loc.second - 1] == 1) dir = (dir + 1) % 4;
		else loc.second--;
		break;
	case 1:
		if (grid[loc.first + 1][loc.second] == 1) dir = (dir + 1) % 4;
		else loc.first++;
		break;
	case 2:
		if (grid[loc.first][loc.second + 1] == 1) dir = (dir + 1) % 4;
		else loc.second++;
		break;
	case 3:
		if (grid[loc.first - 1][loc.second] == 1) dir = (dir + 1) % 4;
		else loc.first--;
		break;
	}
}