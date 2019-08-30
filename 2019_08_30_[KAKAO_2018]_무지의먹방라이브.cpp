//#include "pch.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//pair<int,int> A first : num , second : index
bool cmp1(pair<int,int> a, pair<int,int> b){
	return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

vector<int> food_times;
    
int solution(vector<int> food_times, long long K) {
	int CNT = food_times.size();
	vector<pair<int, int>> FOOD_TIME(CNT);
	for (int i = 0; i < CNT; i++) {
		FOOD_TIME[i].first = food_times[i];
		FOOD_TIME[i].second = i + 1;
	}
	sort(FOOD_TIME.begin(), FOOD_TIME.end(), cmp1);
	sort(food_times.begin(), food_times.end());
	int pos = 0;
	long long numerate_value = 0;
	while (pos < CNT) {
		long long MIN = FOOD_TIME[pos].first;
		auto UPPER = upper_bound(food_times.begin(), food_times.end(), MIN);
		auto LOWER = lower_bound(food_times.begin(), food_times.end(), MIN);
		MIN -= numerate_value;
	//	cout << "MIN : " << MIN << endl;
		int MIN_CNT = UPPER - LOWER;
	//	cout << "MIN_CNT : " << MIN_CNT << endl;
		if (MIN * (CNT - pos) <= K) {
			K = K - MIN * (CNT - pos);
			numerate_value += MIN;
		}
		else {
			break;
		}
		pos += MIN_CNT;
	}

	if (K == 0) {
	//	cout << "IAM HERE~" << endl;
	//	cout << "POS : " << pos << endl;
		if (pos >= CNT) {
			return -1;
		}
		else {
			sort(FOOD_TIME.begin() + pos, FOOD_TIME.end(), cmp2);
			return (*(FOOD_TIME.begin() + pos)).second;
		}
	}
	if (CNT - pos == 0)return -1;
	sort(FOOD_TIME.begin() + pos, FOOD_TIME.end(), cmp2);
	return (*(FOOD_TIME.begin() + pos + K % (CNT - pos))).second;
}

int main() {
	vector<int> tmp = {3,5,5,7};
	cout << solution(tmp, 20) << endl;
	
	
	
	return 0;
}