/*
ID: rjleal21
TASK: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int count;
	fin >> count;
	vector<string> names;
	//string names = (string*)malloc(14 * 8);
	int* moneys = (int*)malloc(32 * count);
	for (int i = 0; i < count; i++) {
		string newname;
		fin >> newname;
		names.push_back(newname);
		moneys[i] = (int)0;
	}
	int moneyGiven, peopleGiven;
	int index = 0;
	int givingindex = 0;
	int moneyback = 0;
	int moneyPerPerson = 0;
	for (int i = 0; i < count; i++) {
		string currentname;
		string givingname;
		fin >> currentname;
		for (int j = 0; j < count; j++) {
			if (names[j] == currentname) {
				index = j;
				break;
			}
		}
		fin >> moneyGiven;
		fin >> peopleGiven;
		moneyback = (peopleGiven == 0) ? moneyGiven : moneyGiven % peopleGiven;
		moneyPerPerson = (peopleGiven == 0) ? 0 : moneyGiven / peopleGiven;
		moneys[index] += moneyback - (moneyGiven);
		for (int j = 0; j < peopleGiven; j++) {
			fin >> givingname;
			for (int k = 0; k < count; k++) {
				if (names[k] == givingname) {
					givingindex = k;
					break;
				}
			}
			moneys[givingindex] += moneyPerPerson;
		}
	}
	for (int i = 0; i < count; i++) {
		fout << names[i] << " " << moneys[i] << endl;
	}
	return 0;
}