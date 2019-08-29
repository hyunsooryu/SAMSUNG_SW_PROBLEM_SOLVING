//#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int calculator(string str) {
	int total = 0;
	int prev = 0;
	int pos = 0;
	int s_size = str.length();
	while (true) {
		if (pos >= s_size) {
			break;
		}
		int now = 0;
		if (str[pos] == '1') {
			now = 1;
			if (str[pos + 1] == '0') {
				now = 10;
				pos += 1;
			}
		}
		else {
			now = str[pos] - '0';
		}
		pos += 1;
		if (str[pos] == 'D') {
			now = now * now;
		}
		else if (str[pos] == 'T') {
			now = now * now * now;
		}
		if (pos + 1 < s_size && (str[pos + 1] == '*' || str[pos + 1] == '#')) {
			if (str[pos + 1] == '*') {
				now *= 2;
				if (prev < 0) {
					total += -prev;
				}
				else {
					total -= prev;
				}
				total += (prev * 2);
				total += now;
			}
			else {
				now *= -1;
				total += now;
			}
			pos += 1;
		}
		else {
			total += now;
		}
		prev = now;
		pos += 1;
	}
	return total;
}

int solution(string dartResult) {
	int answer = 0;
	return calculator(dartResult);
}



int main() {
	cout << calculator("1D2S3T*") << endl;





	return 0;
}