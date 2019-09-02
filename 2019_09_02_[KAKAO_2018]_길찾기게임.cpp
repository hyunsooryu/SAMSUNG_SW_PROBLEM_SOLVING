#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
//vector<vector<int>> POSES = {{5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2}};
vector<vector<int>> POSES;
int LEFT[100001];
int RIGHT[100001];
int LEVEL[100001];
struct TREE {
	int TREE_ROOT;
	vector<int> A;
	vector<int> B;
	TREE() {
		TREE_ROOT = -1;
	}

	void PREORDER(int ROOT) {
		A.push_back(ROOT);
		if (LEFT[ROOT] != 0) {
			PREORDER(LEFT[ROOT]);
		}
		if (RIGHT[ROOT] != 0) {
			PREORDER(RIGHT[ROOT]);
		}
	}

	void POSTORDER(int ROOT) {
		if (LEFT[ROOT] != 0) {
			POSTORDER(LEFT[ROOT]);
		}
		if (RIGHT[ROOT] != 0) {
			POSTORDER(RIGHT[ROOT]);
		}
		B.push_back(ROOT);
	}

	void INSERT(int N, int ROOT) {
		//cout << "RECURSIVE : " << N << " , " << ROOT << endl;
		if (TREE_ROOT == -1) {
			TREE_ROOT = N;
			return;
		}
		else {
			if (LEVEL[N] == LEVEL[ROOT] + 1) {
			//	cout << "부모님 레벨에 도착했습니다. " << endl;
			//	cout << POSES[N - 1][0] << " VS " << POSES[ROOT - 1][0];
				if (POSES[N - 1][0] < POSES[ROOT - 1][0]) {
			//		cout << "부모님의 X값보다 작기 때문에, 부모님의 왼쪽 자식이 됩니다." << endl;
					LEFT[ROOT] = N;
				}
				else {
			//		cout << "부모님의 X값보다 작기 때문에, 부모님의 오른쪽 자식이 됩니다." << endl;
					RIGHT[ROOT] = N;
				}
			}
			else {
			//	cout << POSES[N - 1][0] << " VS " << POSES[ROOT - 1][0];
			//	cout << "아직 레벨이 부모님이 아닙니다." << LEVEL[N] << " VS " << LEVEL[ROOT] + 1 << endl;
				if (POSES[N - 1][0] < POSES[ROOT - 1][0]) {
			//		cout << "왼쪽으로 찾아갑니다. " << endl;
					INSERT(N, LEFT[ROOT]);
				}
				else {
			//		cout << "오른쪽으로 찾아갑니다. " << endl;
					INSERT(N, RIGHT[ROOT]);
				}
			}
		}
		return;
	}
};

struct NODE {
	int index;
	vector<int> XY;
	NODE(int index = 0, vector<int> XY = {{0,1}}) {
		this->index = index;
		this->XY = XY;
	}
};

bool CMP(NODE A, NODE B) {
	return (A.XY[1] == B.XY[1] && A.XY[0] < B.XY[0]) || A.XY[1] > B.XY[1];
}


vector<vector<int>> solution(vector<vector<int>> POSEP) {
    POSES = POSEP;
	vector<NODE> NODES;
	int index = 1;
	for (auto POS : POSES) {
		NODES.push_back(NODE(index, POS));
		index += 1;
	}
	sort(NODES.begin(), NODES.end(), CMP);
	/*
	for (auto k : NODES) {
		cout << k.index << " ";
		cout << POSES[k.index - 1][0] << " , " << POSES[k.index - 1][1] << endl;
	}cout << endl;
	cout << endl;
	*/

	TREE A = TREE();

	int NOW_LEVEL = 0;
	int NOW_HEIGHT = NODES[0].XY[1];
	for (auto NODE : NODES) {
		if (NODE.XY[1] == NOW_HEIGHT) {
			LEVEL[NODE.index] = NOW_LEVEL;
		}
		else {
			NOW_LEVEL += 1;
			NOW_HEIGHT = NODE.XY[1];
			LEVEL[NODE.index] = NOW_LEVEL;
		}
		A.INSERT(NODE.index, A.TREE_ROOT);
	}
	/*
	TREE A = TREE();
	for (auto NODE : NODES) {
		A.INSERT(NODE.index, A.TREE_ROOT);
	}
	*/
	A.PREORDER(A.TREE_ROOT);
	A.POSTORDER(A.TREE_ROOT);

	return { A.A, A.B};
}
