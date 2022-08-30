#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string S;
    cin >> S;

    auto is_prefix = [&](string a, string b) {
        if (a.size() > b.size()) swap(a, b);
        if (b.substr(0, a.size()) == a) return true;
        return false;
    };

    vector<pair<int, string>> cand;
    function<void(string)> dfs = [&](string s) {
        if (s.size() > 10) return;
        if (s.size() > 0) {
            cand.push_back({-s.size(), s});
        }
        dfs(s + '.');
        dfs(s + '-');
    };
    dfs("");
    sort(cand.begin(), cand.end());

    vector<string> ans;
    ans.push_back(S);
    for (int i = 0; i < (int)cand.size(); i++) {
        bool flag = true;
        for (int j = 0; j < (int)ans.size(); j++) {
            if (is_prefix(cand[i].second, ans[j])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.push_back(cand[i].second);
            if ((int)ans.size() == n) {
                for (int j = 1; j < n; j++) {
                    cout << ans[j] << endl;
                }
                return;
            }
        }
    }
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": " << endl;
       solve();
   }
   return 0;
}

