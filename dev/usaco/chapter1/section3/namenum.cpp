/*
ID: rjleal21
TASK: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream dict("dict.txt");
	vector<string> dictionary;
	vector<int> inputnumber;
	vector<vector<string>> numberletters;
	vector<string> iteration;
	iteration.push_back("A");
	iteration.push_back("B");
	iteration.push_back("C");
	numberletters.push_back(iteration);
	iteration.clear();
	iteration.push_back("D");
	iteration.push_back("E");
	iteration.push_back("F");
	numberletters.push_back(iteration);
	iteration.clear();
	iteration.push_back("G");
	iteration.push_back("H");
	iteration.push_back("I");
	numberletters.push_back(iteration);
	iteration.clear();
	iteration.push_back("J");
	iteration.push_back("K");
	iteration.push_back("L");
	numberletters.push_back(iteration);
	iteration.clear(); 
	iteration.push_back("M");
	iteration.push_back("N");
	iteration.push_back("O");
	numberletters.push_back(iteration);
	iteration.clear();
	iteration.push_back("P");
	iteration.push_back("R");
	iteration.push_back("S");
	numberletters.push_back(iteration);
	iteration.clear();
	iteration.push_back("T");
	iteration.push_back("U");
	iteration.push_back("V");
	numberletters.push_back(iteration);
	iteration.clear();
	iteration.push_back("W");
	iteration.push_back("X");
	iteration.push_back("Y");
	numberletters.push_back(iteration);
	vector<string> possiblenames;
	while (!fin.eof()) {
		inputnumber.push_back(fin.get() - 48);
	}
	inputnumber.erase(inputnumber.end() - 1);
	inputnumber.erase(inputnumber.end() - 1);
	while (!dict.eof()) {
		string newName;
		dict >> newName;
		dictionary.push_back(newName);
	}
	if (inputnumber.size() < 9) {
		int possiblenamescount = (int)pow((double)3, (double)inputnumber.size());
		string name;
		int index;
		int remainder;
		for (int i = 0; i < possiblenamescount; i++) {
			name.clear();
			index = i;
			remainder = 0;
			for (int j = 0; j < inputnumber.size(); j++) {
				remainder = index % (int)pow(3, j + 1);
				index -= remainder;
				name.append(numberletters[inputnumber[j] - 2][(int)(remainder / ((int)pow((float)3, (float)j)))]);
			}
			if (find(dictionary.begin(), dictionary.end(), name) != dictionary.end()) {
				possiblenames.push_back(name);
			}
		}
		sort(possiblenames.begin(), possiblenames.end());
		for (int i = 0; i < possiblenames.size(); i++) {
			fout << possiblenames[i] << endl;
		}
	}
	else {
		int n = inputnumber.size();
		for (int i = 0; i < dictionary.size(); i++) {
			if (dictionary[i].length() == n) possiblenames.push_back(dictionary[i]);
		}
		for (int i = 0; i < possiblenames.size(); i++) {
			for (int j = 0; j < n; j++) {
				if ((possiblenames[i][j] != numberletters[inputnumber[j] - 2][0][0]) && (possiblenames[i][j] != numberletters[inputnumber[j] - 2][1][0]) && (possiblenames[i][j] != numberletters[inputnumber[j] - 2][2][0])) {
					possiblenames.erase(possiblenames.begin()+i);
					i--;
					break;
				}
			}
		}
		sort(possiblenames.begin(), possiblenames.end());
		for (int i = 0; i < possiblenames.size(); i++) {
			fout << possiblenames[i] << endl;
		}
	}
	if (possiblenames.size() == 0) {
		fout << "NONE" << endl;
	}
	return 0;
}