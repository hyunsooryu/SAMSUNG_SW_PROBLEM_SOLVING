//#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;
int T, N, M, X, Y, L;
int D[50][50];
int MAP[50][50];
bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
int POSSIBLE[8][4];
bool POSSIBLE_DIR[8][4];



void SET_POSSIBLE() {

	for (int C = 1; C < 8; C++) {
			//상
			if (C == 1 || C == 2 || C == 5 || C == 6) {
				POSSIBLE[C][0] = true;
				POSSIBLE_DIR[C][1] = true;
			}

			//하
			if (C == 1 || C == 2 || C == 4 || C == 7) {
				POSSIBLE[C][1] = true;
				POSSIBLE_DIR[C][0] = true;
			}

			//좌
			if (C == 1 || C == 3 || C == 4 || C == 5) {
				POSSIBLE[C][2] = true;
				POSSIBLE_DIR[C][3] = true;
			}

			//우
			if (C == 1 || C == 3 || C == 6 || C == 7) {
				POSSIBLE[C][3] = true;
				POSSIBLE_DIR[C][2] = true;
			}
	}
}

int BFS() {
	queue<pair<int, int>> Q;
	D[X][Y] = 1;
	Q.push(make_pair(X, Y));
	while (!Q.empty()) {
		int i, j, id;
		tie(i, j) = Q.front(); Q.pop();
		id = MAP[i][j];
		if (D[i][j] == L)continue;

		for (int k = 0; k < 4; k++) {
			if (!POSSIBLE_DIR[id][k])continue;
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (isNotPossiblePos(ni, nj))continue;
			if (D[ni][nj] > 0 || !POSSIBLE[MAP[ni][nj]][k])continue;
			D[ni][nj] = D[i][j] + 1;
			Q.push(make_pair(ni, nj));
		}
	}
	int ANS = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (D[i][j]) {
				ANS = ANS + 1;
				D[i][j] = 0;
			}
		}
	}
	return ANS;
}


int main() {
	SET_POSSIBLE();

	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		scanf("%d %d %d %d %d", &N, &M, &X, &Y, &L);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &MAP[i][j]);
			}
		}
		cout << "#" << testcase << " " << BFS() << "\n";
	}







	return 0;
}