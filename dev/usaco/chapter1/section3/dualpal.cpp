/*
ID: rjleal21
TASK: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int digitplaces;
vector<int> ConvertToBase(int b, int baseten);

int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N;
	int S;
	fin >> N >> S;
	//digitplaces = (int)(log(90000) / log(base)) + 1;
	digitplaces = 20;
	vector<int> max;
	vector<char> chars{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
	vector<vector<int>> numbersinbases;
	vector<int> satisfying;
	vector<int> number;
	bool condition = true;
	int count = 0;
	while (satisfying.size() < N) {
		S++;
		count = 0;
		for (int i = 2; i < 11; i++) {
			condition = true;
			number = ConvertToBase(i, S);
			for (int i = 0; i < (number.size() / 2); i++) {
				if ((number[i]) != (number[number.size() - 1 - i])) {
					condition = false;
					break;
				}
			}
			if (condition) {
				count++;
				if (count == 2) break;
			}
		}
		if (count == 2) {
			satisfying.push_back(S);
		}
	}
	for (int i = 0; i < N; i++) {
		fout << satisfying[i] << endl;
	}
	return 0;
}

vector<int> ConvertToBase(int b, int baseten) {
	vector<int> number;
	for (int i = 0; i <= digitplaces; i++) {
		number.push_back(baseten / pow(b, digitplaces - i));
		baseten %= (int)pow(b, digitplaces - i);
	}
	while (number[0] == 0) {
		number.erase(number.begin());
	}
	return number;
}