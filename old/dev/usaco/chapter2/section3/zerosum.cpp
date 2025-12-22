/*
ID: rjleal21
TASK: zerosum
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

int N;

vector<vector<int>> numbers; //contains all the possible numbers and what they cover (number, first digit, last digit)
vector<string> substrs; //
vector<int> indexes; //contains the index in "numbers" for which the first element that starts with i+1 is located.
vector<string> satisfying;

void recurse(int currentsum, int lastdigit, string str);
string substr(int thenum);

int main() {
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
	
	fin >> N;

	indexes.push_back(0);
	for (int i = 1; i <= N; i++) {
		for (int l = 1; l + i - 1 <= N; l++) { // (int l = 1; l + i - 1 <= N; l++)
		//for (int l = 1 + N - i; l >= 1; l--) {
			int tempnum = 0;
			for (int j = i; j < i + l; j++) {
				tempnum *= 10;
				tempnum += j;
			}
			vector<int> num;
			num.push_back(tempnum);
			num.push_back(i);
			num.push_back(i + l - 1);
			numbers.push_back(num);
			substrs.push_back(substr(tempnum));
		}
		indexes.push_back(numbers.size());
	}

	recurse(0,0, "");

	for (int i = 0; i < satisfying.size(); i++) {
		fout << satisfying[i] << endl;
	}

	return 0;
}

void recurse(int currentsum, int lastdigit, string str) {
	for (int i = indexes[lastdigit]; i < indexes[lastdigit + 1]; i++) {
		if (numbers[i][2] != N) {
			recurse(currentsum + numbers[i][0], numbers[i][2], str + "+" + substrs[i]);
			if (lastdigit != 0) recurse(currentsum - numbers[i][0], numbers[i][2], str + "-" + substrs[i]);
		}
		else {
			if (currentsum + numbers[i][0] == 0) {
				string finalstring = str.substr(1) + "+" + substrs[i];
				int j = 0;
				while (j < satisfying.size()) {
					if (satisfying[j] > finalstring) break;
					j++;
				}
				//satisfying.push_back(str.substr(1) + "+" + substrs[i]);
				satisfying.insert(satisfying.begin() + j, finalstring);
			}
			else if (currentsum - numbers[i][0] == 0) {
				string finalstring = str.substr(1) + "-" + substrs[i];
				int j = 0;
				while (j < satisfying.size()) {
					if (satisfying[j] > finalstring) break;
					j++;
				}
				//satisfying.push_back(str.substr(1) + "-" + substrs[i]);
				satisfying.insert(satisfying.begin() + j, finalstring);
			}
		}
	}
	return;
}

string substr(int thenum) {
	string thesubstr;
	while (thenum > 0) {
		thesubstr.insert(0,to_string(thenum % 10));
		thesubstr.insert(0," ");
		thenum /= 10;
	}
	return thesubstr.substr(1);
}