#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> str(n);
    for (auto& s: str) {
        cin >> s;
    }

    vector<bool> vst(n);
    map<char, string> single;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < str[i].size() - 1; j++) {
            if (str[i][j] != str[i][j + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            vst[i] = 1;
            single[str[i][0]] += str[i];
        }
    }

    vector<int> next(n, -1), prev(n, -1);
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        for (int j = 0; j < n; j++) {
            if (vst[j]) continue;
            if (i == j) continue;
            if (str[i][str[i].size() - 1] == str[j][0]) {
                next[i] = j;
                prev[j] = i;
            }
        }
    }

    string res;
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        if (prev[i] == -1) {
            string s = str[i];
            char c = s[0];
            s = single[c] + s; single[c] = "";
            c = s[s.size() - 1];
            s += single[c]; single[c] = "";
            vst[i] = true;
            int j = next[i];
            while (j != -1 && !vst[j]) {
                vst[j] = true;
                s += str[j];
                c = s[s.size() - 1];
                s += single[c];
                single[c] = "";
                j = next[j];
            }
            res += s;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vst[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for (auto& [k, v]: single) {
        res += v;
    }
    map<char, bool> mp;
    mp[res[0]] = true;
    for (int i = 1; i < res.size(); i++) {
        if (res[i] != res[i - 1] && mp[res[i]]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        } else {
            mp[res[i]] = true;
        }
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        printf("Case #%d: ", cs);
        solve();
    }
    return 0;
}

