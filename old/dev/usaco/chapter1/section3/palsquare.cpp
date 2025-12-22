/*
ID: rjleal21
TASK: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int digitplaces;
vector<int> ConvertToBase(int b, int baseten);

int main() {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int base;
	fin >> base;
	digitplaces = (int)(log(90000) / log(base)) + 1;
	vector<int> max;
	vector<char> chars{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
	int threehundred = 300;
	for (int i = 0; i <= 9; i++) {
		max.push_back(threehundred / pow(base, 9-i));
		threehundred %= (int)pow(base, 9 - i);
	}
	while (max[0] == 0) {
		max.erase(max.begin());
	}
	vector<vector<int>> numbers;
	vector<vector<int>> palindromes;
	vector<int> square;
	vector<int> number;
	bool condition = true;
	for (int i = 1; i < 301; i++) {
		condition = true;
		number = ConvertToBase(base, i);
		square = ConvertToBase(base, i*i);
		for (int i = 0; i < (square.size() / 2); i++) {
			if ((square[i]) != (square[square.size() - 1 - i])) {
				condition = false;
				break;
			}
		}
		if (condition) {
			numbers.push_back(number);
			palindromes.push_back(square);
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = 0; j < numbers[i].size(); j++) fout << chars[numbers[i][j]];
		fout << " ";
		for (int j = 0; j < palindromes[i].size(); j++) fout << chars[palindromes[i][j]];
		fout << endl;
	}
	return 0;
}

vector<int> ConvertToBase(int b, int baseten) {
	vector<int> number;
	for (int i = 0; i <= digitplaces; i++) {
		number.push_back(baseten / pow(b, digitplaces - i));
		baseten %= (int)pow(b, digitplaces - i);
	}
	while (number[0] == 0) {
		number.erase(number.begin());
	}
	return number;
}