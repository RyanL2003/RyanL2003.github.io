/*
ID: rjleal21
TASK: holstein
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

int V;
vector<int> minreq;
int G;
vector<vector<int>> feeds;

int Min;
vector<int> sortedMin;
vector<int> feedtypeNums;

void Recurse(vector<int> input);
bool Satisfy(vector<int> input);
vector<int> GetFeedTypeNums(vector<int> input);
bool Difference(vector<int> input);

bool IsFoundForwards = false;

int main() {
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	fin >> V;
	int temp;
	for (int i = 0; i < V; i++) {
		fin >> temp;
		minreq.push_back(temp);
	}
	fin >> G;
	for (int i = 0; i < G; i++) {
		vector<int> feed;
		for (int j = 0; j < V; j++) {
			fin >> temp;
			feed.push_back(temp);
		}
		feeds.push_back(feed);
	}
	Min = G + 1;
	bool condition = true;
	//Forwards
	vector<int> input;
	for (int i = 0; i < G; i++) {
		condition = true;
		input.clear();
		input.push_back(i);
		if (Satisfy(input)) {
			IsFoundForwards = true;
			if (input.size() < Min) {
				Min = input.size();
				sortedMin = input;
				feedtypeNums = GetFeedTypeNums(input);
			}
			else if (input.size() == Min) {
				if (Difference(GetFeedTypeNums(input))) {
					Min = input.size();
					sortedMin = input;
				}
			}
			condition = false;
		}
		if (condition) for (int j = i + 1; j < G; j++) {
			input.push_back(j);
			if (Satisfy(input)) {
				IsFoundForwards = true;
				if (input.size() < Min) {
					Min = input.size();
					sortedMin = input;
					feedtypeNums = GetFeedTypeNums(input);
				}
				else if (input.size() == Min) {
					if (Difference(GetFeedTypeNums(input))) {
						Min = input.size();
						sortedMin = input;
					}
				}
				condition = false;
			}
			if (condition) for (int k = j + 1; k < G; k++) {
				input.push_back(k);
				if (Satisfy(input)) {
					IsFoundForwards = true;
					if (input.size() < Min) {
						Min = input.size();
						sortedMin = input;
						feedtypeNums = GetFeedTypeNums(input);
					}
					else if (input.size() == Min) {
						if (Difference(GetFeedTypeNums(input))) {
							Min = input.size();
							sortedMin = input;
						}
					}
				}
				input.erase(input.begin() + 2);
			}
			input.erase(input.begin() + 1);
		}
	}

	//Backwards
	if (!IsFoundForwards) {
		vector<int> inputVec;
		for (int i = 0; i < G; i++) {
			inputVec.push_back(i);
		}
		Recurse(inputVec);
	}
	for (int i = 0; i < sortedMin.size(); i++) sortedMin[i]++;
	fout << Min;
	for (int i : sortedMin) fout << " " << i;
	fout << endl;
	return 0;
}

void Recurse(vector<int> input) {
	bool condition = true;
	if (input.size() < Min) {
		Min = input.size();
		sortedMin = input;
		feedtypeNums = GetFeedTypeNums(input);
	}
	else if (input.size() == Min) {
		if (Difference(GetFeedTypeNums(input))) {
			Min = input.size();
			sortedMin = input;
		}
	}
	vector<int> tempvec;
	for (int i = 0; i < input.size(); i++) {
		tempvec = input;
		tempvec.erase(tempvec.begin() + i);
		if (Satisfy(tempvec)) { 
			Recurse(tempvec);
		}
	}
}

bool Satisfy(vector<int> input) {
	vector<int> values;
	values.resize(V, 0);
	bool condition = true;
	for (int i : input) {
		for (int j = 0; j < V; j++) {
			values[j] += feeds[i][j];
		}
	}
	for (int i = 0; i < minreq.size(); i++) if (values[i] < minreq[i]) { return false; }
	return true;
}

vector<int> GetFeedTypeNums(vector<int> input) {
	vector<int> values;
	values.resize(V, 0);
	for (int i : input) {
		for (int j = 0; j < V; j++) {
			values[j] += feeds[i][j];
		}
	}
	return values;
}

bool Difference(vector<int> input) {
	vector<int> values = feedtypeNums;
	for (int i = 0; i < V; i++) values[i] -= input[i];
	int sum = 0;
	for (int i : values) sum += i;
	if (sum > 0) {
		feedtypeNums = input;
		return true;
	}
	else return false;
}