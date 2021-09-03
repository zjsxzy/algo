/*
ID: frankzh1
TASK: lgame
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 40005;
int value[27] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
string dword[maxn];
int dict[maxn][30];
int vword[maxn];
int n;

void solve() {
	string word;
	cin >> word;
	vector<int> cnt(26);
	for (auto &c: word) {
		cnt[c - 'a']++;
	}

	int res = 0;
	vector<int> valid;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int c = 0; c < 26; c++) {
			if (dict[i][c] > cnt[c]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			valid.emplace_back(i);
			res = max(res, vword[i]);
		}
	}
	int m = valid.size();
	set<pair<int, int>> valid_pair;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			bool flag = true;
			for (int c = 0; c < 26; c++) {
				if (dict[valid[i]][c] + dict[valid[j]][c] > cnt[c]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				valid_pair.insert({i, j});
				res = max(res, vword[valid[i]] + vword[valid[j]]);
			}
		}
	}

	cout << res << endl;
	for (int i = 0; i < m; i++) {
		if (vword[valid[i]] == res) cout << dword[valid[i]] << endl;
		for (int j = i + 1; j < m; j++) {
			if (vword[valid[i]] + vword[valid[j]] == res && valid_pair.find({i, j}) != valid_pair.end()) {
				cout << dword[valid[i]] << " " << dword[valid[j]] << endl;
			}
		}
	}
}

int main() {
	freopen("lgame.dict", "r", stdin);
	string s;
	int i = 0;
	while (cin >> s) {
		if (s == ".") break;
		dword[i] = s;
		int score = 0;
		for (auto &c: s) {
			dict[i][c - 'a']++;
			score += value[c - 'a'];
		}
		vword[i] = score;
		i++;
	}
	n = i;
	freopen("lgame.in", "r", stdin);
	freopen("lgame.out", "w", stdout);
    solve();
    return 0;
}

