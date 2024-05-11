#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 300005;
struct Trie {
    struct Tnode {
        int next[26];
        int terminate;
        int cnt;
    }chd[MAXN];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
    }

    void insert(string& s, int id) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!chd[p].next[c]) {
                memset(chd[size].next, 0, sizeof(chd[size].next));
                chd[size].terminate = -1;
                chd[size].cnt = 0;
                chd[p].next[c] = size++;
            }
            p = chd[p].next[c];
            chd[p].cnt++;
        }
        chd[p].terminate = id;
    }

    LL remove(string& s, int id) {
        int p = 0;
        LL res = 0;
        // cout << s << endl;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (chd[p].next[c]) {
                p = chd[p].next[c];
                // cout << p << ' ' << chd[p].cnt << endl;
                chd[p].cnt--;
                res += chd[p].cnt;
            } else break;
        }
        return res;
    }
}trie;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    trie.init();
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        trie.insert(s[i], i);
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int t = trie.remove(s[i], i);
        // cout << s[i] << ' ' << t << endl;
        res += t;
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}