/*
ID: rjleal21
TASK: frac1
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
vector<int> primes;
vector<pair<double, pair<int, int>>> fractions;

int main() {
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	fin >> N;
	bool condition = true;
	for (int i = 2; i < 84; i++) {
		condition = true;
		for (int j : primes) if (i % j == 0) { condition = false; break; }
		if (condition) primes.push_back(i);
	}
	{
		pair<float, pair<int, int>> trivialfrac0;
		pair<float, pair<int, int>> trivialfrac1;
		trivialfrac0.first = 0.0;
		trivialfrac1.first = 1.0;
		pair<int, int> frac0;
		frac0.first = 0;
		frac0.second = 1;
		trivialfrac0.second = frac0;
		pair<int, int> frac1;
		frac1.first = 1;
		frac1.second = 1;
		trivialfrac1.second = frac1;
		fractions.push_back(trivialfrac0);
		fractions.push_back(trivialfrac1);
	} //Instantiate trivial fractions
	pair<float, pair<int, int>> fraction;
	pair<int, int> fracrep;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			condition = true;
			for (int k : primes) if ((i % k == 0) && (j % k == 0)) { condition = false; break; }
			if (condition) {
				fraction.first = ((double)j) / ((double)i);
				fracrep.first = j;
				fracrep.second = i;
				fraction.second = fracrep;
				fractions.push_back(fraction);
			}
		}
	}
	sort(fractions.begin(), fractions.end());
	for (int i = 0; i < fractions.size(); i++) {
		fout << fractions[i].second.first << "/" << fractions[i].second.second << endl;
	}
	return 0;
}