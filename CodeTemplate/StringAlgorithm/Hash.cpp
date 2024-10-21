const int M = 1e9 + 7;
const int B = 2333;

// 多次区间查询s[l..r]是否回文
void Hash(string& s) {
    int n = s.size();
    bs.resize(n + 1); hash.resize(n + 1); rhash.resize(n + 1);
    bs[0] = 1;
    for (int i = 1; i <= n; i++) {
        bs[i] = bs[i - 1] * B;
    }
    for (int i = 0; i < n; i++) {
        // 构建字符串哈希值
        hash[i + 1] = hash[i] * B + s[i];
        // 构建逆序串哈希值
        rhash[i + 1] = rhash[i] * B + s[n - i - 1];
    }
}
// 查询区间seq[l..r]是否回文
// 判断原串哈希值hash[l..r]与逆序串哈希值rhash[n-r+1..n-l+1]是否相等
bool query(int l, int r) {
    int n = seq.size();
    // 从[0..n-1]改为[1..r]
    l++, r++;
    mint A = hash[r] - hash[l - 1] * bs[r - l + 1];
    int L = n - r + 1, R = n - l + 1;
    mint B = rhash[R] - rhash[L - 1] * bs[R - L + 1];
    return A == B;
}

long long MOD = 1e9 + 7;
long long BASE = 2333;

struct HashSeq {
    vector<__int128> P, H;

    HashSeq(string &s) {
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1;
        for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % MOD;
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
    }

    long long query(int l, int r) {
        return (H[r] - H[l - 1] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};

// 多次访问子串 sum[l..r]=sum[r]-sum[l-1]*B^(r-l+1)
vector<LL> get_hash(string s) {
    int n = s.size();
    vector<LL> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = (LL)(sum[i] * B + s[i]) % M;
    }
    return sum;
}

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
