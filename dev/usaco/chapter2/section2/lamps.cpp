/*
ID: rjleal21
TASK: lamps
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
int C;
int indices[6] = {0,1,2,3,2,1};
vector<int> lamps;
vector<vector<int>> trivialconfigs;
vector<string> trivialconfigsstrings;

int countoftrivialconfig(vector<int> config); 
bool compareconfigstrings(string newconfig, string prevconfig);

int main() {
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	lamps.resize(4,2);
	fin >> N;
	fin >> C;
	int temp;
	vector<int> firsts;
	bool isdead = false;
	while ((fin >> temp) && (temp != -1)) {
		temp = temp % 6;
		if (temp == 0) temp += 6;
		temp--;
		if (temp == 5) temp = 1;
		if (temp == 4) temp = 2;
		firsts.push_back(temp);
		lamps[temp] = 1;
	}
	while ((fin >> temp) && (temp != -1)) {
		temp = temp % 6;
		if (temp == 0) temp += 6;
		temp--;
		if (temp == 5) temp = 1;
		if (temp == 4) temp = 2;
		if (find(firsts.begin(), firsts.end(), temp) != firsts.end()) { isdead = true; break; };
		lamps[temp] = 0;
	}
	if (isdead) goto Dead;

	for (int a = 0; a <= 1; a++) {
		for (int b = 0; b <= 1; b++) {
			for (int c = 0; c <= 1; c++) {
				for (int d = 0; d <= 1; d++) {
					bool truth = true;
					if ((lamps[0] != 2) && ((1+a+b+d) % 2 != lamps[0])) {
						truth = false;
					}
					if ((lamps[1] != 2) && ((1+a+c) % 2 != lamps[1])) {
						truth = false;
					}
					if ((lamps[2] != 2) && ((1+a+b) % 2 != lamps[2])) {
						truth = false;
					}
					if ((lamps[3] != 2) && ((1+a+c+d) % 2 != lamps[3])) {
						truth = false;
					}
					if (truth) {
						vector<int> configuration;
						configuration.push_back(a);
						configuration.push_back(b);
						configuration.push_back(c);
						configuration.push_back(d);
						trivialconfigs.push_back(configuration);
					}
				}
			}
		}
	}
	//main issue right now is that this assumes the lamps start off as turned off but they actually
	//start as turned on

	for (vector<int> configuration : trivialconfigs) {
		int opsforconfig = countoftrivialconfig(configuration);
		string configstring = "";
		if ((opsforconfig <= C) && (opsforconfig != C-1)) {
			for (int i = 0; i < N; i++) {
				int index = (i % 6);
				index = indices[index];
				switch (index) {
				case 0:
					configstring += to_string((1+configuration[0] + configuration[1] + configuration[3]) % 2);
					break;
				case 1:
					configstring += to_string((1+configuration[0] + configuration[2]) % 2);
					break;
				case 2:
					configstring += to_string((1+configuration[0] + configuration[1]) % 2);
					break;
				case 3:
					configstring += to_string((1+configuration[0] + configuration[2] + configuration[3]) % 2);
					break;
				}
			}
			if (find(trivialconfigsstrings.begin(), trivialconfigsstrings.end(), configstring) == trivialconfigsstrings.end()) {
				bool didpass = false;
				for (int i = 0; i < trivialconfigsstrings.size(); i++) {
					if (compareconfigstrings(configstring, trivialconfigsstrings[i])) {
						trivialconfigsstrings.insert(trivialconfigsstrings.begin() + i, configstring);
						didpass = true;
						break;
					}
				}
				if (!didpass) trivialconfigsstrings.push_back(configstring);
			}
		}
	}

	for (string config : trivialconfigsstrings) {
		fout << config << endl;
	}
Dead:
	if (trivialconfigsstrings.size() == 0) {
		fout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

int countoftrivialconfig(vector<int> config) {
	return config[0] + config[1] + config[2] + config[3];
}

bool compareconfigstrings(string newconfig, string prevconfig) {
	int newnum = std::bitset<8>(newconfig.substr(0, 8)).to_ulong();
	int prevnum = std::bitset<8>(prevconfig.substr(0, 8)).to_ulong();
	return (newnum < prevnum);
}