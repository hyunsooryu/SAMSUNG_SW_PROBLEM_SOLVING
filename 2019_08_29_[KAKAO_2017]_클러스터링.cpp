#include "pch.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

//JAKAD SIMILARITY
//BASIC = 교집합 원소의 개수 / 합집합 원소의 개수
//EXCEPT 두개 모두 공집합일 경우 1
//다중 집합으로 허용 교집합은 더 작은 개수
//합집합은 더 큰 개수

void Processing(string str, vector<string>& S, set<string>& SET) {
	int S_SIZE = str.size();
	for (int i = 0; i < S_SIZE - 1; i++) {
		string tmp = str.substr(i, 2);
		if (('a' <= tmp[0] && tmp[0] <= 'z') && ('a' <= tmp[1] && tmp[1] <= 'z')){
			cout << tmp << endl;
			S.push_back(tmp);
			SET.insert(tmp);
		}
	}
}

int solution(string str1, string str2) {
	float top = 0;
	float bottom = 0;
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	vector<string> S1;
	vector<string> S2;
	set<string> SET;
	Processing(str1, S1, SET); 
	Processing(str2, S2, SET);
	sort(S1.begin(), S1.end());
	sort(S2.begin(), S2.end());
	if (SET.size() == 0) {
		cout << "공집합 = " << 1 << endl;
		return 1;
	}
	for (set<string>::iterator itor = SET.begin(); itor != SET.end(); ++itor) {
		auto S1_lower = lower_bound(S1.begin(), S1.end(), *itor);
		auto S1_upper = upper_bound(S1.begin(), S1.end(), *itor);
		auto S2_lower = lower_bound(S2.begin(), S2.end(), *itor);
		auto S2_upper = upper_bound(S2.begin(), S2.end(), *itor);
		int S1_SIZE = S1_upper - S1_lower;
		int S2_SIZE = S2_upper - S2_lower;
		int MIN = min(S1_SIZE, S2_SIZE);
		int MAX = max(S1_SIZE, S2_SIZE);
		top += MIN;
		bottom += MAX;
		cout << top << " " << bottom << endl;
	}
	cout << top << " / " << bottom << endl;
	float ans = (top / bottom) * 65536;
	return static_cast<int>(ans);
}

int main() {
	cout << solution("FRANCE", "french") << endl;


	return 0;
}