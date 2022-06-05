#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL inf = 1ll << 60;
LL f_min(LL a, LL b){
  return min(a, b);
}
LL f_max(LL a, LL b){
  return max(a, b);
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T query(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return E;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
		}
	}
	T query(int L, int R){
		return query(L, R, 0, 0, N);
	}
};

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), s(n + 1);
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    vector<int> left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) {
        left[i] = i - 1;
        while (left[i] >= 1 && a[left[i]] <= a[i]) {
            left[i] = left[left[i]];
        }
    }
    for (int i = n; i >= 1; i--) {
        right[i] = i + 1;
        while (right[i] <= n && a[right[i]] <= a[i]) {
            right[i] = right[right[i]];
        }
    }
    segment_tree<LL> stmin(s, f_min, inf);
    segment_tree<LL> stmax(s, f_max, -inf);
    for (int i = 1; i <= n; i++) {
        LL r = stmax.query(i, right[i]);
        LL l = stmin.query(left[i], i);
        // cout << i << " " << a[i] << ' ' << left[i] << ' ' << right[i] << ' ' << r - l << endl;
        if (a[i] < r - l) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}
