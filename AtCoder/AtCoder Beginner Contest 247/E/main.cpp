#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

long long calc(vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> mn, mx;
    for (int i = 0; i < n; i++) {
        if (nums[i] == maxK) mx.push_back(i);
        if (nums[i] == minK) mn.push_back(i);
    }
    if (mn.size() == 0 || mx.size() == 0) return 0;
    int curr = -1;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == minK) {
            auto x = lower_bound(mx.begin(), mx.end(), i);
            if (x != mx.end()) {
                long long prev = i - curr;
                res += prev * (n - *x);
            }
            curr = i;
        } else if (nums[i] == maxK) {
            auto x = lower_bound(mn.begin(), mn.end(), i);
            if (x != mn.end()) {
                long long prev = i - curr;
                res += prev * (n - *x);
            }
            curr = i;
        }
    }
    return res;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> vec;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > x || nums[i] < y) {
            long long t = calc(vec, y, x);
            res += t;
            vec.clear();
        } else {
            vec.push_back(nums[i]);
        }
    }
    long long t = calc(vec, y, x);
    res += t;
    cout << res << endl;
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

