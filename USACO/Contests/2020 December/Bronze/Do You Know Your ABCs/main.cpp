#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    vector<LL> nums(7);
    map<LL, int> cnt;
    for (int i = 0; i < 7; i++) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            for (int k = j + 1; k < 7; k++) {
                LL a = nums[i], b = nums[j], c = nums[k];
                map<LL, int> mp;
                mp[a]++; mp[b]++; mp[c]++;
                mp[a + b]++; mp[a + c]++; mp[b + c]++;
                mp[a + b + c]++;
                if (mp == cnt) {
                    vector<LL> res;
                    res.push_back(a); res.push_back(b); res.push_back(c);
                    sort(res.begin(), res.end());
                    cout << res[0] << " " << res[1] << " " << res[2] << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

