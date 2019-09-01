//#include "pch.h"
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int SIZE[15][15];
char MAP[15][15];
int N, M;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}

vector<pair<int, int>> POS;
int CAL(int n) {
	return n * 4 + 1;
}
void Set(int i, int j) {
	SIZE[i][j] = 0;
	int NEW_SIZE = 1;
	while (true) {
		bool flag = false;
		for (int k = 0; k < 4; k++) {
			int ni = di[k] * NEW_SIZE + i;
			int nj = dj[k] * NEW_SIZE + j;
			if (isNotPossiblePos(ni, nj)) {
				flag = true;
				break;
			}
			if (MAP[ni][nj] == '.') {
				flag = true;
				break;
			}
		}
		if (flag)break;
		SIZE[i][j] = NEW_SIZE;
		NEW_SIZE += 1;
	}
	POS.push_back(make_pair(i, j));
}

int getMax(int a, int b) {
	int ai = POS[a].first;
	int aj = POS[a].second;
	int bi = POS[b].first;
	int bj = POS[b].second;

	//1 -> 3
	int MAX = 0;
	for (int size1 = 0; size1 <= SIZE[ai][aj]; size1++) {
		for (int size2 = 0; size2 <= SIZE[bi][bj]; size2++) {
			if (ai == bi) {// 1 -> 3
				int a_begin = aj - size1;
				int a_end = aj + size1;
				int b_begin = bj - size2;
				int b_end = bj + size2;
				bool flag = false;
				for (int k = a_begin; k <= a_end; k++) {
					if (b_begin <= k && k <= b_end) {
						flag = true;
						break;
					}
				}
				if (flag)continue;
			}

			if (aj == bj) {
				int a_begin = ai - size1;
				int a_end = ai + size1; 
				int b_begin = bi - size2;
				int b_end = bi + size2;
				bool flag = false;
				for (int k = a_begin; k <= a_end; k++) {
					if (b_begin <= k && k <= b_end) {
						flag = true;
						break;
					}
				}
				if (flag)continue;
			}

			int a_begin = ai - size1;
			int a_end = ai + size1;
			int b_begin = bj - size2;
			int b_end = bj + size2;
			if ((a_begin <= bi && bi <= a_end) && (b_begin <= aj && aj <= b_end)) {
				continue;
			}
			a_begin = aj - size1;
			a_end = aj + size1;
			b_begin = bi - size2;
			b_end = bi + size2;
			if ((a_begin <= bj && bj <= a_end) && (b_begin <= ai && ai <= b_end)) {
				continue;
			}

			int MAX_TMP = CAL(size1) * CAL(size2);
			if (MAX_TMP > MAX) {
				MAX = MAX_TMP;
			}
		}
	}

	return MAX;
}

int main() {
	int MAX = 1;
	memset(SIZE, -1, sizeof(SIZE));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	int SHOP_CNT = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == '#') {
				SHOP_CNT += 1;
				Set(i, j);
			}
		}
	}
	if (SHOP_CNT == 0) {
		cout << 0 << endl;
	}


	int POS_SIZE = POS.size();


	for (int i = 0; i < POS_SIZE - 1; i++) {
		for (int j = i + 1; j < POS_SIZE; j++) {
			int MAX_TMP = getMax(i, j);
			if (MAX_TMP > MAX)MAX = MAX_TMP;
		}
	}


	cout << MAX << endl;



















	return 0;
}