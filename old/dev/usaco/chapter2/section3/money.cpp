/*
ID: rjleal21
TASK: money
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

int N, V;
vector<int> values;

//vector<long long> totals;
long long total;
vector<vector<long long>> totals;

long long recurse(int remaining, int highest);


int main() {
	ifstream fin("money.in");
	ofstream fout("money.out");
	
	fin >> V >> N;

	//totals.push_back(0);
	int temp;
	while (fin >> temp) {
		/*int i = 0;
		while ((i < values.size()) && (values[i] < temp)) i++;
		values.insert(values.begin() + i,temp);*/
		values.push_back(temp);
	}

	for (int i = 0; i <= N; i++) {
		vector<long long> instancetotals;
		instancetotals.resize(V, -1);
		totals.push_back(instancetotals);
	}

	/*for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j <= (i / 2); j++) {
			temp += totals[j] * totals[i - j];
		}
		if (find(values.begin(), values.end(), i) != values.end()) temp++;
		totals.push_back(temp);
	}

	fout << totals[N];*/

	total = recurse(N, values.size() - 1);

	fout << total << endl;

	return 0;
}

long long recurse(int remaining, int highest) { //remaining amount to be completed, highest index coin val
	long long temp = 0;
	if (highest != 0) for (int i = 0; i * values[highest] <= remaining; i++) {
		if (totals[remaining - i * values[highest]][highest - 1] == -1)
			totals[remaining - i * values[highest]][highest - 1] = recurse(remaining - i * values[highest], highest - 1);
		temp += totals[remaining - i * values[highest]][highest - 1];
	}
	else {
		return ((remaining % values[highest] == 0) ? (1) : (0));
	}
	return temp;
}