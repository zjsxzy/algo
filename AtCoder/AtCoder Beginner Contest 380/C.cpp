#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> vec;
    string curr;
    for (int i = 0; i < n; i++) {
        if (i != 0 && s[i] != s[i - 1]) {
            vec.push_back(curr);
            curr = "";
        }
        curr += s[i];
    }
    vec.push_back(curr);
    string ans;
    int sz = vec.size(), i = 0, cnt = 0;
    for (; i < sz; i++) {
        ans += vec[i];
        if (vec[i][0] == '1') {
            cnt++;
            if (cnt == k - 1) {
                ans += vec[i + 2];
                ans += vec[i + 1];
                i += 2;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}