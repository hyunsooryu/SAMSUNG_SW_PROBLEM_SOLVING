//#include "pch.h"
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int N, M;
int A[8][8];
bool V[8][8];
int TOTAL;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
bool isOut(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}

int go(vector<pair<int,int>> VIRUS) {
	memset(V, false, sizeof(V));
	queue<pair<int, int>> Q;
	for (auto pos : VIRUS) {
		Q.push(pos);
	}
	int cnt = 0;
	while (!Q.empty()) {
		int i, j;
		tie(i, j) = Q.front(); Q.pop();
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (isOut(ni, nj))continue;
			if (A[ni][nj] >= 1 || V[ni][nj])continue;
			V[ni][nj] = true;
			cnt += 1;
			Q.push(make_pair(ni, nj));
		}
	}
	/*
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 0) {
				if (V[i][j]) {
					cout << "V ";
				}
				else {
					cout << "S ";
				}
			}
			else {
				cout << A[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << cnt << endl;
	*/
	return cnt;
}

int main() {
	cin >> N >> M;
	int ANS = 0;
	vector<pair<int, int>> VIRUS;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] == 0)TOTAL++;
			if (A[i][j] == 2) {
				VIRUS.push_back(make_pair(i, j));
			}
		}
	}
	for (int block1 = 0; block1 < N * M - 2; block1++) {
		int i1 = block1 / M;
		int j1 = block1 % M;
		if (A[i1][j1] >= 1)continue;
		A[i1][j1] = 1;
		for (int block2 = block1 + 1; block2 < N * M - 1; block2++) {
			int i2 = block2 / M;
			int j2 = block2 % M;
			if (A[i2][j2] >= 1)continue;
			A[i2][j2] = 1;
			for (int block3 = block2 + 1; block3 < N * M; block3++) {
				int i3 = block3 / M;
				int j3 = block3 % M;
				if (A[i3][j3] >= 1)continue;
				A[i3][j3] = 1;
				int TMP_ANS = TOTAL - 3 - go(VIRUS);
				if (TMP_ANS > ANS) ANS = TMP_ANS;
				A[i3][j3] = 0;
			}
			A[i2][j2] = 0;
		}
		A[i1][j1] = 0;
	}
	cout << ANS << endl;







	return 0;
}