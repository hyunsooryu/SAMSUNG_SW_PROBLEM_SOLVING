//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
1. DP로 해결했다. 

2. DP를 재귀적으로 구현할 떄 주의할 점. return을 해줄때, 즉 HIT / NO HIT를 따질 때

   배열의 인덱스가 더 크다면, 문제가 되기 때문에 

   HIT 처리를 해줄 D 배열을 더 크게만들던지, 아니면, day == N 일때의 조건을 더 빨리 처리해 준다.


*/

int N; // DAY
int D[20];
int COST[15];
int PAY[15];

int go(int day) {
	//cout << day << endl;
	//DP HIT
	


	if (D[day] != -1) {
	//	cout << "HIT" << endl;
		return D[day];
	}

	if (day == N)return 0; //이걸 먼저 쓰는이유. day가 N일 때 배열값이없어서 아니면 배열을 더크게
	
	//return condition
	
	//choosing case 
	int tmp1 = 0;
	//:case 1 // include N
	if (day + COST[day] - 1 < N) {
		tmp1 = go(day + COST[day]) + PAY[day];
	}
	//:case 2 // Not include N
	int tmp2 = go(day + 1);
	return D[day] = max(tmp1, tmp2);
}

int main() {
	cin >> N;
	memset(D, -1, sizeof(D));
	for (int i = 0; i < N; i++) {
		cin >> COST[i] >> PAY[i];
	}
	
	cout << go(0);






	return 0;
}