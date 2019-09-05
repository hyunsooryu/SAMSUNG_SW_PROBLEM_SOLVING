/*
4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2
3 3 1 1 9
1 2 3
4 0 5
6 7 8
1 3 2 2 4 4 1 1 3
3 3 1 1 9
1 2 3
4 0 5
6 7 8
1 3 2 2 4 4 1 1 3
3 3 1 1 9
1 2 3
4 0 5
6 7 8
1 3 2 2 4 4 1 1 3
*/
//#include "pch.h"
#include <iostream>
using namespace std;

//1 2 3 4 동 서 북 남
int di[] = { 0,0,0,-1,1 };
int dj[] = { 0,1,-1,0,0 };
struct dice{
	int left;
	int right;
	int up;
	int down;
	int front;
	int back;
	dice(int l, int r, int u, int d, int f, int b) {
		this->left = l;
		this->right = r;
		this->up = u;
		this->down = d;
		this->front = f;
		this->back = b;
	}
	void MOVE(int n) {
		if (n == 1) {
			goRight();
		}
		else if (n == 2) {
			goLeft();
		}
		else if (n == 3) {
			goBack();
		}
		else {
			goFront();
		}
	}
	void goBack() {
		int tmp = up;
		up = front;
		front = down;
		down = back;
		back = tmp;
	}
	void goFront() {
		int tmp = up;
		up = back;
		back = down;
		down = front;
		front = tmp;
	}
	void goLeft() {
		int tmp = left;
		left = up;
		up = right;
		right = down;
		down = tmp;
	}
	void goRight() {
		int tmp = right;
		right = up;
		up = left;
		left = down;
		down = tmp;
	}
};
int N, M, X, Y, K;
int A[20][20];
bool isNotPossiblePos(int i, int j) {
	return i < 0 || j < 0 || i >= N || j >= M;
}
int main() {
	cin >> N >> M >> X >> Y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	int now_i = X;
	int now_j = Y;
	dice cube(0, 0, 0, 0, 0, 0);
	while (K--) {
		int order;
		cin >> order;
		int ni = now_i + di[order];
		int nj = now_j + dj[order];
		if (isNotPossiblePos(ni, nj))continue;
		now_i = ni;
		now_j = nj;
		cube.MOVE(order);

		if (A[now_i][now_j] == 0) {
			A[now_i][now_j] = cube.down;
		}
		else {
			cube.down = A[now_i][now_j];
			A[now_i][now_j] = 0;
		}
		cout << cube.up << "\n";
	}






	return 0;
}
