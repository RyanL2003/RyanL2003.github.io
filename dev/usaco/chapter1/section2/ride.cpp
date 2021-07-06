/*
ID: rjleal21
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet;
	string group;
	int cometNum;
	int groupNum;
	int cometSize;
	int groupSize;
	fin >> comet >> group;
	cometSize = comet.size();
	groupSize = group.size();
	cometNum = 1;
	groupNum = 1;
	for (int i = 0; i < cometSize; i++) {
		cometNum *= (int)(comet[i] - 64);
	}
	for (int i = 0; i < groupSize; i++) {
		groupNum *= (int)(group[i] - 64);
	}
	if ((cometNum % 47) == (groupNum % 47)) {
		fout << "GO" << endl;
	}
	else {
		fout << "STAY" << endl;
	}
	return 0;
}