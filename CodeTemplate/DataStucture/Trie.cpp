struct Trie {
    struct Tnode {
        int next[26];
        int terminate;
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
                chd[p].next[c] = size++;
            }
            p = chd[p].next[c];
        }
        chd[p].terminate = id;
    }

    void find(string& s, int id) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (chd[p].next[c]) {
                p = chd[p].next[c];
                if (chd[p].terminate != -1) {
					/*
					 * do something
					 */
                }
            } else return;
        }
    }
}trie;
