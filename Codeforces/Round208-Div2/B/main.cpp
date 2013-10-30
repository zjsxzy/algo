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

int main() {
	int n;
	cin >> n;
	string code, text;
	code = "<3";
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		code += word;
		code += "<3";
	}
	cin >> text;
	int i = 0, j = 0;
	for (; i < code.size() && j < text.size(); ) {
		if (code[i] == text[j]) {
			i++, j++;
		} else {
			j++;
		}
	}
	if (i == code.size()) {
		puts("yes");
	} else {
		puts("no");
	}
	return 0;
}
