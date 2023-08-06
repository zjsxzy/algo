#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<int, int> findCycleLength(LL p, LL q) {
    LL g = gcd(p, q);
    p /= g;
    q /= g;

    int cycleLength = 0;
    int preCycleLength = 0;
    std::unordered_map<LL, LL> remainderMap;

    while (true) {
        LL quotient = p / q;
        LL remainder = p % q;

        if (remainder == 0) {
            // 分数是有限小数，没有循环节
            return {-1, -1};
            break;
        }

        if (remainderMap.find(remainder) != remainderMap.end()) {
            // 出现了循环节
            cycleLength = cycleLength - remainderMap[remainder];
            preCycleLength = remainderMap[remainder];
            break;
        }

        remainderMap[remainder] = cycleLength;
        p = remainder * 10;
        cycleLength++;
    }

    return {preCycleLength, cycleLength};
}

void solve() {
    LL p, q;
    cin >> p >> q;
    auto res = findCycleLength(p, q);
    if (res.first == -1) cout << -1 << endl;
    else cout << res.first << ' ' << res.second << endl;
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