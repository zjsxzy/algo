// 左闭右开区间
namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
}  // namespace atcoder
using namespace atcoder;
int op(int a, int b) {
    return max(a, b);
}
int e() {
    return 0;
}
segtree<int, op, e> tree(m);

// lazysegtree
namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal


template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder
using namespace atcoder;
// 维护区间和
struct S {
    LL sum, len;
};
S op(S l, S r) {
    return {l.sum + r.sum, l.len + r.len};
}
S e() {
    return {0, 0};
}
using F = LL;
S mapping(F f, S x) {
    return {x.sum + f * x.len, x.len};
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}

// example 1
void solve() {
    int n, m;
    cin >> n >> m;
    vector<S> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // read value of position x
        a.push_back({x, 1});
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            x--; y--;
            // range [x, y] add k
            seg.apply(x, y + 1, k);
        } else {
            int x, y;
            cin >> x >> y;
            x--; y--;
            // ask sum of range [x, y]
            cout << seg.prod(x, y + 1).sum << endl;
        }
    }
}


// SSRS's segment tree template
// 左闭右开区间，E是默认值
int f(int a, int b) {
  return max(a, b);
}
template <typename T>
struct segment_tree {
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E) {
		int n = A.size();
		N = 1;
		while (N < n) {
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
		for (int i = 0; i < n; i++) {
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--) {
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T query(int L, int R, int i, int l, int r) {
		if (R <= l || r <= L) {
			return E;
		} else if (L <= l && r <= R) {
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
		}
	}
	T query(int L, int R) {
		return query(L, R, 0, 0, N);
	}
};
segment_tree<int> tree(n, f, 0);

// 左闭右开区间，A是每个节点的乘数, 更新时区间[l,r)的值都更新为A[i]*k
// 如区间为[1,2,3,4,5]，初始时线段树维护区间值为[0,0,0,0,0]，更新位置range_update(1,3,2)，则维护的区间更新为[0,4,6,0,0]
// 若要是更新值为值本身，另初始的A为全1的数组即可
template <typename T>
struct lazy_segment_tree {
    int N;
    vector<T> sum, ST, lazy;
    lazy_segment_tree(vector<T> &A) {
        int N2 = A.size();
        N = 1;
        while (N < N2) {
            N *= 2;
        }
        sum = vector<T>(N * 2 - 1, 0);
        for (int i = 0; i < N2; i++) {
            sum[N - 1 + i] = A[i];
        }
        for (int i = N - 2; i >= 0; i--) {
            sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
        }
        ST = vector<T>(N * 2 - 1, 0);
        lazy = vector<T>(N * 2 - 1, -1);
    }
    void eval(int i) {
        if (lazy[i] != -1) {
            if (i < N - 1) {
                lazy[i * 2 + 1] = lazy[i];
                lazy[i * 2 + 2] = lazy[i];
            }
            ST[i] = sum[i] * lazy[i];
            lazy[i] = -1;
        }
    }
    void range_update(int L, int R, T x, int i, int l, int r) {
        eval(i);
        if (r <= L || R <= l) {
            return;
        } else if (L <= l && r <= R) {
            lazy[i] = x;
            eval(i);
        } else {
            int m = (l + r) / 2;
            range_update(L, R, x, i * 2 + 1, l, m);
            range_update(L, R, x, i * 2 + 2, m, r);
            ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
        }
    }
    void range_update(int L, int R, T x) {
        range_update(L, R, x, 0, 0, N);
    }
    T range_sum(int L, int R, int i, int l, int r) {
        eval(i);
        if (r <= L || R <= l) {
            return 0;
        } else if (L <= l && r <= R) {
            return ST[i];
        } else {
            int m = (l + r) / 2;
            return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
        }
    }
    T range_sum(int L, int R) {
        return range_sum(L, R, 0, 0, N);
    }
};

const int MAXN = 100005;
const int inf = 1e9;
int n;
int a[MAXN];
struct SegTree {
	int mx[MAXN << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushUp(int rt) {
		mx[rt] = max(mx[lson(rt)], mx[rson(rt)]);
	}
	void build(int l, int r, int rt) {
		if (l == r) {
			mx[rt] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}
	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return mx[rt];
		}
		int mid = (l + r) >> 1;
		int res = -inf;
		if (L <= mid) res = max(res, query(L, R, l, mid, lson(rt)));
		if (mid < R) res = max(res, query(L, R, mid + 1, r, rson(rt)));
		return res;
	}
    void update(int p, int val, int l, int r, int rt) {
        if (l == r) {
            mx[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) update(p, val, l, mid, lson(rt));
        else update(p, val, mid + 1, r, rson(rt));
        pushUp(rt);
    }
}tree;

// 既有增加操作也有设置操作的线段
const int MAXN = 100000 + 5;
int val[MAXN];
struct SegTree {

	int sum[MAXN << 2], add[MAXN << 2], put[MAXN << 2];

	int lson(int rt) {
		return rt << 1;
	}

	int rson(int rt) {
		return rt << 1 | 1;
	}

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void pushDown(int rt, int m) {
		if (m == 1) return;
		if (put[rt] != -1) {
			put[lson(rt)] = put[rt];
			put[rson(rt)] = put[rt];
			add[lson(rt)] = 0;
			add[rson(rt)] = 0;
			sum[lson(rt)] = put[rt] * (m - (m >> 1));
			sum[rson(rt)] = put[rt] * (m >> 1);
			put[rt] = -1;
		}
		if (add[rt] != 0) {
			add[lson(rt)] += add[rt];
			add[rson(rt)] += add[rt];
			sum[lson(rt)] += add[rt] * (m - (m >> 1));
			sum[rson(rt)] += add[rt] * (m >> 1);
			add[rt] = 0;
		}
	}

	void build(int l, int r, int rt) {
		add[rt] = 0;
		put[rt] = -1;
		sum[rt] = 0;
		if (l == r) {
			sum[rt] = val[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	void updateAdd(int L, int R, int c, int l, int r, int rt) {
		pushDown(rt, r - l + 1);
		if (L <= l && r <= R) {
			add[rt] += c;
			sum[rt] += c * (r - l + 1);
			return;
		}
		int mid = (l + r) >> 1;
		if (L <= mid) updateAdd(L, R, c, l, mid, lson(rt));
		if (R > mid) updateAdd(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}

	void updateSet(int L, int R, int c, int l, int r, int rt) {
		pushDown(rt, r - l + 1);
		if (L <= l && r <= R) {
			put[rt] = c;
			sum[rt] = c * (r - l + 1);
			return;
		}
		int mid = (l + r) >> 1;
		if (L <= mid) updateSet(L, R, c, l, mid, lson(rt));
		if (R > mid) updateSet(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}

	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		int res = 0;
		if (L <= mid) res += query(L, R, l, mid, lson(rt));
		if (mid < R) res += query(L, R, mid + 1, r, rson(rt));
		return res;
	}

}tree;
