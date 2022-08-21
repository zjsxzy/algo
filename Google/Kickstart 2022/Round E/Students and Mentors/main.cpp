#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> r(n);
    multiset<int> st;
    for (auto& x: r) {
        cin >> x;
        st.insert(x);
    }
    for (int i = 0; i < n; i++) {
        auto x = st.find(r[i]);
        st.erase(x);
        auto mentor = st.upper_bound(2 * r[i]);
        if (mentor == st.begin()) {
            cout << " -1";
        } else {
            mentor--;
            cout << " " << *mentor;
        }
        st.insert(r[i]);
    }
    cout << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ":";
       solve();
   }
   return 0;
}

