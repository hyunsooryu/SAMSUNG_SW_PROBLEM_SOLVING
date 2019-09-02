//#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int A[20][20];
bool EATEN[101];
int di[] = { 1,1,-1,-1 };
int dj[] = { 1,-1,-1,1 };

bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= N;
}

int go(int i, int j, int now_turn, int first_cnt, int second_cnt, int cnt) {
	//cout << i << " " << j << " VALUE : " <<  A[i][j] << " NOW_TURN : " << now_turn << " first_cnt : " << first_cnt << " second_cnt : " << second_cnt << " TOTAL_CNT : " << cnt << endl;
	if (now_turn == 3 && first_cnt == 0 && second_cnt == 0) {
		//	cout << "SUCCESS!" << endl;
		return cnt;
	}

	int SUM = -1;
	if (now_turn == 0) {
		int ni = di[now_turn] + i;
		int nj = dj[now_turn] + j;
		if (!isNotPossiblePos(ni, nj) && !EATEN[A[ni][nj]]) {
			EATEN[A[ni][nj]] = true;
			SUM = max(SUM, go(ni, nj, now_turn, first_cnt + 1, second_cnt, cnt + 1));
			EATEN[A[ni][nj]] = false;
		}
		if (first_cnt > 0) {
			int next_ni = di[now_turn + 1] + i;
			int next_nj = dj[now_turn + 1] + j;
			if (!isNotPossiblePos(next_ni, next_nj)) {
				if (!EATEN[A[next_ni][next_nj]]) {
					EATEN[A[next_ni][next_nj]] = true;
					SUM = max(SUM, go(next_ni, next_nj, now_turn + 1, first_cnt, second_cnt + 1, cnt + 1));
					EATEN[A[next_ni][next_nj]] = false;
				}
			}
		}
	}
	else if (now_turn == 1) {
		int ni = di[now_turn] + i;
		int nj = dj[now_turn] + j;
		if (!isNotPossiblePos(ni, nj) && !EATEN[A[ni][nj]]) {
			EATEN[A[ni][nj]] = true;
			SUM = max(SUM, go(ni, nj, now_turn, first_cnt, second_cnt + 1, cnt + 1));
			EATEN[A[ni][nj]] = false;
		}
		if (second_cnt > 0) {
			int next_ni = di[now_turn + 1] + i;
			int next_nj = dj[now_turn + 1] + j;
			if (!isNotPossiblePos(next_ni, next_nj) && !EATEN[A[next_ni][next_nj]]) {
				EATEN[A[next_ni][next_nj]] = true;
				SUM = max(SUM, go(next_ni, next_nj, now_turn + 1, first_cnt - 1, second_cnt, cnt + 1));
				EATEN[A[next_ni][next_nj]] = false;
			}
		}
	}
	else if (now_turn == 2) {
		if (first_cnt == 0) {
			int ni = di[now_turn + 1] + i;
			int nj = dj[now_turn + 1] + j;
			if (!isNotPossiblePos(ni, nj)) {
				if (second_cnt - 1 == 0) {
					SUM = max(SUM, go(ni, nj, now_turn + 1, first_cnt, second_cnt - 1, cnt + 1));
				}
				else if (!EATEN[A[ni][nj]]) {
					EATEN[A[ni][nj]] = true;
					SUM = max(SUM, go(ni, nj, now_turn + 1, first_cnt, second_cnt - 1, cnt + 1));
					EATEN[A[ni][nj]] = false;
				}
			}
		}
		else {
			int ni = di[now_turn] + i;
			int nj = dj[now_turn] + j;
			if (!isNotPossiblePos(ni, nj) && !EATEN[A[ni][nj]]) {
				EATEN[A[ni][nj]] = true;
				SUM = max(SUM, go(ni, nj, now_turn, first_cnt - 1, second_cnt, cnt + 1));
				EATEN[A[ni][nj]] = false;
			}
		}
	}
	else if (now_turn == 3) {
		int ni = di[now_turn] + i;
		int nj = dj[now_turn] + j;
		if (!isNotPossiblePos(ni, nj)) {
			if (EATEN[A[ni][nj]] && second_cnt - 1 == 0) {
				SUM = max(SUM, go(ni, nj, now_turn, first_cnt, second_cnt - 1, cnt + 1));
			}
			else if (!EATEN[A[ni][nj]]) {
				EATEN[A[ni][nj]] = true;
				SUM = max(SUM, go(ni, nj, now_turn, first_cnt, second_cnt - 1, cnt + 1));
				EATEN[A[ni][nj]] = false;
			}
		}
	}
	return SUM;
}


int main() {
	scanf_s("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}
		int ANS = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				EATEN[A[i][j]] = true;
				int TMP_ANS = go(i, j, 0, 0, 0, 0);
				if (TMP_ANS > ANS)ANS = TMP_ANS;
				EATEN[A[i][j]] = false;
			}
		}
		cout << "#" << testcase << " " << ANS << "\n";
	}











	return 0;
}