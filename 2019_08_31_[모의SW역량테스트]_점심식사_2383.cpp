//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

//계단은 반드시 2개

//사람은 1 ~ 10이하

//계단의 길이 2 ~ 10이하

int N;
int V1;
int V2;

int getDistance(pair<int,int> a, pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}


//int MAP[10][10];
int main() {
	int test_case = 1;
	int test_case_end = 1;
	cin >> test_case_end;
	while (test_case <= test_case_end) {
		int ANS = -1;
		cin >> N;
		vector<pair<int, int>> PERSON_POS;
		vector<pair<int, int>> STAIR_POS;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int x;
				cin >> x;
				if (x == 1) {
					PERSON_POS.push_back(make_pair(i, j));
				}
				else if (x > 1) {
					STAIR_POS.push_back(make_pair(i, j));
					if (STAIR_POS.size() == 1) {
						V1 = x;
					}
					else {
						V2 = x;
					}
				}
			}
		}
		int PERSON_SIZE = PERSON_POS.size();
	
		int S = 0;
		int E = 1 << PERSON_SIZE;
		while (S < E) {
			vector<int> STAIR_0;
			vector<int> STAIR_1;
			for (int pos = 0; pos < PERSON_SIZE; pos++) {
				if (S & (1 << pos))STAIR_0.push_back(pos);
				else			   STAIR_1.push_back(pos);
			}
			int LANDING_CNT = PERSON_SIZE;
			vector<int> LANDING_CNT_0_AT(102);
			vector<int> LANDING_CNT_1_AT(102);
			for (auto pos : STAIR_0) {
				int ARRIVE_TIME = getDistance(PERSON_POS[pos], STAIR_POS[0]);
				LANDING_CNT_0_AT[ARRIVE_TIME + 1] += 1;
			//	cout << ARRIVE_TIME << endl;
			}
			for (auto pos : STAIR_1) {
				int ARRIVE_TIME = getDistance(PERSON_POS[pos], STAIR_POS[1]);
				LANDING_CNT_1_AT[ARRIVE_TIME + 1] += 1;
			//	cout << ARRIVE_TIME << endl;
			}
//			cout << " NOW_S : " << S << endl;
			//SIMULATION //*****
			int now_time = 1;
			queue<pair<int,int>> Q_0;
			int ELEVATOR_0_NOW = 0;
			queue<pair<int,int>> Q_1;
			int ELEVATOR_1_NOW = 0;
			int WAIT_0 = 0;
			int WAIT_1 = 0;
			while (true) {
			//	cout << now_time << " && LANDING_CNT : " << LANDING_CNT << endl;
				//LANDING
				while (!Q_0.empty() && Q_0.front().first == now_time) {
					int land_cnt = Q_0.front().second;
					ELEVATOR_0_NOW -= land_cnt; Q_0.pop();
					LANDING_CNT -= land_cnt;
				}
				while (!Q_1.empty() && Q_1.front().first == now_time) {
					int land_cnt = Q_1.front().second;
					ELEVATOR_1_NOW -= land_cnt; Q_1.pop();
					LANDING_CNT -= land_cnt;
				}

				if (LANDING_CNT == 0)break; //종료조건

				//TAKING
				if (LANDING_CNT_0_AT[now_time] > 0) {
		//			cout << "NOW_TIME : " << now_time << " ~ CNT : " << LANDING_CNT_0_AT[now_time] << endl;
					WAIT_0 += LANDING_CNT_0_AT[now_time];
					
					
				}
				if (LANDING_CNT_1_AT[now_time] > 0) {
		//			cout << "NOW_TIME : " << now_time << " ~ CNT : " << LANDING_CNT_1_AT[now_time] << endl;
					WAIT_1 += LANDING_CNT_1_AT[now_time];
				}
				
				if (ELEVATOR_0_NOW < 3) {
					int possible_cnt = 3 - ELEVATOR_0_NOW;
					if (WAIT_0 >= possible_cnt) {
						Q_0.push(make_pair(now_time + V1, possible_cnt));
						WAIT_0 -= possible_cnt;
						ELEVATOR_0_NOW = 3;
					}
					else {
						Q_0.push(make_pair(now_time + V1, WAIT_0));
						ELEVATOR_0_NOW += WAIT_0;
						WAIT_0 = 0;
					}
				}
				if (ELEVATOR_1_NOW < 3) {
					int possible_cnt = 3 - ELEVATOR_1_NOW;
					if (WAIT_1 >= possible_cnt) {
						Q_1.push(make_pair(now_time + V2, possible_cnt));
						WAIT_1 -= possible_cnt;
						ELEVATOR_1_NOW = 3;
					}
					else {
						Q_1.push(make_pair(now_time + V2, WAIT_1));
						ELEVATOR_1_NOW += WAIT_1;
						WAIT_1 = 0;
					}
				}

				now_time += 1;
			}
		//	cout << "TOTAL_COST_TIME : " << now_time << endl;
			if (ANS == -1 || now_time < ANS) {
				ANS = now_time;
			}
			S += 1;
		}







		cout << "#" << test_case << " " <<  ANS << "\n";
		test_case += 1;
	}











	return 0;
}