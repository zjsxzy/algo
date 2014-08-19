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

vector<string> a, b, c;

char toupper(char c) {
	return (char)(c - 32);
}

char tolower(char c) {
	return (char)(c + 32);
}

void output(string s, bool flag) {
	int t = 0;
	string ans;
	string a, b, c;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ' && !t) continue;
		if (s[i] == '{') {
			t = 1;
		} else if (s[i] == '(') {
			t = 2;
		} else if (s[i] == '[') {
			t = 3;
		} else if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
			t = 0;
		} else {
			if (t == 1) a += s[i];
			if (t == 2) b += s[i];
			if (t == 3) c += s[i];
		}
	}
	if (flag) a[0] = toupper(a[0]);
	cout << a << " " << b << " " << c;
}

int main() {
	string s;
	getline(cin, s);
	int i;
	for (i = 0; i < s.size(); i++)
		if ('A' <= s[i] && s[i] <= 'Z')
			s[i] = tolower(s[i]);
	for (i = 0; i < s.size(); i++)
		if (s[i] == ',') break;
	if (i == s.size()) output(s, true);
	else {
		string s1;
		int j;
		for (j = 0; j < i; j++)
			s1 += s[j];
		string mid;
		for (j = i; j < s.size(); j++)
			if (s[j] == '{' || s[j] == '[' || s[j] == '(') break;
			else mid += s[j];
		string s2;
		for (; j < s.size(); j++)
			s2 += s[j];
		output(s1, true); cout << mid; output(s2, false);
	}
	cout << endl;
	return 0;
}
