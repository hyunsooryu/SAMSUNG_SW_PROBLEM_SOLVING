//#include "pch.h"
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int N, K;
int A[8][8];
bool VISITED[8][8];
bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= N;
}
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

int go(int i, int j, bool cutting_used) {
	//cout << i << " , " << j << " cutting_used : " << cutting_used << endl;
	int val = A[i][j];
	int MAX = 1;
	for (int k = 0; k < 4; k++) {
		int ni = di[k] + i;
		int nj = dj[k] + j;
		if (isNotPossiblePos(ni, nj))continue;
		if (VISITED[ni][nj])continue;
		if (A[ni][nj] < val) {
			VISITED[ni][nj] = true;
			int MAX_TMP = go(ni, nj, cutting_used) + 1;
			MAX = max(MAX_TMP, MAX);
			VISITED[ni][nj] = false;
		}
		else {
			if (cutting_used)continue;
			if (A[ni][nj] >= val && (A[ni][nj] - K <= val - 1)) {
				VISITED[ni][nj] = true;
				int tmp = A[ni][nj];
				A[ni][nj] = val - 1;
				int MAX_TMP = go(ni, nj, true) + 1;
				MAX = max(MAX_TMP, MAX);
				A[ni][nj] = tmp;
				VISITED[ni][nj] = false;
			}
		}
	}
	return MAX;
}

int main() {
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase) {
		cin >> N >> K;
		int ANS = 1;
		vector<pair<int, int>> TOPS;
		int MAX_HEIGHT = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
				if (A[i][j] > MAX_HEIGHT) {
					MAX_HEIGHT = A[i][j];
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] == MAX_HEIGHT) {
					TOPS.push_back(make_pair(i, j));
				}
			}
		}
		
		for (pair<int, int> TOP : TOPS) {
			int i, j;
			tie(i, j) = TOP;
			VISITED[i][j] = true;
			int ANS_TMP = go(i, j, false);
			if (ANS_TMP > ANS) {
				ANS = ANS_TMP;
			}
		//	cout << ANS << endl;
			VISITED[i][j] = false;
		}

		cout << "#" << testcase << " " << ANS << "\n";
	}











	return 0;
}