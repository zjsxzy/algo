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

int n;
string s;

void solve() {
    vector<pair<int, int> > gto;
    vector<int> vec;
    int cnt = 1;
    char c = s[0];
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == c) {
            cnt++;
        } else {
            vec.push_back(cnt);
            if (cnt > 1) {
                gto.push_back(make_pair(idx, cnt));
            }
            idx++;
            c = s[i];
            cnt = 1;
        }
    }
    vec.push_back(cnt);
    if (cnt > 1) {
        gto.push_back(make_pair(idx, cnt));
    }
    idx++;
    /*
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < gto.size(); i++) {
        cout << gto[i].first << " " << gto[i].second << endl;
    }
    */
    int res = 0;
    for (int i = 0, j = 0; i < vec.size(); i++) {
        while (j < gto.size() && gto[j].first < i) {
            j++;
        }
        while (j < gto.size() && gto[j].second == 1) {
            j++;
        }
        if (j < gto.size() && gto[j].second > 1) {
            gto[j].second--;
        } else {
            i++;
        }
        res++;
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        cin >> n;
        cin >> s;
        solve();
    }
    return 0;
}

