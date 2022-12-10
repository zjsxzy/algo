#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (auto& x: A) cin >> x;
    vector<int> vec;
    for (int i = 0; i < M; i++) vec.push_back(A[i]);
    sort(vec.begin(), vec.end());
    LL sum = 0;
    multiset<LL> st1, st2;
    for (int i = 0; i < M; i++) {
        if (i < K) {
            st1.insert(vec[i]);
            sum += vec[i];
        } else {
            st2.insert(vec[i]);
        }
    }
    cout << sum;
    for (int i = 1; i <= N - M; i++) {
        // delete A[i - 1]
        auto x = st1.find(A[i - 1]);
        if (x != st1.end()) {
            sum -= A[i - 1];
            st1.erase(x);
        } else {
            auto y = st2.find(A[i - 1]);
            st2.erase(y);
        }

        // add A[i + M - 1]
        if ((int)st1.size() == K) {
            auto mx = st1.end();
            mx--;
            // cout << *mx << endl;
            if (A[i + M - 1] < *mx) {
                sum += A[i + M - 1] - *mx;
                st2.insert(*mx);
                st1.erase(mx);
                st1.insert(A[i + M - 1]);
            } else {
                st2.insert(A[i + M - 1]);
            }
        } else {
            assert(st1.size() == K - 1);
            if (st2.empty()) {
                st1.insert(A[i + M - 1]);
                sum += A[i + M - 1];
            } else {
                auto mn = st2.begin();
                if (A[i + M - 1] <= *mn) {
                    sum += A[i + M - 1];
                    st1.insert(A[i + M - 1]);
                } else {
                    sum += *mn;
                    st1.insert(*mn);
                    st2.erase(mn);
                    st2.insert(A[i + M - 1]);
                }
            }
        }
        cout << ' ' << sum;
    }
    cout << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}