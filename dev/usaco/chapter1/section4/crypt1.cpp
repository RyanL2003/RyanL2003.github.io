/*
ID: rjleal21
TASK: crypt1
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

vector<int> digits;

bool IfValid(int n);
bool IsEachDigit(int n);
bool IsOnlyThree(int n);
int digit(int n);
int runoff(int n);

int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int N;
	fin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		fin >> temp;
		digits.push_back(temp);
	}
	int count = 0;
	int firstnum, secondnum, thirdnum, forthnum, fifthnum, sixthnum, seventhnum, eighthnum, ninthnum, tenthnum, eleventhnum, twelvethnum;
	/*int btimese, atimese, btimesd;
	for (int c = 0; c < N; c++) {
		for (int e = 0; e < N; e++) {
			firstnum = digits[c] * digits[e];
			if (IfValid(digit(firstnum))) for (int b = 0; b < N; b++) {
				btimese = digits[b] * digits[e];
				secondnum = runoff(firstnum) + btimese;
				if (IfValid(digit(secondnum))) for (int d = 0; d < N; d++) {
					thirdnum = digits[c] * digits[d];
					btimesd = digits[b] * digits[d];
					forthnum = btimesd + runoff(thirdnum);
					if (IfValid(digit(thirdnum)) && IfValid(digit(forthnum))) {
						fifthnum = thirdnum + secondnum;
						if (IfValid(digit(fifthnum))) for (int a = 0; a < N; a++) {
							atimese = digits[a] * digits[e];
							sixthnum = atimese + runoff(secondnum);
							seventhnum = sixthnum + forthnum + runoff(digit(secondnum) + digit(thirdnum));
							eighthnum = digits[a] * digits[d] + runoff(forthnum);
							ninthnum = eighthnum + runoff(digit(sixthnum) + digit(forthnum) + runoff(digit(secondnum) + digit(thirdnum)));
							tenthnum = runoff(ninthnum);
							if ((IfValid(digit(sixthnum))) 
								&& (IfValid(digit(seventhnum))) 
								&& (IfValid(digit(eighthnum)))
								&& IfValid(ninthnum)
								&& IfValid(tenthnum)) {
								count++;
							}
						}
					}
				}
			}
		}
	}*/
	int A, B, C, D, E;
	/*for (int c = 0; c < N; c++) for (int e = 0; e < N; e++) for (int b = 0; b < N; b++) for (int d = 0; d < N; d++) for (int a = 0; a < N; a++) {
		A = digits[a];
		B = digits[b];
		C = digits[c];
		D = digits[d];
		E = digits[e];
		firstnum = C * E;
		secondnum = runoff(firstnum) + B * E;
		thirdnum = C * D;
		forthnum = B * D + runoff(thirdnum);
		fifthnum = digit(thirdnum) + digit(secondnum) + runoff(firstnum);
		sixthnum = A * E + runoff(secondnum);
		seventhnum = digit(sixthnum) + digit(forthnum) + runoff(fifthnum);
		eighthnum = A * D + runoff(forthnum);
		twelvethnum = runoff(sixthnum);
		ninthnum = digit(eighthnum) + runoff(seventhnum) + digit(twelvethnum);
		eleventhnum = runoff(eighthnum);
		tenthnum = eleventhnum + runoff(ninthnum);
		if (IfValid(digit(firstnum)) 
			&& IfValid(digit(secondnum))
			&& IfValid(digit(thirdnum))
			&& IfValid(digit(forthnum))
			&& IfValid(digit(fifthnum))
			&& IfValid(digit(sixthnum))
			&& IfValid(digit(seventhnum))
			&& IfValid(digit(eighthnum))
			&& IfValid(digit(ninthnum))
			&& IfValid(digit(tenthnum))
			&& IfValid(digit(eleventhnum))
			&& IfValid(digit(twelvethnum))) {
			count++;
		}
	}*/
	for (int c = 0; c < N; c++) for (int e = 0; e < N; e++) for (int b = 0; b < N; b++) for (int d = 0; d < N; d++) for (int a = 0; a < N; a++) {
		A = digits[a];
		B = digits[b];
		C = digits[c];
		D = digits[d];
		E = digits[e];
		firstnum = A * 100 + B * 10 + C;
		secondnum = D * 10 + E;
		if (IsEachDigit(firstnum * E)
			&& IsEachDigit(firstnum * D)
			&& IsEachDigit(firstnum * secondnum)
			&& IsOnlyThree(firstnum * E)
			&& IsOnlyThree(firstnum * D)) {
			count++;
		}
	}
	fout << count << endl;
	return 0;
}

bool IfValid(int n) {
	int j = 10;
	while (n > 0) {
		if (find(digits.begin(), digits.end(), n % j) == digits.end()) 
			return false;
		n = (n - (n % j)) / 10;
		j *= 10;
	}
	return true;
}

bool IsEachDigit(int n) {
	string str = to_string(n);
	for (int i = 0; i < str.size(); i++) if (find(digits.begin(), digits.end(), str[i] - 48) == digits.end()) 
		return false;
	return true;
}

bool IsOnlyThree(int n) {
	string str = to_string(n);
	if (str.size() != 3) return false;
	return true;
}

int digit(int n) {
	return n % 10;
}

int runoff(int n) {
	return n / 10;
}