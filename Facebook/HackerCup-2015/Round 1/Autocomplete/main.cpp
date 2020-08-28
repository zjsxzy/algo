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

const int MAXN = 10000;
int ret;
struct Trie {
    struct Tnode {
        int next[26];
        int terminate;
    }chd[MAXN * 600];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
    }

    void insert(string s, int id) {
        int p = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!chd[p].next[c]) {
                memset(chd[size].next, 0, sizeof(chd[size].next));
                chd[size].terminate = -1;
                chd[p].next[c] = size++;
            } else cnt++;
            p = chd[p].next[c];
        }
        chd[p].terminate = id;
        ret += min(cnt + 1, (int)s.size());
		// cout << s << " " << min(cnt + 1, (int)s.size()) << endl;
    }
}trie;
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
    int ts;
    scanf("%d", &ts);
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d: ", cas);
        int n;
        scanf("%d", &n);
        trie.init();
        ret = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            trie.insert(s, i);
        }
		printf("%d\n", ret);
    }
	return 0;
}

