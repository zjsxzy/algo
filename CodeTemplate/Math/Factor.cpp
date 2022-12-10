// 计算质因子
void get_prime_factor(int m) {
    vector<vector<int>> fac(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = i * 2; j <= m; j += i) {
            fac[j].push_back(i);
        }
    }
}
