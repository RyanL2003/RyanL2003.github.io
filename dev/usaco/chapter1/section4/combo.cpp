/*
ID: rjleal21
TASK: combo
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

vector<int> combo1;
vector<int> combo2;

vector<vector<int>> numbers;

int N;

bool Satisfy1(int n, int i);
bool Satisfy2(int n, int i);

int main() {
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	fin >> N;
	int temp;
	for (int i = 0; i < 3; i++) {
		fin >> temp;
		combo1.push_back(temp);
	}
	for (int i = 0; i < 3; i++) {
		fin >> temp;
		combo2.push_back(temp);
	}
	int count = 0;
	bool key1;
	bool key2;
	bool prev1;
	bool prev2;
	bool add1;
	bool add2;
	for (int i = 1; i <= N; i++) {
		key1 = Satisfy1(i, 0); 
		prev1 = Satisfy1(i, 0); 
		add1 = Satisfy1(i, 0);
		key2 = Satisfy2(i, 0);
		prev2 = Satisfy2(i, 0);
		add2 = Satisfy2(i, 0);
		if (key1 || key2) for (int j = 1; j <= N; j++) {
			prev1 = (key1) ? Satisfy1(j, 1) : false;
			add1 = (key1) ? Satisfy1(j, 1) : false;
			prev2 = (key2) ? Satisfy2(j, 1) : false;
			add2 = (key2) ? Satisfy2(j, 1) : false;
			if (prev1 || prev2) for (int k = 1; k <= N; k++) {
				add1 = (prev1) ? Satisfy1(k, 2) : false;
				add2 = (prev2) ? Satisfy2(k, 2) : false;
				if (add1 || add2) {
					count++;
					vector<int> thecombo{i,j,k};
					numbers.push_back(thecombo);
				}
			}
		}
	}
	fout << count << endl;
	return 0;
}

bool Satisfy1(int n, int i) {
	if ((abs(n - N - combo1[i]) < 3) || (abs(n-combo1[i]) < 3) || (abs(n + N - combo1[i]) < 3)) return true;
	return false;
}

bool Satisfy2(int n, int i) {
	if ((abs(n - N - combo2[i]) < 3) || (abs(n-combo2[i]) < 3) || (abs(n + N - combo2[i]) < 3)) return true;
	return false;
}