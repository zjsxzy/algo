#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    map<int, vector<int>> vec;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        vec[s[i] - 'a'].push_back(i);
    }
    if (t[2] == 'X') {
        int a = t[0] - 'A', b = t[1] - 'A';
        if (vec.find(a) == vec.end() || vec.find(b) == vec.end()) {
            cout << "No" << endl;
            return;
        }
        if (vec[a][0] < vec[b][vec[b].size() - 1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        int a = t[0] - 'A', b = t[1] - 'A', c = t[2] - 'A';
        if (vec.find(a) == vec.end() || vec.find(b) == vec.end() || vec.find(c) == vec.end()) {
            cout << "No" << endl;
            return;
        }
        if (vec[a][0] < vec[b][vec[b].size() - 1]) {
            for (auto x: vec[b]) {
                if (vec[a][0] < x && x < vec[c][vec[c].size() - 1]) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
        cout << "No" << endl;
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