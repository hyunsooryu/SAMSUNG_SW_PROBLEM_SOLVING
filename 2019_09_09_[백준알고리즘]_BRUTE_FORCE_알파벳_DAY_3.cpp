//#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
bool V[26];
char MAP[20][20];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}


int go(int i, int j) {
	int MAX = 1;
	for (int k = 0; k < 4; k++) {
		int ni = di[k] + i;
		int nj = dj[k] + j;
		if (isNotPossiblePos(ni, nj))continue;
		if (V[MAP[ni][nj] - 'A'])continue;
		V[MAP[ni][nj] - 'A'] = true;
		int tmp = go(ni, nj) + 1;
		V[MAP[ni][nj] - 'A'] = false;
		MAX = max(MAX, tmp);
	}
	return MAX;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
	V[MAP[0][0] - 'A'] = true;
	cout << go(0, 0) << endl;
	return 0;
}