/*
ID: rjleal21
TASK: preface
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

void getdigits(int N);
void addwholeten(int col, int coefficient);
void addwhole(int col, int index, int coefficient);
void addsingle(int col, int index, int coefficient);

int N;
vector<int> counts;
vector<char> countsindices{ 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
vector<int> firstdigit{ 0,1,2 };
vector<int> seconddigit{ 2,3,4 };
vector<int> thirddigit{ 4,5,6 };
vector<int> fourthdigit{ 6,7,7 };
vector<vector<int>> digitvectors{ firstdigit,seconddigit,thirddigit,fourthdigit };
vector<int> firstinc { 1,2,3,1,0,1,2,3,1 };
vector<int> secondinc{ 0,0,0,1,1,1,1,1,0 };
vector<int> thirdinc { 0,0,0,0,0,0,0,0,1 };
vector<int> digits;
int digitcount;

int main() {
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	fin >> N;
	counts.resize(8, 0);
	getdigits(N);
	reverse(digits.begin(), digits.end());

	int tempN = N + 1;

	for (int i = digitcount - 1; i >= 0; i--) {
		tempN -= (digits[i] * pow(10,i));
		if ((digits[i] != 0) && (i != 0))
		{
			if (digits[i] > 1) addwhole(i, digits[i] - 1, pow(10, i));
			addsingle(i, digits[i], tempN);

			for (int j = i - 1; j >= 0; j--) {
				addwholeten(j, digits[i] * pow(10, (i-1)));
			}
		}
		else if (i == 0) addwhole(0, digits[i], 1);
	}

	for (int i = 0; i < 7; i++) {
		if (counts[i] != 0) {
			fout << countsindices[i] << " " << counts[i] << endl;
		}
	}
	return 0;
}

void getdigits(int N) {
	if (N >= 10) {
		getdigits(N / 10);
	}

	int digit = N % 10;
	digitcount++;

	digits.push_back(digit);
}

void addwholeten(int col, int coefficient) {
	for (int i = 0; i < 9; i++) {
		counts[digitvectors[col][0]] += firstinc[i] * coefficient;
		counts[digitvectors[col][1]] += secondinc[i] * coefficient;
		counts[digitvectors[col][2]] += thirdinc[i] * coefficient;
	}
}

void addwhole(int col, int index, int coefficient) {
	for (int i = 0; i < index; i++) {
		counts[digitvectors[col][0]] += firstinc[i] * coefficient;
		counts[digitvectors[col][1]] += secondinc[i] * coefficient;
		counts[digitvectors[col][2]] += thirdinc[i] * coefficient;
	}
}

void addsingle(int col, int index, int coefficient) {
	counts[digitvectors[col][0]] += firstinc[index - 1] * coefficient;
	counts[digitvectors[col][1]] += secondinc[index - 1] * coefficient;
	counts[digitvectors[col][2]] += thirdinc[index - 1] * coefficient;
}