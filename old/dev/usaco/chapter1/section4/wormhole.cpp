/*
ID: rjleal21
TASK: wormhole
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
int thecount = 0;
vector<int> testing;

struct coord {
	int x;
	int y;
};

struct apair {
	int i1;
	int i2;
};

struct row {
	int ycoord;
	vector<int> xs;
	vector<int> ids;
};

vector<coord> wormholes;
vector<row> rows;
vector<int> endofrowids;
vector<int> nextone;
vector<vector<apair>> allperms;

void Check(vector<apair> permutation);
bool IsInPair(apair pair1, int i);
int PairComplement(vector<apair> permutation, int i); 
void Recurse(vector<int> variables, vector<apair> pairs); 
bool IsPairEquiv(apair pair1, apair pair2);
bool IsPairIn(vector<apair> perm, apair thepair);
bool IsUnique(vector<apair> perm);

int main() {
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	fin >> N;
	int x, y;
	bool condition = true;
	bool condition2 = true;
	for (int i = 0; i < N; i++) {
		condition = true;
		fin >> x;
		fin >> y;
		coord newcoord;
		newcoord.x = x;
		newcoord.y = y;
		wormholes.push_back(newcoord);
		for (int j = 0; j < rows.size(); j++) if (rows[j].ycoord == y) { 
			condition = false;
			condition2 = true;
			for (int k = 0; k < rows[j].xs.size(); k++) if (rows[j].xs[k] > x) {
				condition2 = false;
				rows[j].xs.insert(rows[j].xs.begin() + k, x);
				rows[j].ids.insert(rows[j].ids.begin() + k, i);
				break;
			}
			if (condition2) {
				rows[j].xs.push_back(x);
				rows[j].ids.push_back(i);
			}
			break; 
		}
		if (condition) {
			row newrow;
			newrow.ycoord = y;
			newrow.xs.push_back(x);
			newrow.ids.push_back(i);
			rows.push_back(newrow);
		}
	}
	for (int i = 0; i < rows.size(); i++) {
		endofrowids.push_back(rows[i].ids[rows[i].ids.size() - 1]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < rows.size(); j++) {
			for (int k = 0; k < rows[j].ids.size(); k++) 
				if (rows[j].ids[k] == i) 
					if (k != rows[j].ids.size() - 1) nextone.push_back(rows[j].ids[k + 1]); else nextone.push_back(0);
		}
	}
	thecount = 0;
	vector<int> inputvars;
	for (int i = 0; i < N; i++) inputvars.push_back(i);
	vector<apair> outputpairs;
	Recurse(inputvars, outputpairs);
	fout << thecount << endl;
	return 0;
}

void Recurse(vector<int> variables, vector<apair> pairs) {
	if (variables.size() > 2) {
		vector<int> newsetvariables;
		vector<apair> newpairs;
		//for (int i = 0; i < variables.size() - 1; i++) {
		int i = 0;
		//for (int i = 0; i < 2; i++) 
		{
			for (int j = i + 1; j < variables.size(); j++) {
				newsetvariables = variables;
				newsetvariables.erase(newsetvariables.begin() + j);
				newsetvariables.erase(newsetvariables.begin() + i);
				newpairs = pairs;
				apair newpair;
				newpair.i1 = variables[i];
				newpair.i2 = variables[j];
				newpairs.push_back(newpair);
				Recurse(newsetvariables, newpairs);
			}
		}
	}
	else {
		apair newpair;
		newpair.i1 = variables[0];
		newpair.i2 = variables[1];
		pairs.push_back(newpair);
		Check(pairs);
	}
}

void Check(vector<apair> permutation) {
	bool condition;
	bool condition2;
	//if (IsUnique(permutation))
	if (true)
	{
		condition = true;
		condition2 = true;
		int currentid = 0;
		for (int i = 0; i < N; i++) {
			testing.clear();
			condition2 = true;
			currentid = i;
			while (condition2) {
				testing.push_back(currentid);
				currentid = PairComplement(permutation, currentid);
				if (find(endofrowids.begin(), endofrowids.end(), currentid) != endofrowids.end()) {
					condition2 = false;
					break;
				}
				else {
					currentid = nextone[currentid];
					if (find(testing.begin(), testing.end(), currentid) != testing.end()) {
						condition2 = false;
						condition = false;
						break;
					}
				}
			}
			if (!condition) break;
		}
		if (!condition) {
			allperms.push_back(permutation);
			thecount++;
		}
	}
}

bool IsInPair(apair pair1, int i) {
	if (pair1.i1 == i) return true;
	else if (pair1.i2 == i) return true;
	else return false;
}

bool IsPairIn(vector<apair> perm, apair thepair) {
	for (int i = 0; i < perm.size(); i++) {
		if (IsPairEquiv(perm[i], thepair)) return true;
	}
	return false;
}

bool IsPairEquiv(apair pair1, apair pair2) {
	if ((pair1.i2 == pair2.i2) && (pair1.i1 == pair2.i1)) return true;
	else if ((pair1.i2 == pair2.i1) && (pair1.i1 == pair2.i2)) return true;
	else return false;
}

int PairComplement(vector<apair> permutation, int i) {
	for (int j = 0; j < permutation.size(); j++) {
		if (permutation[j].i1 == i) return permutation[j].i2;
		if (permutation[j].i2 == i) return permutation[j].i1;
	}
	return 0;
}

bool IsUnique(vector<apair> perm) {
	bool condition = true;
	for (int j = 0; j < allperms.size(); j++) {
		condition = true;
		for (int i = 0; i < perm.size(); i++) {
			if (!IsPairIn(allperms[j], perm[i])) { 
				condition = false;
				break; 
			}
		}
		if (condition) 
			return false;
	}
	return true;
}