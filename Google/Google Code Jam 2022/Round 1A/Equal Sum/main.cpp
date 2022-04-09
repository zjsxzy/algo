#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool can;
LL sum;
map<pair<int, LL>, bool> dp;
vector<int> ans;
void dfs(int m, LL n, vector<int>& nums) {
    if (n > sum) return;
    if (can == true) return;
    if (m == nums.size()) {
        if(n == sum / 2) {
            can = true;
            for (auto& x: ans) cout << x << " ";
            cout << endl;
            return;
        }
    } else{
        if (dp.find({m, n}) != dp.end()) return;
        dp[{m, n}] = true;
        dfs(m + 1, n, nums);
        ans.push_back(nums[m]);
        dfs(m + 1, n + (LL)nums[m], nums);
        ans.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    LL suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        suma += a[i];
        cout << i + 1;
        if (i == n - 1) cout << endl;
        else cout << " ";
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sumb += (LL)b[i];
        a.push_back(b[i]);
    }
    sum = suma + sumb;
    ans.clear();
    dp.clear();
    can = false;
    dfs(0, 0, a);
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

