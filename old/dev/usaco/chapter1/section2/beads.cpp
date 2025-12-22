/*
ID: rjleal21
TASK: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int N;
	fin >> N;
	//const char* beads;
	string beads;
	fin >> beads;
	vector<int> potentialbreaks;
	for (int i = 0; i < N; i++) {
		if (beads[i % N] != beads[(i+1) % N]) {
			potentialbreaks.push_back(i);
		}
	}
	char left, right;
	int distance = 2;
	int max = 2;
	int index;
	bool existBlue = false, existRed = false;
	for (int i = 0; i < N; i++) {
		if (beads[i] == 'b') existBlue = true;
		if (beads[i] == 'r') existRed = true;
	}
	if ((existBlue && existRed) == false) {
		fout << N << endl;
	} 
	else {
		int lowlimit = 0;
		for (int i = 0; i < potentialbreaks.size(); i++) {
			index = potentialbreaks[i];
			distance = 2;
			left = beads[index];
			right = beads[(index + 1) % N];
			if (beads[index] == 'w') {
				left = (beads[(index + 1) % N] == 'b') ? 'r' : 'b';
			}
			else if (beads[(index + 1) % N] == 'w') {
				right = (beads[index] == 'b') ? 'r' : 'b';
			}
			int k = 1;
			while ((beads[(index - k + N) % N]) != right) {
				distance += 1;
				k += 1;
			}
			lowlimit = (index + 1 - k + N) % N;
			k = 1;
			while (((beads[(index + 1 + k) % N]) != left) && (((index + 1 + k) % N) != lowlimit)) {
				distance += 1;
				k += 1;
			}
			if (distance > max) {
				max = distance;
			}
		}
		fout << max << endl;
	}
}