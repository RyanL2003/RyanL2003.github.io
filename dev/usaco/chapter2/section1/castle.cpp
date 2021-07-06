/*
ID: rjleal21
TASK: castle
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

int M, N;
vector<int> MbyN;
//vector<vector<int>> Matrix;
vector<vector<int>> EdgeList;
vector<pair<int, int>> WallList;

void Recurse(int n, int id);

int main() {
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	fin >> M >> N;

	int temp;
	MbyN.resize(M * N, -1);
	/*Matrix.resize(M * N);
	for (int i = 0; i < M * N; i++) { 
		vector<int> matrixcol;
		matrixcol.resize(M * N, 0);
		MbyN.push_back(matrixcol); 
	}*/
	EdgeList.resize(M * N);
	for (int i = 0; i < M * N; i++) {
		int m = i % M;
		int n = i / M;
		fin >> temp;
		if (!(temp & 1)) {
			EdgeList[i].push_back((n)*M + m - 1);
		}
		if (!(temp & 2)) {
			EdgeList[i].push_back((n - 1) * M + m);
		}
		else if (n != 0) {
			pair<int, int> newpair;
			newpair.first = i;
			newpair.second = i - M;
			WallList.push_back(newpair);
		}
		if (!(temp & 4)) {
			EdgeList[i].push_back((n)*M + m + 1);
		}
		else if (m + 1 != M) {
			pair<int, int> newpair;
			newpair.first = i;
			newpair.second = i + 1;
			WallList.push_back(newpair);
		}
		if (!(temp & 8)) {
			EdgeList[i].push_back((n + 1) * M + m);
		}
	}
	int id = 1;
	for (int i = 0; i < M * N; i++) if (MbyN[i] == -1) {
		Recurse(i, id);
		id++;
	}
	fout << id - 1 << endl;
	vector<int> sizevec;
	sizevec.resize(id - 1, 0);
	for (int i = 0; i < N * M; i++) {
		sizevec[MbyN[i] - 1]++;
	}
	//vector<pair<pair<int,int>, pair<int,int>>> pairings;
	id--;
	bool condition = true;
	/*for (int i = 0; i < id; i++) 
		for (int j = i + 1; j < id; j++) {
		pair<int, int> thepairids;
		pair<int, int> thepairlengths;
		thepairids.first = i + 1;
		thepairids.second = j + 1;
		thepairlengths.first = sizevec[i];
		thepairlengths.second = sizevec[j];
		pair<pair<int, int>, pair<int, int>> finalpair;
		finalpair.first = thepairlengths;
		finalpair.second = thepairids;
		condition = true;
		for (int k = 0; k < pairings.size(); k++) {
			if (pairings[k].first.first + pairings[k].first.second < sizevec[i] + sizevec[j]) {
				condition = false;
				pairings.insert(pairings.begin() + k, finalpair);
				break;
			}
		}
		if (condition) pairings.push_back(finalpair);
	}*/
	/*for (int i = 0; i < id; i++) {
		for (int j = i + 1; j < id; j++) {
			pair<int, int> thepairids;
			pair<int, int> thepairlengths;
			thepairids.first = i + 1;
			thepairids.second = j + 1;
			thepairlengths.first = sizevec[i];
			thepairlengths.second = sizevec[j];
			pair<pair<int, int>, pair<int, int>> finalpair;
			finalpair.first = thepairlengths;
			finalpair.second = thepairids;
			pairings.push_back(finalpair);
		}
	}*/
	vector<int> sortedsize = sizevec;
	sort(sortedsize.begin(), sortedsize.end());
	fout << sortedsize[sortedsize.size() - 1] << endl;
	condition = true;
	pair<int, int> thepair;
	int count = 0;
	/*for (int i = 0; i < pairings.size(); i++) {
		count = 0;
		for (int j = 0; j < M * N; j++) {
			if (count == pairings[i].first.second) break;
			if (MbyN[j] == pairings[i].second.second) {
				count++;
				if (((j - 1 >= 0) && (((j - 1) / M) == (j / M)) && (MbyN[j - 1] == pairings[i].second.first))
					|| ((j + 1 < M * N) && (((j + 1) / M) == (j / M)) && (MbyN[j + 1] == pairings[i].second.first))
					|| ((j + M < M * N) && (MbyN[j + M] == pairings[i].second.first))
					|| ((j - M >= 0) && (MbyN[j - M] == pairings[i].second.first))) {
					condition = false;
					fout << pairings[i].first.first + pairings[i].first.second << endl;
					thepair = pairings[i].second;
					break;
				}
			}
			if (!condition) break;
		}
	}*/
	int newi;
	/*for (int i = 0; i < M * N; i++) {
		int m = i % M;
		int n = N - (i / M) - 1;
		newi = (n * M) + m;
		if (MbyN[newi] == thepair.second) {
			if ((n != 0) && (MbyN[newi - M] == thepair.first)) {
				fout << n + 1 << " " << m + 1 << " N" << endl;
				break;
			}
			if ((m + 1 != M) && (MbyN[newi + 1] == thepair.first)) {
				fout << n + 1 << " " << m + 1 << " E" << endl;
				break;
			}
		}
		if (MbyN[newi] == thepair.first) {
			if ((n != 0) && (MbyN[newi - M] == thepair.second)) {
				fout << n + 1 << " " << m + 1 << " N" << endl;
				break;
			}
			if ((m + 1 != M) && (MbyN[newi + 1] == thepair.second)) {
				fout << n + 1 << " " << m + 1 << " E" << endl;
				break;
			}
		}
	}*/
	char direction = 'N';
	for (int i = 0; i < M * N; i++) {
		int m = i / N;
		int n = N - (i % N) - 1;
		newi = (n * M) + m;
		if ((newi > M) && (MbyN[newi] != MbyN[newi - M]) && (sizevec[MbyN[newi] - 1] + sizevec[MbyN[newi - M] - 1] > count)) {
			count = sizevec[MbyN[newi] - 1] + sizevec[MbyN[newi - M] - 1];
			thepair.first = n + 1;
			thepair.second = m + 1;
			direction = 'N';
		}
		else if ((m + 1 < M) && (MbyN[newi] != MbyN[newi + 1]) && (sizevec[MbyN[newi] - 1] + sizevec[MbyN[newi + 1] - 1] > count)) {
			count = sizevec[MbyN[newi] - 1] + sizevec[MbyN[newi + 1] - 1];
			thepair.first = n + 1;
			thepair.second = m + 1;
			direction = 'E';
		}
	}
	fout << count << endl;
	fout << thepair.first << " " << thepair.second << " " << direction << endl;
	return 0;
}

void Recurse(int n, int id) {
	MbyN[n] = id;
	for (int i = 0; i < EdgeList[n].size(); i++) {
		if (MbyN[EdgeList[n][i]] == -1) 
			Recurse(EdgeList[n][i], id);
	}
}