#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int f(int a, int b){
  return gcd(a, b);
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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& x: A) cin >> x;
    vector<int> B(N);
    for (auto& x: B) cin >> x;
    vector<int> C(N - 1), D(N - 1);
    for (int i = 0; i < N - 1; i++) {
        C[i] = abs(A[i + 1] - A[i]);
        D[i] = abs(B[i + 1] - B[i]);
    }
    segment_tree<int> st1(C, f, 0);
    segment_tree<int> st2(D, f, 0);
    while (Q--) {
        int h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        h1--;
        w1--;
        h2--;
        w2--;
        int x = st1.query(h1, h2);
        int y = st2.query(w1, w2);
        cout << gcd(gcd(x, y), A[h1] + B[w1]) << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

