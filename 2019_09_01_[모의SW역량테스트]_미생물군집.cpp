//#include "pch.h"
#include <iostream>
#include <vector>

struct CELL {
	int i;
	int j;
	int cnt;
	int dir;
	bool dead;
	CELL(int i = 0, int j = 0, int cnt = 0, int dir = 0) {
		this->i = i;
		this->j = j;
		this->cnt = cnt;
		this->dir = dir;
		dead = false;
	}
};

using namespace std;
int di[] = { 0,-1,1,0,0 };
int dj[] = { 0,0,0,-1,1 };
int MAP[100][100];
int SUM[100][100];
int N, M, K;

bool isInRed(int x, int y) {
	return x == 0 || y == 0 || x == N - 1 || y == N - 1;
}

int main() {
	int T;
	scanf_s("%d", &T);
	memset(MAP, -1, sizeof(MAP));
	for (int testcase = 1; testcase <= T; ++testcase) {
		cin >> N >> M >> K;
		vector<int> CELL_ALIVE(K);
		vector<CELL> CELLS(K);
		for (int i = 0; i < K; i++) {
			int x, y, cnt, dir;
			scanf_s("%d %d %d %d", &x, &y, &cnt, &dir);
			CELLS[i] = CELL(x, y, cnt, dir);
			CELL_ALIVE[i] = i;
		}

		//SIMULATION(){
		while (M--) {
			vector<int> NEW_CELL_ALIVE;
			for (int index : CELL_ALIVE) {
				int now_dir = CELLS[index].dir;
				int now_cnt = CELLS[index].cnt;
				int ni = CELLS[index].i + di[now_dir];
				int nj = CELLS[index].j + dj[now_dir];
				CELLS[index].i = ni;
				CELLS[index].j = nj;
				//no way to be OUTSIDE;
				if (isInRed(ni, nj)) {
					MAP[ni][nj] = index;
					now_cnt /= 2;
					CELLS[index].cnt = now_cnt;
					if (now_dir < 3) {
						CELLS[index].dir = 3 - now_dir;
					}
					else {
						CELLS[index].dir = 7 - now_dir;
					}
					if (now_cnt == 0) {
						CELLS[index].dead = true;
						SUM[ni][nj] = 0;
						MAP[ni][nj] = -1;
						continue;
					}
					SUM[ni][nj] += now_cnt;
				}
				else {
					SUM[ni][nj] += now_cnt;
					if (MAP[ni][nj] == -1) {
						MAP[ni][nj] = index;
					}
					else {
						int enemy = MAP[ni][nj];
						if (CELLS[enemy].cnt < CELLS[index].cnt) {
							MAP[ni][nj] = index;
							CELLS[enemy].dead = true;
						}
						else {
							CELLS[index].dead = true;
						}
					}
				}	
			}
			/*
			cout << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (MAP[i][j] == -1) {
						cout << ". ";
					}
					else {
						cout << MAP[i][j] << " ";
					}
				}
				cout << endl;
			}
			cout << endl;
			*/
			for (int index : CELL_ALIVE) {
				if (CELLS[index].dead == true)continue;
				int now_i = CELLS[index].i;
				int now_j = CELLS[index].j;
				MAP[now_i][now_j] = -1;
				CELLS[index].cnt = SUM[now_i][now_j];
				SUM[now_i][now_j] = 0;
				NEW_CELL_ALIVE.push_back(index);
			}
			CELL_ALIVE = NEW_CELL_ALIVE;
		}
		int ANS = 0;

		for (int index : CELL_ALIVE) {
			ANS += CELLS[index].cnt;
		}

		cout << "#" << testcase << " " << ANS << "\n";
	}








	return 0;
}