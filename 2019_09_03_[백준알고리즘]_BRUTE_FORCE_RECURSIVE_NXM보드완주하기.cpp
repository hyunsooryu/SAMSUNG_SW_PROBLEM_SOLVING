//#include "pch.h"
/*
재귀함수를 구현할 때 주의해야 할점. 

특히 목적지와 하고자 하는 방향을 정확히 파악해야 한다.

*/
#include <iostream>

using namespace std;
//N * M 보드 완주하기
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

char A[33][33];
bool V[33][33];
int N, M;
bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}

int MAX;

void go_only_recursive(int i, int j, int cnt, int now_dir, int turn_cnt) {
	if (cnt == 0) {
		if (MAX == -1 || turn_cnt < MAX) {
			MAX = turn_cnt;
		}
		return;
	}
	if (now_dir >= 0) {
		int ni = di[now_dir] + i;
		int nj = dj[now_dir] + j;
		if (!isNotPossiblePos(ni, nj)) {
			if (A[ni][nj] == '.' && V[ni][nj] == false) {
				V[ni][nj] = true;
				go_only_recursive(ni, nj, cnt - 1, now_dir, turn_cnt);
				V[ni][nj] = false;
			}
			else {
				go_only_recursive(i, j, cnt, -1, turn_cnt); //방향변환
			}
		}
		else {
			go_only_recursive(i, j, cnt, -1, turn_cnt);
		}
	}
	else {
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + i;
			int nj = dj[k] + j;
			if (isNotPossiblePos(ni, nj))continue;
			if (V[ni][nj] || A[ni][nj] == '*')continue;
			V[ni][nj] = true;
			go_only_recursive(ni, nj, cnt - 1, k, turn_cnt + 1);
			V[ni][nj] = false;
		}
	}
}

void go(int i, int j, int cnt, int turn_cnt) {
	if (MAX != -1 && turn_cnt == MAX)return;
	//cout << i << " " << j << " " << cnt << " " << turn_cnt << endl;
	if (cnt == 0) {
		if (MAX == -1 || turn_cnt < MAX) {
			MAX = turn_cnt;
		}
		return;
	}
	for (int k = 0; k < 4; k++) {
		int now_i = i;
		int now_j = j;
		int tmp = cnt;
		while (true) {
			int ni = now_i + di[k];
			int nj = now_j + dj[k];
			if (isNotPossiblePos(ni, nj))break;
			if (A[ni][nj] == '*' || V[ni][nj])break;
			V[ni][nj] = true;
			now_i = ni;
			now_j = nj;
			tmp -= 1;
		}
		if ((now_i == i && now_j == j))continue;

		go(now_i, now_j, tmp, turn_cnt + 1);
		while (!(now_i == i && now_j == j)) {
			V[now_i][now_j] = false;
			now_i -= di[k];
			now_j -= dj[k];
			
		}
	}
	return;
}


int main() {
	int tc = 1;
	while (cin >> N >> M) {
		MAX = -1;
		int CNT = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> A[i][j];
				if (A[i][j] == '.') {
					CNT += 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				V[i][j] = true;
				if (A[i][j] == '.') {
					go_only_recursive(i, j, CNT - 1, -1, 0);
				}
				V[i][j] = false;
			}
		}
		cout << "Case " << tc++ << ": " << MAX << "\n";
	}













	return 0;
}
