#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> find_substring(string pattern, string text) {
    // cout << pattern << ' ' << text << endl;
    int n = pattern.size();
    vector<int> next(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            j = next[j];
            if (pattern[j] == pattern[i]) {
                next[i + 1] = j + 1;
                break;
            }
        }
    }
    vector<int> position;
    int m = text.size();
    for (int i = 0, j = 0; i < m; i++) {
        if (j < n && text[i] == pattern[j]) {
            j++;
        } else {
            while (j > 0) {
                j = next[j];
                if (text[i] == pattern[j]) {
                    j++;
                    break;
                }
            }
        }
        if (j == n) {
            position.push_back(i - n + 1);
        }
    }
    return position;
}

void solve() {
    int n;
    string S, T;
    cin >> n >> S >> T;
    for (auto& c: T) {
        if (c >= 'a' && c <= 'z') c = 'A' + c - 'a';
        else c = 'a' + c - 'A';
    }
    vector<int> res = find_substring(S, T + T);
    if (res.empty()) cout << "No" << endl;
    else {
        int ans = n;
        cout << "Yes" << endl;
        for (auto x: res) {
            ans = min(ans, x);
            ans = min(ans, n - x);
        }
        cout << ans << endl;
    }
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