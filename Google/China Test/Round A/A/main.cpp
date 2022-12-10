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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

string charout(char ch) {
	if (ch == '0') return "zero";
	if (ch == '1') return "one";
	if (ch == '2') return "two";
	if (ch == '3') return "three";
	if (ch == '4') return "four";
	if (ch == '5') return "five";
	if (ch == '6') return "six";
	if (ch == '7') return "seven";
	if (ch == '8') return "eight";
	if (ch == '9') return "nine";
}
void print(char ch, int tot) {
	if (tot == 1) {
		cout << " " << charout(ch);
		return;
	}
	if (tot == 2) {
		cout << " double " << charout(ch);
		return;
	}
	if (tot == 3) {
		cout << " triple " << charout(ch);
		return;
	}
	if (tot == 4) {
		cout << " quadruple " << charout(ch);
		return;
	}
	if (tot == 5) {
		cout << " quintuple " << charout(ch);
		return;
	}
	if (tot == 6) {
		cout << " sextuple " << charout(ch);
		return;
	}
	if (tot == 7) {
		cout << " septuple " << charout(ch);
		return;
	}
	if (tot == 8) {
		cout << " octuple " << charout(ch);
		return;
	}
	if (tot == 9) {
		cout << " nonuple " << charout(ch);
		return;
	}
	if (tot == 10) {
		cout << " decuple " << charout(ch);
		return;
	}
	for (int i = 0; i < tot; i++) {
		cout << " " << charout(ch);
	}
}

void output(string in) {
	char now = in[0];
	int tot = 1;
	for (int i = 1; i < in.size(); i++) {
		if (in[i] != now) {
			print(now, tot);
			now = in[i];
			tot = 1;
		} else {
			tot++;
		}
	}
	if (tot != 0) {
		print(now, tot);
	}
}
int main() {
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d:", cas);
		string num, format;
		cin >> num >> format;
		vector<int> f;
		for (int i = 0; i < format.size(); i++) {
			if ('0' <= format[i] && format[i] <= '9') {
				int t = format[i] - '0';
				int j;
				for (j = i + 1; j < format.size(); j++) {
					if (j < format.size() && '0' <= format[j] && format[j] <= '9') {
						t = t * 10 + format[j] - '0';
					} else break;
				}
				i = j;
				f.PB(t);
			}
		}
		int now = 0;
		for (int i = 0; i < f.size(); i++) {
			string read = num.substr(now, f[i]);
			now += f[i];
			output(read);
		}
		puts("");
	}
	return 0;
}
