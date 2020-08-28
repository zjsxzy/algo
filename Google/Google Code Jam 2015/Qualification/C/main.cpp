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
#include <cassert>
#include <climits>
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

int L, X;
string str;
vector<pair<bool, char> > Start, End, Base;
char multiply(char a, char b) {
	if (a == '1') return b;
	if (b == '1') return a;
	if (a == b) return '1';
	if (a == 'i') {
		if (b == 'j') return 'k';
		if (b == 'k') return 'j';
	} else if (a == 'j') {
		if (b == 'i') return 'k';
		if (b == 'k') return 'i';
	} else if (a == 'k') {
		if (b == 'i') return 'j';
		if (b == 'j') return 'i';
	}
	return '#';
}
bool sign(char a, char b) {
	if (a == '1' || b == '1') return 0;
	if (a == b) return 1;
	if ((a == 'i' && b == 'k') || (a == 'j' && b == 'i') || (a == 'k' && b == 'j')) return 1;
	return 0;
}

bool solve() {
	string s = "";
	for (int i = 0; i < min(4, X); i++) {
		s += str;
	}
	if (X > 4) {
		for (int i = 0; i < (X - 4) % 4; i++) {
			s += str;
		}
	}
	pair<bool, char> cur = MP(0, '1');
	bool found_i = false, found_j = false;
	for (int i = 0; i < SZ(s); i++) {
		cur.first = cur.first ^ sign(cur.second, s[i]);
		cur.second = multiply(cur.second, s[i]);
		if (cur.first == 0 && cur.second == 'i') {
			found_i = true;
		}
		if (found_i && cur.first == 0 && cur.second == 'k') {
			found_j = true;
		}
	}
	if (found_i && found_j && cur.first == 1 && cur.second == '1') {
		return true;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> L >> X;
		cin >> str;
		bool ret = solve();
		printf("Case #%d: ", cas);
		puts(ret ? "YES" : "NO");
	}
	return 0;
}

