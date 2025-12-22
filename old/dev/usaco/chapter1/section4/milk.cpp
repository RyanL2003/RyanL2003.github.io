/*
ID: rjleal21
TASK: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int cost = 0;
	int totalneeded;
	fin >> totalneeded;
	int N;
	fin >> N;
	vector<vector<int>> producers;
	int j;
	int k = 0;
	for (int i = 0; i < N; i++) {
		vector<int> producer;
		fin >> j;
		producer.push_back(j);
		fin >> j;
		producer.push_back(j);
		for (k = 0; k < producers.size(); k++) {
			if (producers[k][0] > producer[0]) break;
		}
		producers.insert(producers.begin() + k, producer);
	}
	while (totalneeded > 0) {
		if (totalneeded < producers[0][1]) {
			cost += producers[0][0] * totalneeded;
			totalneeded -= totalneeded;
		}
		else {
			cost += producers[0][0] * producers[0][1];
			totalneeded -= producers[0][1];
			producers.erase(producers.begin());
		}
	}
	fout << cost << endl;
	return 0;
}