//#include "pch.h"
#include <iostream>
#include <tuple>
#include <map>
#include <queue>

using namespace std;

//2차원을 저장하고 싶을떄!!!!

/*
그동안에는 map<pair<int,int>> MAP 을 사용해서 문제를 해결했다면, 이제 드디어 해결 방법을 찾았습니다.
map<int,map<int,int>> 를 사용해서 문제를 해결해주겠습니다.
*/
map<int, map<int, int>> D;

int S;
int main() {
	cin >> S;
	queue<pair<int, int>> Q;
	D[1][0] = 1;

	Q.push(make_pair(1, 0));

	while (!Q.empty()) {
		int SCREEN;
		int CLIP;
		tie(SCREEN, CLIP) = Q.front(); Q.pop();
		if (SCREEN == S) {
			cout << D[SCREEN][CLIP] - 1 << "\n";
			break;
		}

		if (SCREEN > 0 && D[SCREEN][SCREEN] == 0) {
			//	cout << "HI1~" << endl;
			D[SCREEN][SCREEN] = D[SCREEN][CLIP] + 1;
			Q.push(make_pair(SCREEN, SCREEN));
		}

		if (CLIP > 0 && D[SCREEN + CLIP][CLIP] == 0) {
			//	cout << "HI2~" << endl;
			D[SCREEN + CLIP][CLIP] = D[SCREEN][CLIP] + 1;
			Q.push(make_pair(SCREEN + CLIP, CLIP));
		}

		if (SCREEN > 0 && D[SCREEN - 1][CLIP] == 0) {
			//	cout << "HI3~" << endl;
			D[SCREEN - 1][CLIP] = D[SCREEN][CLIP] + 1;
			Q.push(make_pair(SCREEN - 1, CLIP));
		}
	}








	return 0;
}