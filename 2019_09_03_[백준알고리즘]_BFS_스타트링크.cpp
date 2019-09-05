//#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int V[1000001];
bool isOut(int n) {
	return n < 1 || n > F;
}

void BFS(int F, int S, int G, int U, int D) {
	queue<int> Q;
	V[S] = 0;
	Q.push(S);
	while (!Q.empty()) {
		int tmp = Q.front(); Q.pop();
		int u_predict = tmp + U;
		int d_predict = tmp - D;
		if (!isOut(u_predict) && V[u_predict] == 0) {
			V[u_predict] = V[tmp] + 1;
			Q.push(u_predict);
		}
		if (!isOut(d_predict) && V[d_predict] == 0) {
			V[d_predict] = V[tmp] + 1;
			Q.push(d_predict);
		}
	}
	if (V[G] == 0) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << V[G] << endl;
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	BFS(F, S, G, U, D);

	return 0;
}