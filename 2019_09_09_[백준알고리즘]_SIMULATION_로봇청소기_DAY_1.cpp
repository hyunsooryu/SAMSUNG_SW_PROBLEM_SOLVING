//#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//SIMULATION
//북 동 남 서
//0 1 2 3
//4 5 6 7
//

int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };

int N, M;
int MAP[50][50];
bool V[50][50];
bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}
int S, E, DIR;

int go(int i, int j, int now_dir) {
//	cout << "현재 위치 : " << i << " , " << j << endl;
	int ni = 0;
	int nj = 0;
	int tmp_dir = 0;
	bool flag = false;
	for (int k = 1; k <= 4; k++) {
		tmp_dir = (now_dir + 4 - k) % 4;
		ni = di[tmp_dir] + i;
		nj = dj[tmp_dir] + j;
		if (V[ni][nj] || MAP[ni][nj])continue;
		flag = true;
		break;
	}
	int ANS = 0;
	if (flag) {
		V[ni][nj] = true;
		ANS = go(ni, nj, tmp_dir) + 1;
	}

	else {
		int ni = di[(now_dir + 2) % 4] + i;
		int nj = dj[(now_dir + 2) % 4] + j;
		if (!MAP[ni][nj]) {
			ANS = go(ni, nj, now_dir);
		}
	}
	return ANS;
}

int main() {
	cin >> N >> M;
	cin >> S >> E >> DIR;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &MAP[i][j]);
		}
	}
	V[S][E] = true;
	cout << go(S, E, DIR) + 1;
	



	

	





	return 0;
}