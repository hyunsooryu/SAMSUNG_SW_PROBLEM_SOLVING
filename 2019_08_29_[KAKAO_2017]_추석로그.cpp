#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//PRE_PROCESSING
//int

int CHECK[86500];
void STR_TO_INT_TIME(string str, vector<int>& START, vector<int>& END) {
	int S_SIZE = str.size();
	string DD = str.substr(0, 10);
	string HH;
	string MM;
	int s = 11;
	int cnt = 0;
	string tmp = str.substr(11, S_SIZE - 10);
	HH = tmp.substr(0, 12);
	tmp = tmp.substr(13, tmp.size() - 12);
	MM = tmp;
	cout << DD << " --- " << HH << " --- " << MM << endl;
	/*
	*/
	int milimin = 0;
	int second_to_mili = stoi(MM.substr(0, 1));
	int mili_to_mili = 0;
	second_to_mili *= 1000;
	string tmp_mili;
	int index = 1;
	while (true) {
		if (MM[index] == 's') {
			break;
		}
		else if (MM[index] != '.') {
			tmp_mili.push_back(MM[index]);
		}
		index += 1;
	}
	if (tmp_mili.size() > 0) {
		mili_to_mili = stoi(tmp_mili);
	}
	cout << second_to_mili << " " << mili_to_mili << endl;
	milimin += (second_to_mili + mili_to_mili);

	int log_period = 0;
	int log_mili_to_mili = stoi(HH.substr(9, 3));
	int log_seco_to_mili = stoi(HH.substr(6, 2)) * 1000;
	int log_minu_to_mili = stoi(HH.substr(3, 2)) * 60 * 1000;
	int log_hour_to_mili = stoi(HH.substr(0, 2)) * 3600 * 1000;
	cout << log_mili_to_mili << endl;
	cout << log_seco_to_mili << endl;
	cout << log_minu_to_mili << endl;
	cout << log_hour_to_mili << endl;
	log_period = log_mili_to_mili + log_seco_to_mili + log_minu_to_mili + log_hour_to_mili;
	cout << "FINAL : " << log_period << endl;
	cout << log_period << endl;
	int start = log_period - milimin + 1;
	int end = log_period;
	START.push_back(start);
	END.push_back(end);
}


//1시간 = 60분 = 3600초 = 3600000 밀리초 
//1초 = 1000밀리초
//1분 = 1000밀리초 * 60




int main() {

	vector<string> tmp = { "2016-09-15 20:59:57.421 0.351s",
		"2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s" };

	vector<int> START;
	vector<int> END;
for (auto k : tmp) {
	STR_TO_INT_TIME(k, START, END);
}
/*
int MAX = 0;
int E = tmp.size();
for (auto s : START) {
	for (int i = 0; i < E; i++) {
		int TMP_START = S
	}
}



*/


	return 0;
}