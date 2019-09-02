//#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Searching2X3(int x, int y, vector<vector<int>> board) {
	if (board[x][y] == 0)return false;
	int black_cnt = 0;
	int etc_cnt = 0;
	int etc = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[x + i][y + j] == -1) {
				black_cnt += 1;
			}
			else if(board[x + i][y + j] == 0){
				return false;
			}
			else {
				if (etc == 0) {
					etc = board[x + i][y + j];
					etc_cnt += 1;
				}
				else {
					if (board[x + i][y + j] != etc) {
						return false;
					}
					else {
						etc_cnt += 1;
					}
				}
			}
		}
	}
	return etc_cnt == 4 && black_cnt == 2;
}

void reSetBlack(vector<vector<int>>& board, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == -1) {
				board[i][j] = 0;
			}
		}
	}
}

bool Searching3X2(int x, int y, vector<vector<int>> board) {
	if (board[x][y] == 0)return false;
	int black_cnt = 0;
	int etc_cnt = 0;
	int etc = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (board[x + i][y + j] == -1) {
				black_cnt += 1;
			}
			else if (board[x + i][y + j] == 0) {
				return false;
			}
			else {
				if (etc == 0) {
					etc = board[x + i][y + j];
					etc_cnt += 1;
				}
				else {
					if (board[x + i][y + j] != etc) {
						return false;
					}
					else {
						etc_cnt += 1;
					}
				}
			}
		}
	}
	return etc_cnt == 4 && black_cnt == 2;
}
/*
void display(vector<vector<int>> boards) {
	cout << "\n";
	for (auto board : boards) {
		for (int i : board) {
			if (i < 0) {
				cout << "x ";
			}
			else {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}
*/


bool SetBlack(vector<vector<int>>& board,int N) {
	bool flag = false;
	for (int j = 0; j < N; j++) {
		if (board[0][j] == 0) {
			flag = true;
			board[0][j] = -1;
		}
	}
	if (!flag)return false;
	for (int i = 0; i < N - 1; i++) {
		bool flag = false;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == -1 && board[i + 1][j] == 0) {
				board[i][j] = 0;
				board[i + 1][j] = -1;
				flag = true;
			}
		}
		if (!flag)break;
	}

	//display(board);
	return true;
}

void REMOVE(int s, int e, bool button, vector<vector<int>>& board) {
	if (button) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				board[s + i][e + j] = 0;
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				board[s + i][e + j] = 0;
			}
		}
	}
}
/*
vector<vector<int>> board = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 4, 0, 0, 0},{0, 0, 0, 0, 0, 4, 4, 0, 0, 0},{0, 0, 0, 0, 3, 0, 4, 0, 0, 0},{0, 0, 0, 2, 3, 0, 0, 0, 5, 5},{1, 2, 2, 2, 3, 3, 0, 0, 0, 5},{1, 1, 1, 0, 0, 0, 0, 0, 0, 5}};
*/
bool isNotPossblePos(int x, int y, int N) {
	return x < 0 || y < 0 || x >= N || y >= N;
}
int Destroy(vector<vector<int>>& board, int N) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isNotPossblePos(i + 1, j + 2, N)) {
				if (Searching2X3(i, j, board)) {
			//		cout << "2 X 3 !! : ";
			//		cout << i << " " << j << endl;
					cnt += 1;
					REMOVE(i, j, true, board);
				}
			}
			if (!isNotPossblePos(i + 2, j + 1, N)) {
				if (Searching3X2(i, j, board)) {
			//		cout << "3 X 2 !! : ";
			//		cout << i << " " << j << endl;
					cnt += 1;
					REMOVE(i, j, false, board);
				}
			}
		}
	}
	return cnt;
}


int solution(vector<vector<int>> board) {
	int ans = 0;
	int N = board.size();
	//int C = 1;
	while (true) {
		/*
		cout << C << "차시 :::::::::" << endl;
		cout << endl;
		*/
		int answer = 0;
		bool result = SetBlack(board, N);
		if (!result)break;
		/*
		cout << "검은 비 생성 완료 : " << endl;
		cout << endl;
		*/
		answer += Destroy(board, N);
		/*
		cout << "파괴 완료 : " << endl;
		cout << endl;
		display(board);
		cout << endl;
		*/
		ans += answer;
		if (answer > 0) {
			reSetBlack(board, N);
		//	cout << "RESET 완료 : " << endl;
		}
	//	display(board);
		
		//cout << "NOW_ANS : " << answer << endl;
		//cout << endl;
	//	C += 1;
	}
	return ans;
}