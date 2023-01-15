template <typename T>
struct Binary_Indexed_Tree {
    vector<T> bit;
    const int n;

    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()) {
        bit.resize(n + 1);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    Binary_Indexed_Tree(int n, const T &x) : n(n) {
        bit.resize(n + 1);
        vector<T> v(n, x);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    void add(int i, const T &x) {
        for (i++; i <= n; i += (i & -i)) bit[i] += x;
    }

    void change(int i, const T &x) { add(i, x - query(i, i + 1)); }

    T sum(int i) const {
        T ret = 0;
        for (; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }

    T query(int l, int r) const { return sum(r) - sum(l); }

    T operator[](int i) const { return query(i, i + 1); }

    int lower_bound(T x) const { // v[0]+...+v[r] >= x
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] < x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }

    int upper_bound(T x) const { // v[0]+...+v[r] > x
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] <= x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }
};

/*
 * One dimension Binary Index Tree. Notice that the array is C[1], C[2], ..., C[N]
 */
const int maxn = 1000005;
struct BinaryIndexTree {
	int N;
	int C[maxn];

	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}

	int lowbit(int x) {
		return x & (-x);
	}

	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}

	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit;

// 2-d
const int MAXN = 500 + 10;
int T , N , M;
int C[MAXN][MAXN];

int lowbit(int x) {
	return x & (-x);
}

int sum(int x , int y) {
	int ans = 0;
	for (int i = x ; i <= N ; i += lowbit(i))
	for (int j = y ; j <= N ; j += lowbit(j))
		ans += C[i][j];
	return ans;
}

void add(int x , int y , int num) {
	for (int i = x ; i > 0 ; i -= lowbit(i))
	for (int j = y ; j > 0 ; j -= lowbit(j))
		C[i][j] += num;
}
