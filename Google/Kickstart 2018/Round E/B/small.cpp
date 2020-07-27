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

int n, m, p;
vector<string> pref;
set<int> forb;
vector<int> zero, one;

void pre() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            if (pref[i][j] == '0') {
                zero[j]++;
            } else {
                one[j]++;
            }
        }
    }
    /*
    for (int i = 0; i < p; i++) {
        cout << zero[i] << " " << one[i] << endl;
    }
    */
}

string state(int s) {
    string str = "";
    for (int i = 0; i < p; i++) {
        if (s & (1 << i)) {
            str += "1";
        } else {
            str += "0";
        }
    }
    return str;
}

void solve(int cs) {
    int res = n * p;
    int s = -1;
    for (int mask = 0; mask < (1<<p); mask++) {
        if (forb.find(mask) == forb.end()) {
            int temp = 0;
            for (int j = 0; j < p; j++) {
                if (mask & (1 << j)) {
                    temp += zero[j];
                } else {
                    temp += one[j];
                }
            }
            if (temp < res) {
                res = temp;
                s = mask;
            }
        }
    }
    cout << "Case #" << cs << ": " << res << endl;
    cout << state(s) << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        cin >> n >> m >> p;
        pref.resize(n);
        zero.resize(p);
        one.resize(p);
        for (int i = 0; i < n; i++) {
            cin >> pref[i];
        }
        for (int i = 0; i < m; i++) {
            string str;
            cin >> str;
            int mask = 0;
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == '1') {
                    mask |= (1 << j);
                }
            }
            forb.insert(mask);
        }
        pre();
        solve(cs);
        pref.clear();
        forb.clear();
        zero.clear();
        one.clear();
    }
    return 0;
}

