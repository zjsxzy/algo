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

const int MAXN = 105;
map<int, int> inv;
int mp[15];
int n;
string numStr[15];
int s[MAXN], t[MAXN];

int strToInt(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') ret |= (1 << i);
	}
	return ret;
}

string intToStr(pair<int, int> x) {
	int num = x.first, mask = x.second;
	if (num == -1) return "ERROR!";
	string ret = numStr[num];
	for (int i = 0; i < 7; i++) {
		if ((mask & (1 << i)) && ret[i] == '1') {
			ret[i] = '0';
		}
	}
	return ret;
}

pair<int, int> solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s[i] = strToInt(str);
	}
	vector<pair<int, int> > ret;
	for (int mask = 0; mask < (1 << 7); mask++) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (s[i] & mask) {
				flag = false;
				break;
			}
			t[i] = s[i] | mask;
		}
		if (!flag) continue;
		for (int st = 0; st <= 9; st++) {
			int cur = st;
			flag = true;
			for (int i = 0; i <= n && flag; i++) {
				if (i == n) {
					ret.PB(MP(cur, mask));
				} else {
					int state = mp[cur];
					for (int j = 0; j < 7; j++) {
						if ((state & (1 << j)) && !(t[i] & (1 << j))) {
							flag = false; break;
						}
						if (!(state & (1 << j)) && (s[i] & (1 << j))) {
							flag = false; break;
						}
					}
					cur--;
					if (cur == -1) cur = 9;
				}
			}
		}
	}
	if (ret.size() == 0 || ret.size() > 1) return MP(-1, -1);
	else return ret[0];
}

void init() {
	mp[0] = strToInt("1111110"); numStr[0] = "1111110";
	mp[1] = strToInt("0110000"); numStr[1] = "0110000";
	mp[2] = strToInt("1101101"); numStr[2] = "1101101";
	mp[3] = strToInt("1111001"); numStr[3] = "1111001";
	mp[4] = strToInt("0110011"); numStr[4] = "0110011";
	mp[5] = strToInt("1011011"); numStr[5] = "1011011";
	mp[6] = strToInt("1011111"); numStr[6] = "1011111";
	mp[7] = strToInt("1110000"); numStr[7] = "1110000";
	mp[8] = strToInt("1111111"); numStr[8] = "1111111";
	mp[9] = strToInt("1111011"); numStr[9] = "1111011";
	for (int i = 0; i <= 9; i++) {
		inv[mp[i]] = i;
	}
}

int main() {
	int ts;
	scanf("%d", &ts);
	init();
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		pair<int, int> res = solve();
		cout << intToStr(res) << endl;
	}
	return 0;
}

