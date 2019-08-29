#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

struct cache {
	int CAPACITY;
	int cost;
	list<string> MEMORY;
	cache(int CAPACITY = 0){
		this->CAPACITY = CAPACITY;
		cost = 0;
	}
	bool isEmpty() {
		return MEMORY.empty();
	}
	bool isFull() {
		return MEMORY.size() == CAPACITY;
	}
	bool HIT(string target) {
		if (isEmpty())return false;
		auto itor = MEMORY.begin();
		while (itor != MEMORY.end()) {
			if ((*itor) == target)return true;
			itor++;
		}
		return false;
	}
	void insert(string tmp) {
		if (HIT(tmp)) {
			cost += 1;
			MEMORY.remove(tmp);
			MEMORY.push_front(tmp);
		}
		else {
			cost += 5;
			if (isFull()) {
				MEMORY.push_front(tmp);
				MEMORY.pop_back();
			}
			else {
				MEMORY.push_front(tmp);
			}
		}
	}
};

int solution(int cacheSize, vector<string> cities) {
	cache CACHE(cacheSize);
	for (string city : cities) {
		transform(city.begin(), city.end(), city.begin(), ::tolower);
		CACHE.insert(city);
	}
	return CACHE.cost;
}