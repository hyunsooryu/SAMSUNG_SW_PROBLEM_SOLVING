#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int N;
int A[10][10];
int V[10][10][3][102];

int li[] = { -1,1,0,0 };
int lj[] = { 0,0,-1,1 };

int bi[] = { -1,-1,1,1 };
int bj[] = { -1,1,-1,1 };

int ki[] = { 2,2,-2,-2,-1,-1,1,1 };
int kj[] = { 1,-1,1,-1,2,-2,2,-2 };

bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= N;
}
int si, sj;
int ANS = -1;
int main() {
	memset(V, -1, sizeof(V));
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 1) {
				si = i; sj = j;
			}
		}
	}

	queue<tuple<int, int, int, int>> Q;
	for (int id = 0; id < 3; id++) {
		V[si][sj][id][1] = 0;
		Q.push(make_tuple(si, sj, id, 1));
	}
	while (!Q.empty()) {
		int i, j, id, now_num;
		tie(i, j, id, now_num) = Q.front(); Q.pop();

		//cout << i << ", " << j << ", " << id << ", " << now_num << endl;

		if (now_num == N * N) {
			if (ANS == -1 || V[i][j][id][now_num] < ANS) {
				ANS = V[i][j][id][now_num];
			}
			continue;
		}

		for (int k = 0; k < 3; k++) {
			if (id == k)continue;
			if (V[i][j][k][now_num] == -1) {
				V[i][j][k][now_num] = V[i][j][id][now_num] + 1;
				Q.push(make_tuple(i, j, k, now_num));
			}
		}


		if (id == 0) {
			for (int k = 0; k < 4; k++) {
				int ni = li[k] + i; int nj = lj[k] + j;
				while (true) {
					if (isNotPossiblePos(ni, nj)) {
						break;
					}
					int next_num = now_num;
					if (A[ni][nj] == now_num + 1) {
						next_num = now_num + 1;
					}
					if (V[ni][nj][id][next_num] == -1) {
						V[ni][nj][id][next_num] = V[i][j][id][now_num] + 1;
						Q.push(make_tuple(ni, nj, id, next_num));
					}
					ni += li[k];
					nj += lj[k];
				}
			}
		}


		if (id == 1) {
			for (int k = 0; k < 4; k++) {
				int ni = bi[k] + i; int nj = bj[k] + j;
				while (true) {
					if (isNotPossiblePos(ni, nj)) {
						break;
					}
					int next_num = now_num;
					if (A[ni][nj] == now_num + 1) {
						next_num = now_num + 1;
					}
					if (V[ni][nj][id][next_num] == -1) {
						V[ni][nj][id][next_num] = V[i][j][id][now_num] + 1;
						Q.push(make_tuple(ni, nj, id, next_num));
					}
					ni += bi[k];
					nj += bj[k];
				}
			}
		}

		if (id == 2) {
			for (int k = 0; k < 8; k++) {
				int ni = ki[k] + i;
				int nj = kj[k] + j;
				if (isNotPossiblePos(ni, nj))continue;
				int next_num = now_num;
				if (A[ni][nj] == now_num + 1) {
					next_num = now_num + 1;
				}
				if (V[ni][nj][id][next_num] == -1) {
					V[ni][nj][id][next_num] = V[i][j][id][now_num] + 1;
					Q.push(make_tuple(ni, nj, id, next_num));
				}
			}
		}
	}




	cout << ANS << endl;








	return 0;
}