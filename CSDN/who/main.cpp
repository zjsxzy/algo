#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

map<string, int> dp;

bool check(string word) {
	bool res = true;
	for (int i = 0; i < word.size() - 1; i++)
		res &= (word[i] < word[i + 1]);
	return res;
}

bool dfs(string word) {
	if (dp.find(word) != dp.end()) {
		return dp[word];
	}
	if (word.size() == 1) {
		return dp[word] = false;
	}
	if (check(word)) {
		return dp[word] = false;
	}
	bool res = true;
	string temp = word;
	for (int i = 0; i < word.size(); i++) {
		temp.erase(temp.begin() + i);
		res &= dfs(temp);
		temp = word;
	}
	return dp[word] = (!res);
}

int who(string word) {
	return dfs(word) ? 1 : 0;
}

int main() {
	cout << who("bad") << endl;
	/*
	FOREACH(it, dp) {
		cout << it->first << " " << it->second << endl;
	}
	*/
	cout << who("aaa") << endl;
	return 0;
}

