/*
ID: rjleal21
TASK: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int N;
vector<int> hills;
vector<int> lowest;
vector<int> greatest;
int leastcost;

int Cost(int i, int n);

int main() {
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	fin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		fin >> temp;
		hills.push_back(temp);
	}
	lowest = hills;
	sort(lowest.begin(), lowest.end());
	greatest = lowest;
	reverse(greatest.begin(), greatest.end());
	leastcost = 1000000000;
	int acccost = 0;
	for (int i = 0; i < 100; i++) {
		acccost = 0;
		for (int n = 0; n < N; n++) acccost += Cost(i, hills[n]);
		if (acccost < leastcost) leastcost = acccost;
	}
	fout << leastcost << endl;
	return 0;
}

int Cost(int i, int n) {
	if ((i-n < 9) && (n-i < 10)) return 0;
	else {
		if ((i-n) >= 9) {
			return (i - n - 8) * (i - n - 8);
		}
		else {
			return (n - i - 9) * (n - i - 9);
		}
	}
}