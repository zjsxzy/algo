/*
ID: frankzh1
TASK: frameup
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int h, w;
struct Point {
	int upx, downx, upy, downy;
}corner[26];
bool vis[26];
vector<string> ans, frame;
int cnt;

bool valid(int index) {
    char top = 'A' + index;
	for (int i = corner[index].upx; i <= corner[index].downx; i++) {
		if (frame[i][corner[index].upy] != top && frame[i][corner[index].upy] != '.') return false;
		if (frame[i][corner[index].downy] != top && frame[i][corner[index].downy] != '.') return false;
	}
	for (int j = corner[index].upy; j <= corner[index].downy; j++) {
		if (frame[corner[index].upx][j] != top && frame[corner[index].upx][j] != '.') return false;
		if (frame[corner[index].downx][j] != top && frame[corner[index].downx][j] != '.') return false;
	}
	return true;
}

void dfs(string str) {
    if (str.size() == cnt) {
        reverse(str.begin(), str.end());
        ans.PB(str);
    }
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) continue;
        if (!valid(i)) continue;
        vis[i] = false;
        vector<string> temp = frame;
		for (int k = corner[i].upx; k <= corner[i].downx; k++) {
		    frame[k][corner[i].upy] = '.';
			frame[k][corner[i].downy] = '.';
		}
		for (int j = corner[i].upy; j <= corner[i].downy; j++) {
			frame[corner[i].upx][j] = '.';
			frame[corner[i].downx][j] = '.';
		}
		dfs(str + (char)('A' + i));
        /*
		for (int k = corner[i].upx; k <= corner[i].downx; k++) {
			frame[k][corner[i].upy] = (char)('A' + i);
			frame[k][corner[i].downy] = (char)('A' + i);
		}
		for (int j = corner[i].upy; j <= corner[i].downy; j++) {
			frame[corner[i].upx][j] = (char)('A' + i);
			frame[corner[i].downx][j] = (char)('A' + i);
		}
        */
        frame = temp;
        vis[i] = true;
    }
}

void solve() {
    cin >> h >> w;
    frame.resize(h);
    for (auto &s: frame) {
        cin >> s;
    }
    cnt = 0;
    for (int i = 0; i < h; i++) {
	    for (int j = 0; j < w; j++) {
		    int k = frame[i][j] - 'A';
			if (k >= 0) {
				if (!vis[k]) {
                    cnt++;
					vis[k] = true;
					corner[k].upx = corner[k].downx = i;
					corner[k].upy = corner[k].downy = j;
				} else {
				    if (i < corner[k].upx)
						corner[k].upx = i;
					if (i > corner[k].downx)
						corner[k].downx = i;
					if (j < corner[k].upy)
						corner[k].upy = j;
					if (j > corner[k].downy)
						corner[k].downy = j;
				}
			}
		}
	}
    dfs("");
	sort(ans.begin(), ans.end());
    for (auto &s: ans) {
        cout << s << endl;
    }
}

int main() {
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);
    solve();
    return 0;
}

