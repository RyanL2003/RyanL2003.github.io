/*
ID: rjleal21
TASK: pprime
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

int A, B;
int mindigits = 0, maxdigits = 0;
vector<int> primes;
vector<int> values;

int GenPal(int num, int size, bool parity);

int main() {
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	fin >> A >> B;
	bool condition = true;
	int temp = A;
	while (temp > 0) { mindigits++; temp /= 10; }
	temp = B;
	while (temp > 0) { maxdigits++; temp /= 10; }
	for (int i = 2; i < 10008; i++) {
		condition = true;
		for (int j : primes) if (i % j == 0) { condition = false; break; }
		if (condition) primes.push_back(i);
	}
	int lengthofiteration;
	int value;
	bool parity;
	for (int i = mindigits; i <= maxdigits; i++) {
		lengthofiteration = (i + 1) / 2;
		parity = (i % 2 == 0) ? (true) : (false);
		for (int j = (int)pow(10, lengthofiteration - 1); j < (int)pow(10, lengthofiteration); j++) {
			value = GenPal(j, lengthofiteration, parity);
			if ((A <= value) && (value <= B)) {
				condition = true;
				for (int k = 0; k < primes.size(); k++) if ((value % primes[k] == 0) && (value != primes[k])) {
					condition = false;
					break;
				}
				if (condition) values.push_back(value);
			}
		}
	}
	for (int i = 0; i < values.size(); i++) fout << values[i] << endl;
	return 0;
}

int GenPal(int num, int size, bool parity) {
	int returnnum = 0;
	int numagain = num;
	for (int i = 0; i < size; i++) {
		returnnum += (numagain % 10) * (int)pow(10, size - 1 - i);
		numagain /= 10;
	}
	return (parity) ? returnnum + (num * (int)pow(10, size)) : returnnum + ((num / 10) * (int)pow(10, size));
}