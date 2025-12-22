/*
ID: rjleal21
TASK: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct gap {
	int start;
	int length;
	int end;
};

struct board {
	int begin;
	int end;
	vector<gap> gaps;
};

int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int M, S, C;
	fin >> M >> S >> C;
	vector<int> first{ 200, 0 };
	vector<bool> stalls(S, false);
	vector<int> cows;
	vector<board> boards;
	int number;
	for (int i = 0; i < C; i++) {
		fin >> number;
		cows.push_back(number);
		stalls[number] = true;
		if (number < first[0]) first[0] = number;
		if (number > first[1]) first[1] = number;
	}
	board board1;
	board1.begin = first[0];
	board1.end = first[1];
	for (int i = first[0]; i < first[1]; i++) {
		if (!stalls[i]) {
			gap thegap;
			thegap.start = i;
			while (!stalls[i]) i++;
			thegap.end = i - 1;
			thegap.length = thegap.end - thegap.start + 1;
			board1.gaps.push_back(thegap);
		}
	}
	boards.push_back(board1);
	int boardnumber;
	int gapnumber;
	int gapsize = 0;
	board oldboard;
	vector<gap> oldgaps;
	board newboard1;
	board newboard2;
	for (int i = 1; i < M; i++) {
		gapsize = 0;
		for (int j = 0; j < boards.size(); j++) {
			for (int k = 0; k < boards[j].gaps.size(); k++) {
				if (boards[j].gaps[k].length > gapsize) {
					boardnumber = j;
					gapnumber = k;
					oldboard = boards[j];
					oldgaps = boards[j].gaps;
					gapsize = boards[j].gaps[k].length;
				}
			}
		}
		if (gapsize != 0)
		{
			oldboard = boards[boardnumber];
			newboard1.gaps.clear();
			newboard2.gaps.clear();
			newboard1.begin = oldboard.begin;
			newboard2.end = oldboard.end;
			newboard1.end = oldgaps[gapnumber].start - 1;
			newboard2.begin = oldgaps[gapnumber].end + 1;
			boards.erase(boards.begin() + boardnumber);
			for (int j = 0; j < gapnumber; j++) newboard1.gaps.push_back(oldgaps[j]);
			for (int j = gapnumber + 1; j < oldgaps.size(); j++) newboard2.gaps.push_back(oldgaps[j]);
			boards.insert(boards.begin() + boardnumber, newboard1);
			boards.insert(boards.begin() + boardnumber + 1, newboard2);
		}
		else break;
	}
	int count = 0;
	for (int i = 0; i < boards.size(); i++) {
		count += boards[i].end - boards[i].begin + 1;
	}
	fout << count << endl;
	return 0;
}