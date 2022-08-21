int ELFhash(string& s) {
    int h = 0, x = 0;
    for (int i = 0; i < s.size(); i++) {
        h = (h << 4) + s[i];
        if ((x = h & 0xF0000000L) != 0) {
            h ^= (x >> 24);
        }
        h &= ~x;
    }
    return h;
}

// s是回文串，求s的最短回文子串t使得s+t仍然为回文串
// 用hash函数快速判断hash(s)是否等于hash(reverse(s))
void solve(int n, string s) {
    LL base = 131, mod = 1000000007;
    LL Left = 0, Right = 0, Mul = 1;
    for (int i = 0; i < n; i++) {
        Left = (Left * base + s[i]) % mod;
        Mul = Mul * base % mod;
    }
    Right = Left;
    LL left = 0, right = 0, mul = 1;
    int best = -1;
    for (int i = n - 1; i >= 0; i--) {
        left = (left * base + s[i]) % mod;
        right = (right + mul * s[i]) % mod;

        Left = (Left * base + s[i]) % mod;
        Right = (Right + Mul * s[i]) % mod;

        if (left == right && Left == Right) {
            best = i;
            break;
        }
        Mul = Mul * base % mod;
        mul = mul * base % mod;
    }
    string add = s.substr(best, n - best);
    cout << add << endl;
}
