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

vector<vector<string> > cnt;
int count(string str) {
    set<char> st;
    for (int i = 0; i < str.size(); i++)  {
        if (str[i] != ' ') st.insert(str[i]);
    }
    return st.size();
}
int main() {
    int ts;
    scanf("%d\n", &ts);
    cnt.resize(21);
    for (int cas = 1; cas <= ts; cas++) {
        for (int i = 0; i < 21; i++) {
            cnt[i].clear();
        }
        int n;
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++) {
            string str;
            getline(cin, str);
            int sum = count(str);
            cnt[sum].PB(str);
        }
        for (int i = 20; i >= 0; i--) {
            if (cnt[i].size() > 0) {
                sort(cnt[i].begin(), cnt[i].end());
                printf("Case #%d: %s\n", cas, cnt[i][0].c_str());
                break;
            }
        }
    }
    return 0;
}

