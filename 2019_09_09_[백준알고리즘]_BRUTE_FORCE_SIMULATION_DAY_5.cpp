#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M, LIMIT;
int MAP[15][15];
bool DEAD[15][15];
int main() {
	cin >> N >> M >> LIMIT;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	int MAX_SCORE = 0;
	for (int j1 = 0; j1 < M - 2; j1++) {
		for (int j2 = j1 + 1; j2 < M - 1; j2++) {
			for (int j3 = j2 + 1; j3 < M; j3++) {
				int SCORE = 0;
				vector<int> ARROW = { j1, j2, j3 };
			//	cout << "NOW_J : " << ARROW[0] << " " << ARROW[1] << " " << ARROW[2] << endl;
				memset(DEAD, false, sizeof(DEAD));
				for (int i = N; i >= 1; i--) {
					vector<int> POS_I = { -1,-1,-1 };
					vector<int> POS_J = { -1,-1,-1 };
					for (int pos = 0; pos < 3; pos++) {
						int now_i = i;
						int now_j = ARROW[pos];
						int tmp_dist = -1;
						int tmp_j = -1;
						for (int k = 0; k < i; k++) {
							for (int t = 0; t < M; t++) {
								if (MAP[k][t] == 1 && !DEAD[k][t]) {
									int trying_dist = abs(now_i - k) + abs(now_j - t);
									if (trying_dist > LIMIT)continue;

									if (tmp_dist == -1 || trying_dist < tmp_dist) {
										POS_I[pos] = k;
										POS_J[pos] = t;
										tmp_dist = trying_dist;
										tmp_j = t;
									}
									else if (trying_dist == tmp_dist && t < tmp_j) {
										POS_I[pos] = k;
										POS_J[pos] = t;
									}
								}
							}
						}
						
					}
					for (int index = 0; index < 3; index++) {
						if (POS_I[index] == -1 || POS_J[index] == -1)continue;
						if (DEAD[POS_I[index]][POS_J[index]])continue;
						DEAD[POS_I[index]][POS_J[index]] = true;
						SCORE += 1;
					}
				}
				if (SCORE > MAX_SCORE)MAX_SCORE = SCORE;
			}
		}
	}

	cout << MAX_SCORE << endl;
	










	return 0;
}