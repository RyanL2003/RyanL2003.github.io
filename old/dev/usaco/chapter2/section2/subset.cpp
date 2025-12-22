/*
ID: rjleal21
TASK: subset
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

int MAX;
int N;

//void Recurse(int min, int max, int left, int depth);
//int FindSum(int size);

int TOTAL = 0;

int main() {
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	fin >> N;

	MAX = N * (N + 1) / 2;
	vector<unsigned int> counts;
	vector<unsigned int> countsnew;
	counts.resize(MAX + 1, 0);
	counts[0] = 1;
	countsnew.resize(MAX + 1, 0);
	countsnew[0] = 1;

	if (N * (N+1) % 4 != 0) { fout << 0 << endl; return 0; }

	for (int i = 1; i <= N; i++) {
		for (int j = 0; counts[j] != 0; j++) {
			countsnew[j + i] += counts[j];
		}
		counts = countsnew;
	}

	fout << counts[MAX / 2] / 2 << endl;

	//partsum = (N * (N + 1)) / 4;
	//if ((N * (N + 1)) % 4 != 0) {
	//	fout << 0 << endl;
	//	return 0;
	//}
	//int mincount = 0;
	//int maxcount;
	//int tempval = 0;
	//for (int n = N; tempval < partsum; n--) { // might be a <=
	//	mincount += 1;
	//	tempval += n;
	//}
	//maxcount = N - mincount;

	//for (int i = mincount; i <= maxcount; i++) {
	//	int currentamount = 0;
	//	int tempsum = FindSum(i);

	//	if (tempsum == partsum) TOTAL++;
	//	else if (tempsum > partsum) Recurse(1, i, tempsum - partsum, N - i);
	//}

	//fout << TOTAL / 2 << endl;

	return 0;
}

//void Recurse(int min, int max, int left, int depth) { 
//	//min is size of last block, max is max block size rn, left is remaining count
//	for (int i = min; (left - i >= 0) && (i <= max); i++) {
//		if (left - i == 0) { TOTAL++; return; }
//		else if ((depth != 1) && (left - i > 0)) {
//			Recurse(i, max, left - i, depth - 1);
//		}
//	}
//	return;
//}
//
//int FindSum(int size) {
//	int tempN = N;
//	int sum = 0;
//	for (int i = 0; i < size; i++) {
//		sum += tempN;
//		tempN--;
//	}
//	return sum;
//}