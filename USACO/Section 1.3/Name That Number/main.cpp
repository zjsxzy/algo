/*
ID: frankzh1
TASK: namenum
LANG: C++
*/
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
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

set<string> names;
map<char, int> m;
LL num;

void init() {
    m['A']=2;m['B']=2;m['C']=2;
    m['D']=3;m['E']=3;m['F']=3;
    m['G']=4;m['H']=4;m['I']=4;
    m['J']=5;m['K']=5;m['L']=5;
    m['M']=6;m['N']=6;m['O']=6;
    m['P']=7;m['R']=7;m['S']=7;
    m['T']=8;m['U']=8;m['V']=8;
    m['W']=9;m['Y']=9;m['Z']=9;
    m['Q']=0;m['Z']=0;
}

LL convert(string s) {
    LL res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        res = res * 10 + m[s[i]];
    }
    return res;
}

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    ifstream fdict ("dict.txt");
    string s;
    while (fdict >> s) {
        names.insert(s);
    }
    init();

    cin >> num;
    int cnt = 0;
    for (set<string>::iterator it = names.begin(); it != names.end(); it++) {
        string s = *it;
        if (convert(s) == num) {
            cout << s << endl;
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "NONE" << endl;
    }
    return 0;
}

