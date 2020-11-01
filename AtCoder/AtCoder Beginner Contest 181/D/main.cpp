#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int main() {
    string s;
    cin >> s;

    if (s.size() < 4) {
        vector<int> perm(s.size());
        for (int i = 0; i < s.size(); i++) {
            perm[i] = i;
        }
        do {
            int num = 0;
            for (int i = 0; i < s.size(); i++) {
                num = num * 10 + s[perm[i]] - '0';
            }
            if (num % 8 == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        } while(next_permutation(perm.begin(), perm.end()));
        cout << "No" << endl;
        return 0;
    }

    map<int, int> cnt;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - '0']++;
    }
    map<int, int> cur;
    for (int i = 100; i <= 999; i++) {
        if (i % 8 == 0) {
            int a = i / 100, b = i % 100 / 10, c = i % 10;
            cur.clear();
            cur[a]++;
            cur[b]++;
            cur[c]++;
            bool flag = true;
            for (auto it : cur) {
                if (cnt.find(it.first) == cnt.end()) {
                    flag = false;
                    break;
                }
                if (cnt[it.first] < it.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

