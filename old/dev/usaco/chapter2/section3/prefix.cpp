/*
ID: rjleal21
TASK: prefix
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

string S;
vector<string> primitives;
vector<int> lengths;
vector<vector<string>> sortedprimitives;
vector<bool> ifhit;
int pcount = 0;

int prefixlength;

void recurse(int index);
bool recursemodified(int index, int length, string s, vector<string> primitivesmodified);

int main() {
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	
	string temp;
	while ((fin >> temp) && (temp != ".")) {
		primitives.push_back(temp);
		lengths.push_back(temp.length());
		pcount++;
	}
	while (fin >> temp) {
		S.append(temp);
	}

	ifhit.resize(S.size(), false);

	if (S.size() > 100000) {
		vector<string> primitivesmodified;
		sortedprimitives.resize(10);
		for (int i = 0; i < primitives.size(); i++) {
			sortedprimitives[lengths[i] - 1].push_back(primitives[i]);
		}
		primitivesmodified.insert(primitivesmodified.end(), sortedprimitives[0].begin(), sortedprimitives[0].end());
		for (int i = 1; i < 10; i++) {
			for (int k = 0; k < sortedprimitives[i].size(); k++) {
				if (recursemodified(0, i+1, sortedprimitives[i][k], primitivesmodified)) {
					primitives.erase(find( primitives.begin(), primitives.end(), sortedprimitives[i][k]));
				}
			}
			primitivesmodified.insert(primitivesmodified.end(), sortedprimitives[i].begin(), sortedprimitives[i].end());
		}
		lengths.clear();
		for (int i = 0; i < primitives.size(); i++) {
			lengths.push_back(primitives[i].length());
		}
		pcount = primitives.size();
	}

	recurse(0);
	fout << prefixlength << endl;

	return 0;
}

void recurse(int index) {
	ifhit[index] = true;
	bool isend = true;
	vector<int> possprims;
	possprims.push_back(-1);
	do {
		isend = true;
		if (possprims[0] != -1) index += lengths[possprims[0]];
		possprims.clear();
		ifhit[index] = true;
		for (int i = 0; i < pcount; i++) {
			if (primitives[i] == S.substr(index, lengths[i])) {
				isend = false;
				possprims.push_back(i);
			}
		}
	} while ((possprims.size() == 1) && !(ifhit[index + lengths[possprims[0]]]));
	for (int prim : possprims) {
		if (!ifhit[index + lengths[prim]]) recurse(index + lengths[prim]);
	}
	if (isend) { 
		if (prefixlength < index) prefixlength = index; 
	}

	return;
}

bool recursemodified(int index, int length, string s, vector<string> primitivesmodified) {
	if (index == length) {
		return true;
	}
	for (int i = 0; i < primitivesmodified.size(); i++) {
		if (primitivesmodified[i] == s.substr(index, primitivesmodified[i].length())) {
			if (recursemodified(index + primitivesmodified[i].length(), length, s, primitivesmodified)) return true;
		}
	}

	return false;
}