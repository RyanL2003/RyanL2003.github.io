/*
ID: rjleal21
TASK: sprime
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
int sqrtnum;
int N;
vector<int> primes;
vector<int> values;
vector<vector<int>> primessorted;

int Digits(int n);
bool IsPrime(int n);

int main() {
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	fin >> N;
	sqrtnum = (int)sqrt(pow(10, N)) + 50;
	bool condition = true;
	/*for (int i = 2; i < sqrtnum; i++) {
		condition = true;
		for (int j : primes) if (i % j == 0) { condition = false; break; }
		if (condition) primes.push_back(i);
	}
	int Max = (int)pow(10, N);
	int num;
	for (int i = (int)pow(10, N - 1); i < Max; i++) {
		condition = true;
		num = i;
		for (int n = 0; n < N; n++) {
			if (num == 1) {
				condition = false;
				break;
			}
			for (int j : primes) 
				if (num % j == 0) {
				if (num != j)
					condition = false;
				break;
			}
			if (!condition) break;
			num /= 10;
		}
		if (condition) fout << i << endl;
	}*/
	int max = (int)pow(10, N);
	for (int i = 0; i < N + 1; i++) {
		vector<int> primeswithdig;
		primessorted.push_back(primeswithdig);
	}
	for (int i = 2; i < sqrtnum; i++) {
		condition = true;
		for (int j : primes) if (i % j == 0) { 
			condition = false; 
			break; 
		}
		if (condition) { 
			primes.push_back(i);
			if (Digits(i) == 1) primessorted[0].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < primessorted[i - 1].size(); j++) {
			for (int k = 1; k < 10; k += 2) {
				if (IsPrime((primessorted[i-1][j] * 10) + k)) {
					primessorted[i].push_back((primessorted[i - 1][j] * 10) + k);
				}
			}
		}
	}
	for (int i = 0; i < primessorted[N - 1].size(); i++) {
		fout << primessorted[N - 1][i] << endl;
	}
	return 0;
}

int Digits(int n) {
	if (n / 10 == 0) return 1;
	if (n / 100 == 0) return 2;
	if (n / 1000 == 0) return 3;
	if (n / 10000 == 0) return 4;
	if (n / 100000 == 0) return 5;
	if (n / 1000000 == 0) return 6;
	if (n / 10000000 == 0) return 7;
	if (n / 100000000 == 0) return 8;
	if (n / 1000000000 == 0) return 9;
	else return 0;
}

bool IsPrime(int n) {
	for (int i : primes) if (n % i == 0) {
		if (n != i) return false;
		else return true;
	}
	return true;
}