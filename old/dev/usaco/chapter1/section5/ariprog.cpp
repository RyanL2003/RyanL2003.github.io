/*
ID: rjleal21
TASK: ariprog
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
int M;
int finalindex;
//vector<int> bisquares;
//vector<int> certainbisquares;
vector<int> output;
pair<int, int> all[125001];

int main() {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	fin >> N >> M;
	int maxamount = 2 * M * M;
	int maxdiff = 1 + (maxamount / (N - 1));
	/*for (int i = 0; i <= M; i++) {
		for (int j = i; j <= M; j++) {
			if (find(bisquares.begin(), bisquares.end(), (i * i) + (j * j)) == bisquares.end()) {
				bisquares.push_back((i * i) + (j * j));
			}
		}
	}*/
	int bisquaresbool[125001] = {0};
	for (int i = 0; i <= M; i++) {
		for (int j = i; j <= M; j++) {
			bisquaresbool[(i*i) + (j*j)] = 1;
		}
	}
	int bisquare;
	bool condition = true;
	//sort(bisquares.begin(), bisquares.end());
	/*finalindex = bisquares.size() - 1;
	condition = true;
	int value = 0;
	std::vector<int>::iterator temp;
	vector<int> tempbisquares;
	vector<vector<int>> tempnums;*/
	/*for (int j = 1; j < maxdiff; j++) {
		certainbisquares = bisquares;
		for (int i = 0; certainbisquares[i] + ((N - 1) * j) <= certainbisquares[certainbisquares.size() - 1]; i++) {
			condition = true;
			tempbisquares.clear();
			for (int n = 1; n < N; n++) {
				temp = find(certainbisquares.begin() + i, certainbisquares.end(), certainbisquares[i] + (n * j));
				if (temp == certainbisquares.end()) {
					condition = false;
					for (int k = 0; k < tempbisquares.size(); k++) 
						certainbisquares.erase(certainbisquares.begin() + tempbisquares[k] - k);
					break;
				}
				else {
					tempbisquares.push_back(temp - certainbisquares.begin());
				}
			}
			if (condition) {
				output.push_back(certainbisquares[i]);
				output.push_back(j);
			}
		}
	}*/
	/*for (int j = 1; j < maxdiff; j++) {
		certainbisquares.clear();
		value = 0;
		for (int i = 0; bisquares[i] + ((N - 1) * j) <= bisquares[finalindex]; i++) {
			condition = true;
			for (int n = 1; n < N; n++) if (find(bisquares.begin(), bisquares.end(), bisquares[i] + (n * j)) == bisquares.end()) { condition = false; break; }
			if (condition) {
				output.push_back(bisquares[i]);
				output.push_back(j);
				value = i;
				for (int n = 0; n < N; n++) certainbisquares.push_back(1 + bisquares[i] + (n * j));
				break;
			}
		}
		if (certainbisquares.size() > 0) while (certainbisquares[N - 1] <= bisquares[finalindex]) {
			condition = true;
			for (int n = 0; n < N; n++) if (find(bisquares.begin(), bisquares.end(), certainbisquares[n]) == bisquares.end()) { condition = false; break; }
			if (condition) { output.push_back(certainbisquares[0]); output.push_back(j); }
			value++;
			certainbisquares[0] = bisquares[value];
			for (int n = 1; n < N; n++) certainbisquares[n] = certainbisquares[0] + (n * j);
		}
	}*/
	/*for (int i = 1; i < maxdiff; i++) {
		tempbisquares.clear();
		tempnums.clear();
		for (int n = 0; n < i; n++) { 
			vector<int> tempvec;
			tempnums.push_back(tempvec);
			tempbisquares.push_back(n); 
		}
		while (tempbisquares[0] < bisquares[finalindex]) {
			for (int n = 0; n < i; n++) {
				if (find(bisquares.begin(), bisquares.end(), tempbisquares[n]) != bisquares.end()) tempnums[n].insert(tempnums[n].begin(), tempbisquares[n]);
				else tempnums[n].clear();
				if (tempnums[n].size() == N) {
					output.push_back(tempnums[n][4]);
					output.push_back(i);
					tempnums[n].erase(tempnums[n].begin() + 4);
				}
				tempbisquares[n] += i; 
			}
		}
	}*/
	int equivalentterm;
	int p;
	bool exists;
	int startint = 0;
	/*for (int b = 1; b < maxdiff; b++) {
		for (int q = 0; q < M; q++) {
			for (int x = -q; q + x < M;	x++) {
				equivalentterm = b - (x * (2*q + x));
			}
		}
	}*/
	/*for (int d = 1; d < maxdiff; d++) {
		for (int i = 0; i < maxamount + 1 - ((N - 1) * d); i++) {
			exists = true;
			for (int m = 0; m < N; m++) if (bisquaresbool[i + (m * d)] == 0) {
				exists = false;
				break;
			}
			if (exists) {
				output.push_back(i);
				output.push_back(d);
			}
		}
	}*/
	int count = 0;
	for (int d = 1; d < maxdiff; d++) {
		for (int n = 0; n < d; n++) {
			for (int i = 0; n + i < maxamount + 1 - ((N - 1) * d); i += d) {
				exists = true;
				for (int m = 0; m < N; m++) if (bisquaresbool[n + i + (m * d)] == 0) {
					exists = false;
					i += (m * d);
					break;
				}
				if (exists) {
					/*output.push_back(i+n);
					output.push_back(d);*/
					all[count] = make_pair(d, n + i);
					count++;
				}
			}
		}
	}
	/*if (output.size() > 0) {
		for (int i = 0; i < output.size(); i += 2) {
			fout << output[i] << " " << output[i + 1] << endl;
		}
	}*/
	sort(all, all + count);
	for (int i = 0; i < count; i++) {
		fout << all[i].second << " " << all[i].first << endl;
	}
	if (count == 0) fout << "NONE" << endl;
	return 0;
}