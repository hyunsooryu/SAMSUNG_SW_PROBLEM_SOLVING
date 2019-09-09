//#include "pch.h"
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
char MAP[20][20];
int INDEX[20][20];
int DIST[11][11];
int V[11][20][20];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
bool isNotPossblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}
int S, E;
int main() {
	while (true) {
		cin >> M >> N;
		if (M == 0 && N == M)break;
		memset(V, -1, sizeof(V));
		memset(INDEX, -1, sizeof(INDEX));
		memset(DIST, 0, sizeof(DIST));
		queue<tuple<int, int, int>> Q;
		int CNT = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> MAP[i][j];
				if (MAP[i][j] == 'o') {
					INDEX[i][j] = 0;
					V[0][i][j] = 0;
					Q.push(make_tuple(0, i, j));
				}
				else if (MAP[i][j] == '*') {
					V[CNT][i][j] = 0;
					Q.push(make_tuple(CNT, i, j));
					INDEX[i][j] = CNT++;
				}
			}
		}

		while (!Q.empty()) {
			int id, i, j;
			tie(id, i, j) = Q.front(); Q.pop();
			//cout << "VISIT ID : " << id << " " << "POS : " << i << " " << j << " DIST : " << V[id][i][j] << endl;
			for (int k = 0; k < 4; k++) {
				int ni = di[k] + i;
				int nj = dj[k] + j;
				if (isNotPossblePos(ni, nj))continue;
				if (MAP[ni][nj] == 'x' || V[id][ni][nj] >= 0)continue;
				if (INDEX[ni][nj] >= 0)DIST[id][INDEX[ni][nj]] = V[id][i][j] + 1;
				V[id][ni][nj] = V[id][i][j] + 1;
				Q.push(make_tuple(id, ni, nj));
			}
		}
		vector<int> TMP(CNT);
		for (int k = 0; k < CNT; k++) {
			TMP[k] = k;
		}
		int MIN_ANS = -1;
		do {
			if (!DIST[0][TMP[1]])continue;
			int ANS = DIST[0][TMP[1]];
			bool flag = false;
			for (int i = 1; i < CNT - 1; i++) {
				int TMP_ANS = DIST[TMP[i]][TMP[i + 1]];
				if (!TMP_ANS) {
					flag = true;
					break;
				}
				ANS += TMP_ANS;
			}
			if (!flag) {
				/*
				cout << "PATH : " << endl;
				for (int k = 0; k < CNT; k++) {
					cout << TMP[k] << " ";
				}cout << endl;
				*/
				//	cout << "NOW_MIN_ANS : " << MIN_ANS <<  " (VS) TRY_ANS : " << ANS << endl;
				if (MIN_ANS == -1 || ANS < MIN_ANS) {
					//	cout << "##CHANGED" << endl;
					MIN_ANS = ANS;
					//	cout << "NOW_MIN_ANS : " << MIN_ANS << endl;
				}
			}
		} while (next_permutation(TMP.begin() + 1, TMP.end()));


		cout << MIN_ANS << endl;

	}







	return 0;
}