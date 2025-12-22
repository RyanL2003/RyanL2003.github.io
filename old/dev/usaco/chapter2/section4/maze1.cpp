/*
ID: rjleal21
TASK: maze1
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

int W, H;

char maze[78][202];
int paths[40][102];

pair<int, int> init1, init2;
int d1 = -1, d2 = -1;

void addexit(pair<int, int> loc, int d); 
void iterate(pair<int, int> loc, int d, int l);

int main() {
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");

	fin >> W >> H;

	fin.ignore();
	string temp;
	for (int j = 0; j < 1 + (2 * H); j++) {
		getline(fin, temp);
		for (int i = 0; i < 1 + (2*W); i++) {
			maze[i + 1][j + 1] = temp[i];
		}
	}
	for (int i = 0; i < 39; i++) {
		maze[i][0] = ' ';
		for (int j = 0; j < 101; j++) {
			paths[i][j] = 10000;
		}
	}
	for (int i = 1; i <= 2 * W; i++) {
		if (maze[i][1] == ' ')
			addexit(make_pair(i/2,1), 0);
		if (maze[i][2*H + 1] == ' ')
			addexit(make_pair(i/2,H), 2);
	}
	for (int i = 1; i <= 2 * H; i++) {
		if (maze[1][i] == ' ')
			addexit(make_pair(1, i/2), 3);
		if (maze[2*W + 1][i] == ' ')
			addexit(make_pair(W, i/2), 1);
	}

	paths[init2.first][init2.second] = 1;
	iterate(init1, d1, 1);
	paths[init2.first][init2.second] = 100000;
	iterate(init2, d2, 1);

	int max = 0;
	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= H; j++) {
			if (paths[i][j] > max) max = paths[i][j];
		}
	}

	fout << max << endl;

	return 0;
}

void addexit(pair<int,int> loc, int d) {
	if (d1 == -1) {
		init1 = loc;
		d1 = d;
	}
	else {
		init2 = loc;
		d2 = d;
	}
}

void iterate(pair<int,int> loc, int d, int l) {
	if (paths[loc.first][loc.second] > l) paths[loc.first][loc.second] = l;
	else 
		return;
	switch (d) {
	case 0:
		if (maze[loc.first * 2 + 1][loc.second * 2] == ' ') 
			iterate(make_pair(loc.first + 1, loc.second), 3, l + 1);
		if (maze[loc.first * 2][loc.second * 2 + 1] == ' ') 
			iterate(make_pair(loc.first, loc.second + 1), 0, l + 1);
		if (maze[loc.first * 2 - 1][loc.second * 2] == ' ') 
			iterate(make_pair(loc.first - 1, loc.second), 1, l + 1);
		break;
	case 1:
		if (maze[loc.first * 2][loc.second * 2 + 1] == ' ') 
			iterate(make_pair(loc.first, loc.second + 1), 0, l + 1);
		if (maze[loc.first * 2 - 1][loc.second * 2] == ' ') 
			iterate(make_pair(loc.first - 1, loc.second), 1, l + 1);
		if (maze[loc.first * 2][loc.second * 2 - 1] == ' ') 
			iterate(make_pair(loc.first, loc.second - 1), 2, l + 1);
		break;
	case 2:
		if (maze[loc.first * 2 - 1][loc.second * 2] == ' ') 
			iterate(make_pair(loc.first - 1, loc.second), 1, l + 1);
		if (maze[loc.first * 2][loc.second * 2 - 1] == ' ') 
			iterate(make_pair(loc.first, loc.second - 1), 2, l + 1);
		if (maze[loc.first * 2 + 1][loc.second * 2] == ' ') 
			iterate(make_pair(loc.first + 1, loc.second), 3, l + 1);
		break;
	case 3:
		if (maze[loc.first * 2][loc.second * 2 - 1] == ' ') 
			iterate(make_pair(loc.first, loc.second - 1), 2, l + 1);
		if (maze[loc.first * 2 + 1][loc.second * 2] == ' ') 
			iterate(make_pair(loc.first + 1, loc.second), 3, l + 1);
		if (maze[loc.first * 2][loc.second * 2 + 1] == ' ') 
			iterate(make_pair(loc.first, loc.second + 1), 0, l + 1);
		break;
	}
}