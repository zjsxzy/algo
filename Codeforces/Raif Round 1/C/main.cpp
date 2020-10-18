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

string s;

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        string s;
        cin >> s;

        int n = s.size();
        int del = 0, sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') sum_a++;
            else sum_b++;

            if (s[i] == 'B') {
                if (sum_a > 0) {
                    del += 2;
                    sum_a--; sum_b--;
                }
                else if (sum_a == 0 && sum_b > 1) {
                    del += 2;
                    sum_b -= 2;
                }
            }
        }

        cout << n - del << endl;
    }
    return 0;
}

