#include <iostream>
using namespace std;
int A[9];
int TMP[9];
bool V[9];
int go(int index) {
	if (index == 9) {
		bool flag = false;
		int tmp_sum = TMP[0] + TMP[1] + TMP[2];
		int tmp_sum_1 = TMP[0] + TMP[4] + TMP[8];
		int tmp_sum_2 = TMP[2] + TMP[4] + TMP[6];
		if (tmp_sum_1 != tmp_sum || tmp_sum_2 != tmp_sum)return -1;
		for (int k = 0; k < 3; k++) {
			tmp_sum_1 = TMP[k * 3] + TMP[k * 3 + 1] + TMP[k * 3 + 2];
			tmp_sum_2 = TMP[k] + TMP[k + 3] + TMP[k + 6];
			if (tmp_sum_1 != tmp_sum || tmp_sum_2 != tmp_sum) {
				flag = true;
				break;
			}
		}
		if (flag)return - 1;
	//	cout << "I AM MAGIC NUMBER " << endl;
		int MIN = 0;
		for (int k = 0; k < 9; k++) {
			int diff = A[k] - TMP[k];
			if (diff < 0) diff = -diff;
			MIN += diff;
		}
	//	cout << "MIN : " << MIN << endl;
		return MIN;
	}
	int ANS_MIN = -1;
	for (int k = 0; k < 9; k++) {
		if (V[k])continue;
		V[k] = true;
		TMP[index] = k + 1;
		int ANS = go(index + 1);
		if (ANS_MIN == -1 || (0 <= ANS && ANS < ANS_MIN)) ANS_MIN = ANS;
		V[k] = false;
	}
	return ANS_MIN;
}

int main() {
	for (int k = 0; k < 9; k++) {
		cin >> A[k];
	}
	cout << go(0) << endl;


	return 0;
}