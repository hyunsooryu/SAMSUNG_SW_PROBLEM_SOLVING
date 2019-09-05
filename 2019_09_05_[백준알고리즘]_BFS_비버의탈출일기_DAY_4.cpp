//#include "pch.h"
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
char MAP[51][51];
int D[51][51];
int N, M;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };


/*
    더블 큐를 이용한 문제 풀이
    하나 하나씩 BFS를 하고 시간차로 해결하는 것을 적용해도 좋습니다.
*/



bool isOut(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}

//WATER_FIRST

//POINT_SECOND



int ei, ej;
queue<pair<int, int>> WATER;
queue<pair<int, int>> BIBER;
int main() {
	memset(D, -1, sizeof(D));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 'S') {
				D[i][j] = 0;
				BIBER.push(make_pair(i, j));
			}
			else if (MAP[i][j] == 'D') {
				ei = i;
				ej = j;
			}
			else if (MAP[i][j] == '*') {
				WATER.push(make_pair(i, j));
			}
		}
	}
	int TIME = 1;
	//Simulation(){
	while (true) {
		queue<pair<int, int>> PRE_WATER;
		queue<pair<int, int>> PRE_BIBER;
		
		while (!WATER.empty()) {
			int i, j;
			tie(i, j) = WATER.front(); WATER.pop();
			
			for (int k = 0; k < 4; k++) {
				int ni = di[k] + i;
				int nj = dj[k] + j;
				if (isOut(ni, nj))continue;
				if (MAP[ni][nj] == '.' || MAP[ni][nj] == 'S') {
					MAP[ni][nj] = '*';
					PRE_WATER.push(make_pair(ni, nj));
				}
			}
		}

		while (!BIBER.empty()) {
			int i, j;
			tie(i, j) = BIBER.front(); BIBER.pop();
			for (int k = 0; k < 4; k++) {
				int ni = di[k] + i;
				int nj = dj[k] + j;
				if (isOut(ni, nj))continue;
				if (D[ni][nj] != -1 || MAP[ni][nj] == '*' || MAP[ni][nj] == 'X')continue;
				D[ni][nj] = D[i][j] + 1;
				PRE_BIBER.push(make_pair(ni, nj));
			}
		}

		WATER = PRE_WATER;
		BIBER = PRE_BIBER;
		
		if (BIBER.empty()) {
			break;
		}/*
		cout << "TIME : ";
		cout << TIME++ << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (MAP[i][j] == 'X') {
					cout << "X ";
				}
				else if (MAP[i][j] == '*') {
					cout << "* ";
				}
				else if (MAP[i][j] == '.' && D[i][j] == -1) {
					cout << ". ";
				}
				else if (MAP[i][j] == 'D' && D[i][j] == -1) {
					cout << "D ";
				}
				else if (D[i][j] != -1) {
					cout << "S ";
				}
			}
			cout << endl;
		}
		cout << endl;
		*/
	}

	

	if (D[ei][ej] < 0) {
		cout << "KAKTUS\n";
	}
	else {
		cout << D[ei][ej] << "\n";
	}
	

	return 0;
}