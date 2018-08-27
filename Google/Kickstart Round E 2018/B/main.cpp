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
set<string> forb;
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
}

int score(string str) {
    int res = 0;
    for (int i = 0; i < p; i++) {
        if (str[i] == '1') {
            res += zero[i];
        } else {
            res += one[i];
        }
    }
    return res;
}

void solve(int cs) {
    string best = "";
    for (int i = 0; i < p; i++) {
        if (one[i] > zero[i]) {
            best += "1";
        } else {
            best += "0";
        }
    }
    int res = score(best);
    // for (int i = 0; i < p; i++)
    //     printf("i=%d, one=%d, zero=%d\n", i, one[i], zero[i]);
    // cout << "bestScore: " << res << endl;

    int bestCost = 0;
    priority_queue<pair<int, string> > q;
    q.push(MP(0, best));
    while (!q.empty()) {
        pair<int, string> cur = q.top(); q.pop();
        int cost = -cur.first;
        string mask = cur.second;
        // cout << cost << " " << state(mask) << endl;
        if (forb.find(mask) == forb.end()) {
            // cout << "final: " << state(mask) << endl;
            bestCost = cost;
            break;
        } else {
            for (int i = 0; i < p; i++) {
                if (mask[i] == best[i]) {
                    string newMask = mask;
                    if (mask[i] == '1') {
                        newMask[i] = '0';
                    } else {
                        newMask[i] = '1';
                    }
                    int newCost = cost + abs(one[i] - zero[i]);
                    q.push(MP(-newCost, newMask));
                }
            }
        }
    }
    cout << "Case #" << cs << ": " << res + bestCost << endl;
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
            forb.insert(str);
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

