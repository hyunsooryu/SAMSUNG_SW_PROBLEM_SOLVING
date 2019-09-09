//https://programmers.co.kr/learn/courses/30/lessons/17686

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isNum(char e) {
	return '0' <= e && e <= '9';
}
// F-15KGB
// 01234567
struct file {
	string head;
	string original;
	int num;
	string tail;
	int index;
	file(string target = "", int index = 0) {
		this->original = target;
		this->tail = "";
		this->index = index;
		setVariable(target);
	}
	void setVariable(string target) {
		int pos = 0;
		int length = target.length();
		while (pos < length) {
			if (isNum(target[pos])) {
				this->head = target.substr(0, pos);
				int tmp_pos = pos;
				while (tmp_pos < length && isNum(target[tmp_pos])) {
					tmp_pos += 1;
				}
				this->num = stoi(target.substr(pos, tmp_pos - pos));
				if (tmp_pos < length) {
					this->tail = target.substr(tmp_pos, length - tmp_pos);
				}
				break;
			}
			pos += 1;
		}
	}
};


bool cmp(file a, file b) {
	string tmp1 = a.head;
	string tmp2 = b.head;
	transform(tmp1.begin(), tmp1.end(), tmp1.begin(), ::toupper);
	transform(tmp2.begin(), tmp2.end(), tmp2.begin(), ::toupper);
	if (tmp1 != tmp2) {
		return tmp1 < tmp2;
	}
	else if ((tmp1 == tmp2) && (a.num != b.num)) {
		return a.num < b.num;
	}
	return a.index < b.index;
}

vector<string> solution(vector<string> files) {
	int file_size = files.size();
	vector<string> answer(file_size);
	vector<file> FILE(file_size);
	for (int i = 0; i < file_size; i++) {
		FILE[i] = file(files[i], i);
	}
	sort(FILE.begin(), FILE.end(), cmp);
	for (int i = 0; i < file_size; i++) {
		answer[i] = FILE[i].original;
	}
	return answer;
}

