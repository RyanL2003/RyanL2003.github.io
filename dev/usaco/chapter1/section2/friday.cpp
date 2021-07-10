/*
ID: rjleal21
TASK: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int N;
	fin >> N;
	int daysofmonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int frequency[7] = { 0,0,0,0,0,0,0 };
	int dayofweek = 2 + 12;
	for (int i = 0; i < N; i++) {
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[0];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		if (i % 4 == 0) {
			if ((i % 100) != 0) {
				dayofweek += 1;
			}
			else if (((1900+i) % 400) == 0) {
				dayofweek += 1;
			}
		}
		dayofweek += daysofmonths[1];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[2];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[3];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[4];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[5];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[6];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[7];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[8];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[9];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[10];
		dayofweek %= 7;
		frequency[dayofweek] += 1;
		dayofweek += daysofmonths[11];
	}
	fout << frequency[0] << " " << frequency[1] << " " << frequency[2] << " " << frequency[3] << " " << frequency[4] << " " << frequency[5] << " " << frequency[6] << endl;
}