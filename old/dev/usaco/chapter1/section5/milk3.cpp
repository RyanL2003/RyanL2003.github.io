/*
ID: rjleal21
TASK: milk3
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

int A, B, C;
vector<int> bounds;
//vector<tuple<int, int, int>> triples;
vector<vector<int>> triples;
vector<int> sortedints;

int main() {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	fin >> A >> B >> C;
	bounds.push_back(A);
	bounds.push_back(B);
	bounds.push_back(C);
	vector<int> firstconfig;
	firstconfig.push_back(0);
	firstconfig.push_back(0);
	firstconfig.push_back(C);
	triples.push_back(firstconfig);
	for (int i = 0; i < triples.size(); i++) {
		//tuple<int, int, int> configuration = triples[i];
		vector<int> configuration = triples[i];
		for (int j = 0; j < 3; j++) if (configuration[j] != 0) {
			for (int n = 0; n < 3; n++) if ((n != j) && (configuration[n] != bounds[n])) {
				//refilling
				vector<int> newconfig = configuration;
				if (bounds[n] - newconfig[n] < newconfig[j]) {
					newconfig[j] -= bounds[n] - newconfig[n];
					newconfig[n] = bounds[n];
				}
				else {
					newconfig[n] += newconfig[j];
					newconfig[j] = 0;
				}
				if (find(triples.begin(), triples.end(), newconfig) == triples.end()) triples.push_back(newconfig);
			}
		}
	}
	for (int i = 0; i < triples.size(); i++) if (triples[i][0] == 0) sortedints.push_back(triples[i][2]);
	sort(sortedints.begin(), sortedints.end());
	for (int i = 0; i < sortedints.size(); i++) {
		fout << sortedints[i];
		if (i != sortedints.size() - 1) fout << " ";
	}
	fout << endl;
	return 0;
}