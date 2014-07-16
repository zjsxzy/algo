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
struct Trie {
    struct Tnode {
        int next[26];
        int terminate;
		int cnt;
    }chd[MAXN * 600];
    int size;

    void init() {
        size = 1;
        memset(chd[0].next, 0, sizeof(chd[0].next));
        chd[0].terminate = -1;
		chd[0].cnt = 0;
    }

    void insert(char *s, int id) {
        int p = 0;
        for (int i = 0; s[i]; i++) {
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

    int find(char *s) {
        int p = 0;
        for (int i = 0; s[i]; i++) {
            int c = s[i] - 'a';
            if (chd[p].next[c]) {
                p = chd[p].next[c];
            } else return 0;
        }
		return chd[p].cnt;
    }
}trie;

int main() {
	int n, m;
	scanf("%d", &n);
	trie.init();
	for (int i = 0; i < n; i++) {
		char str[15];
		scanf("%s", str);
		trie.insert(str, i);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char str[15];
		scanf("%s", str);
		int tot = trie.find(str);
		printf("%d\n", tot);
	}
	return 0;
}

