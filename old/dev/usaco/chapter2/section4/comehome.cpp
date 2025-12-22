/*
ID: rjleal21
TASK: comehome
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

#define INF 214748364;
#define PTS 53

int P;
int edges[PTS][PTS];

int shortestdists[PTS];
int parent[PTS];
bool visited[PTS];

int main() {
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	int i, j, k;

	fin >> P;

	for (i = 0; i < PTS; i++)
	for (j = 0; j < PTS; j++) {
		edges[i][j] = INF;
	}
	string temp;
	int a, b, d;
	char ac, bc;
	int line = 0;
	while (fin >> ac >> bc >> d) {
		line++;
		a = ac - 'A';
		b = bc - 'A';
		if (a > 25) a -= 6;
		if (b > 25) b -= 6;
		if (edges[a][b] > d) {
			edges[a][b] = d;
			edges[b][a] = d;
		}
	}

	//Floyd-Warshaw (mistake)
	//for (k = 0; k < PTS; k++)
	//for (i = 0; i < PTS; i++)
	//for (j = 0; j < PTS; j++) {
	//	if (dist[i][j] > dist[i][k] + dist[k][j])
	//		dist[i][j] = dist[i][k] + dist[k][j];
	//}

	for (i = 0; i < PTS; i++) shortestdists[i] = edges[25][i];
	shortestdists[25] = 0;
	int nodenum = 0;
	int tempdist = INF;
	while (nodenum < PTS) {
		tempdist = INF;
		for (i = 0; i < PTS; i++) if ((tempdist > shortestdists[i]) && (!visited[i])) { j = i; tempdist = shortestdists[i]; }

		visited[j] = true;
		nodenum++;

		for (k = 0; k < PTS; k++) if (shortestdists[j] + edges[j][k] < shortestdists[k]) { shortestdists[k] = shortestdists[j] + edges[j][k]; parent[k] = j; }
	}

	int shortestdist = INF;
	int shortestindex = 0;
	for (i = 0; i < 25; i++)
		if (shortestdist > shortestdists[i])
		{
			shortestdist = shortestdists[i];
			shortestindex = i;
		}

	fout << ((shortestindex < 25) ? (char)('A' + shortestindex) : (char)('a' + shortestindex)) << " " << shortestdist << endl;

	return 0;
}