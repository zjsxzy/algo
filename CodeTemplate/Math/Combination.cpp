const int MAXN = 33;
int comb[MAXN][MAXN];

void init(int n) {
    memset(comb, 0, sizeof(comb));
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

