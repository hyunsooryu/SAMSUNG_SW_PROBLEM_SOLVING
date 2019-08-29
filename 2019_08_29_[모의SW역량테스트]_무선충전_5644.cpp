//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int di[] = { 0,-1,0,1,0 };
int dj[] = { 0,0,1,0,-1 };
struct batteryCenter{
	int power;
	int range;
	int i;
	int j;
	batteryCenter(int i = 0, int j = 0, int range = 0, int power = 0) {
		this->i = i;
		this->j = j;
		this->range = range;
		this->power = power;
	}
};

bool isPossiblePos(int i, int j, batteryCenter bc) {
	return abs(i - bc.i) + abs(j - bc.j) <= bc.range;
}
vector<batteryCenter> BC_FEATURES;


int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int ans = 0;
		int N, M;
		cin >> N >> M;
		vector<vector<int>> PERSON(2, vector<int>(N + 1));
		BC_FEATURES.resize(M);
		for (int p = 0; p < 2; p++) {
			for (int i = 1; i <= N; i++) {
				scanf("%d", &PERSON[p][i]);
			}
		}
		for (int i = 0; i < M; i++) {
			int x, y, range, power;
			scanf("%d %d %d %d", &y, &x, &range, &power);
			BC_FEATURES[i] = batteryCenter(x - 1, y - 1, range, power);
		}
		int p1_i = 0; int p1_j = 0;
		int p2_i = 9; int p2_j = 9;
		for (int t = 0; t < N + 1; t++) {
			p1_i += di[PERSON[0][t]];
			p1_j += dj[PERSON[0][t]];
			p2_i += di[PERSON[1][t]];
			p2_j += dj[PERSON[1][t]];
			//MOVING

			vector<int> POSSIBLE_POS_FOR_1;
			vector<int> POSSIBLE_POS_FOR_2;
			for (int i = 0; i < M; i++) {
				if (isPossiblePos(p1_i, p1_j, BC_FEATURES[i])) {
					POSSIBLE_POS_FOR_1.push_back(i);
				}
				if (isPossiblePos(p2_i, p2_j, BC_FEATURES[i])) {
					POSSIBLE_POS_FOR_2.push_back(i);
				}
			}

			sort(POSSIBLE_POS_FOR_1.begin(), POSSIBLE_POS_FOR_1.end(), [](int i, int j) {
				return BC_FEATURES[i].power > BC_FEATURES[j].power;
			});
			sort(POSSIBLE_POS_FOR_2.begin(), POSSIBLE_POS_FOR_2.end(), [](int i, int j) {
				return BC_FEATURES[i].power > BC_FEATURES[j].power;
			});
			
			if (POSSIBLE_POS_FOR_1.empty() && !POSSIBLE_POS_FOR_2.empty()) {
				ans += BC_FEATURES[POSSIBLE_POS_FOR_2[0]].power;
			}
			else if (POSSIBLE_POS_FOR_2.empty() && !POSSIBLE_POS_FOR_1.empty()){
				ans += BC_FEATURES[POSSIBLE_POS_FOR_1[0]].power;
			}
			else if (!POSSIBLE_POS_FOR_1.empty() && !POSSIBLE_POS_FOR_2.empty()) {
				if (POSSIBLE_POS_FOR_1[0] == POSSIBLE_POS_FOR_2[0]) {
					int size1 = POSSIBLE_POS_FOR_1.size();
					int size2 = POSSIBLE_POS_FOR_2.size();
					if (size1 == size2 && size2 == 1) {
						ans += BC_FEATURES[POSSIBLE_POS_FOR_1[0]].power;
					}
					else if (size1 > 1 && size2 == 1) {
						ans += BC_FEATURES[POSSIBLE_POS_FOR_1[1]].power + BC_FEATURES[POSSIBLE_POS_FOR_2[0]].power;
					}
					else if (size1 == 1 && size2 > 1) {
						ans += BC_FEATURES[POSSIBLE_POS_FOR_1[0]].power + BC_FEATURES[POSSIBLE_POS_FOR_2[1]].power;
					}
					else {
						ans += BC_FEATURES[POSSIBLE_POS_FOR_1[0]].power + max(BC_FEATURES[POSSIBLE_POS_FOR_1[1]].power, BC_FEATURES[POSSIBLE_POS_FOR_2[1]].power);
					}
				}
				else {
					ans += BC_FEATURES[POSSIBLE_POS_FOR_1[0]].power + BC_FEATURES[POSSIBLE_POS_FOR_2[0]].power;
				}
			}
		//	cout << t << " : " << ans << endl;
		}
		cout << "#" << tc << " " << ans << "\n";
	}








	return 0;
}