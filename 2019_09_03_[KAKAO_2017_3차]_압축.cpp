//#include "pch.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> DIC;

void INIT() {
	int index = 1;
	for (char c = 'A'; c <= 'Z'; c++) {
		string a;
		a += c;
		DIC[a] = index;
		index += 1;
	}
}

vector<int> solution(string target) {
	INIT();
	vector<int> ANS;
	int now_index = 0;
	int SEC_INDEX = 27;
	int max_searcn = 1;
	int E = target.length();

	while (now_index < E) {
	//	cout << "NOW_INDEX : " << now_index << endl;
		int start = now_index;
		int end = start + max_searcn - 1;
		if (end >= E) {
			end = E - 1;
		}
		for (int tmp_index = end; tmp_index >= start; tmp_index--) {
			if (DIC[target.substr(start, tmp_index - start + 1)] != 0) {
		//		cout << "SEC_INDEX : " << SEC_INDEX << endl;
		//		cout << "SEC_FINDED!!" << endl;
		//		cout << target.substr(start, tmp_index - start + 1) << endl;
		//		cout << DIC[target.substr(start, tmp_index - start + 1)] << endl;
		//		cout << "NOW TMP_INDEX + 1 : " << " ";
				now_index += (tmp_index - start + 1);
	//			cout << now_index << "!!!!" << endl;
				ANS.push_back(DIC[target.substr(start, tmp_index - start + 1)]);
		//		cout << tmp_index + 1 << endl;
				if (tmp_index + 1 < E) {
		//			cout << "NEW_SEC" << endl;
		//			cout << target.substr(start, tmp_index + 1 - start + 1) << endl;
					if (DIC[target.substr(start, tmp_index + 1 - start + 1)] == 0) {
						DIC[target.substr(start, tmp_index + 1 - start + 1)] = SEC_INDEX++;
					}
					max_searcn = max(max_searcn, tmp_index + 1 - start + 1);
					break;
				}
				else {
					break;
				}
			}
		}
		/*
		cout << endl;
		cout << endl;
		for (auto k : ANS) {
			cout << k << " ";
		}cout << endl;
		*/
	}
	return ANS;
}

int main() {
	vector<int> ANS = solution("THATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITISTHATTHATISISTHATTHATISNOTISNOTISTHATITITIS");
	int tmp = 1;
	for (int index : ANS) {
		cout << index << " ";
		if (tmp % 10 == 0)cout << endl;
		tmp += 1;
	}


	return 0;
}