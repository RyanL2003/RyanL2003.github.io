/*
ID: rjleal21
TASK: nocows
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

using namespace std;

int N, K;

int total = 0;
int highestmember = 1;
vector<vector<pair<int,int>>> bysizes; //possible trees sorted by (size-1) and are of form (#of leaves, #of ones of this kind)
vector<int> counts;
vector<vector<int>> pascalstree;
int satisfyingleaves = 0;


int choose(int n, int k);
bool isSatisfying(pair<int, int> thepair);

int main() {
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	
	fin >> N >> K;
	pascalstree.resize(100);
	pascalstree[0].push_back(1);
	for (int i = 1; i < 100; i++) {
		pascalstree[i].push_back(1);
		for (int j = 1; j < i; j++) {
			pascalstree[i].push_back((pascalstree[i-1][j-1] + pascalstree[i-1][j]) % 9901);
		}
		pascalstree[i].push_back(1);
	}

	bysizes.resize(201);
	counts.resize(201,0);
	bysizes[0].push_back(make_pair(1, 1));
	
	for (int h = 1; h < K; h++) {
		for (int n = highestmember - 1; n >=0; n--) { //counts
			while (bysizes[n].size() != 0) {
				pair<int, int> currentpair = bysizes[n][0];
				for (int l = 1; l <= currentpair.first; l++) {
					int newsize = n + (2 * l);
					if ((newsize > highestmember) && (newsize <= N)) highestmember = newsize+1;
					if ((newsize <= N) && ((newsize + (2 * (K - h - 1))) <= N)) {
						satisfyingleaves = 2 * l;
						vector<pair<int,int>>::iterator location = find_if(bysizes[newsize].begin(), bysizes[newsize].end(), isSatisfying);
						if (location != bysizes[newsize].end()) {
							(*location).second += ((choose(currentpair.first, l) % 9901) * currentpair.second) % 9901;
						}
						else {
							bysizes[newsize].push_back(make_pair(satisfyingleaves, ((choose(currentpair.first, l) % 9901) * currentpair.second) % 9901));
						}
					}
				}
				bysizes[n].erase(bysizes[n].begin());
			}
		}
	}

	for (pair<int,int> currentpair : bysizes[N-1]) {
		total += (currentpair.second % 9901);
	}

	fout << (total % 9901) << endl;

	return 0;
}

int choose(int n, int k) {
	return pascalstree[n][k];
}

bool isSatisfying(pair<int,int> thepair) {
	return (thepair.first == satisfyingleaves) ? (true) : (false);
}