/*
ID: rjleal21
TASK: sort3
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
vector<int> inputsequence;
int ones = 0;
int twos = 0;
int threes = 0;
int twosinone = 0;
int threesinone = 0;
int onesintwo = 0;
int threesintwo = 0;
int onesinthree = 0;
int twosinthree = 0;
int swaps = 0;

int main() {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	fin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		fin >> temp;
		if (temp == 1) {
			ones++;
		}
		else if (temp == 2) {
			twos++;
		}
		else {
			threes++;
		}
		inputsequence.push_back(temp);
	}
	for (int i = 0; i < ones; i++) {
		if (inputsequence[i] == 2) {
			twosinone++;
		}
		if (inputsequence[i] == 3) {
			threesinone++;
		}
	}
	for (int i = ones; i < ones + twos; i++) {
		if (inputsequence[i] == 1) {
			onesintwo++;
		}
		if (inputsequence[i] == 3) {
			threesintwo++;
		}
	}
	for (int i = ones + twos; i < N; i++) {
		if (inputsequence[i] == 1) {
			onesinthree++;
		}
		if (inputsequence[i] == 2) {
			twosinthree++;
		}
	}
	if (twosinone < onesintwo) {
		swaps += twosinone;
		onesintwo -= twosinone;
		twosinone -= twosinone;
	}
	else {
		swaps += onesintwo;
		twosinone -= onesintwo;
		onesintwo -= onesintwo;
	}
	if (threesintwo < twosinthree) {
		swaps += threesintwo;
		twosinthree -= threesintwo;
		threesintwo -= threesintwo;
	}
	else {
		swaps += twosinthree;
		threesintwo -= twosinthree;
		twosinthree -= twosinthree;
	}
	if (threesinone < onesinthree) {
		swaps += threesinone;
		onesinthree -= threesinone;
		threesinone -= threesinone;
	}
	else {
		swaps += onesinthree;
		threesinone -= onesinthree;
		onesinthree -= onesinthree;
	}
	swaps += (twosinone * 2) + (onesintwo * 2);
	fout << swaps << endl;
	return 0;
}