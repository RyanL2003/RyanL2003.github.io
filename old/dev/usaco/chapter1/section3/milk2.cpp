/*
ID: rjleal21
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	int N;
	fin >> N;
	vector<int> starts;
	vector<int> ends;
	int latesttime = 0;
	int max1 = 0;
	vector<int> indicesleft;
	int currenttime = 1000000;
	for (int i = 0; i < N; i++) {
		int start;
		int end;
		fin >> start >> end;
		starts.push_back(start);
		ends.push_back(end);
		indicesleft.push_back(i);
		if (currenttime > starts[i]) currenttime = starts[i];
		if (latesttime < end) latesttime = end;
	}
	int max2 = 0;
	int lasttime = 0;
	int finaltime = 0;
	int nexttime = 0;
	int nextindex;
	bool haschanged = false;
	vector<int> activeindices;
	while (currenttime < latesttime) {
		nexttime = latesttime;
		if (haschanged == false) {
			lasttime = latesttime;

			for (int i = 0; i < indicesleft.size(); i++) {
				if (lasttime > starts[indicesleft[i]]) { 
					lasttime = starts[indicesleft[i]]; 
					finaltime = ends[indicesleft[i]];
					nextindex = i;
				}
			}
			indicesleft.erase(indicesleft.begin() + nextindex);
			if ((lasttime - currenttime) > max2) max2 = lasttime - currenttime;
			haschanged = true;
		}
		else if (haschanged == true) {
			haschanged = false;
			for (int i = 0; i < indicesleft.size(); i++) {
				if (starts[indicesleft[i]] <= finaltime) {
					if (ends[indicesleft[i]] > finaltime) { 
						finaltime = ends[indicesleft[i]];
						haschanged = true;
					}
					indicesleft.erase(indicesleft.begin() + i);
				}
			}
			if (haschanged == false) {
				currenttime = finaltime;
				if ((currenttime - lasttime) > max1) max1 = currenttime - lasttime;
			}
		}

	}
	
	fout << max1 << " " << max2 << endl;
	return 0;
}