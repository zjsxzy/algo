/*
ID: frankzh1
TASK: gift1
LANG: C++
*/
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
map<string, int> giftr, gifts;
vector<string> name;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    cin >> n;
    name.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        giftr[name[i]] = 0;
        gifts[name[i]] = 0;
    }
    for (int i = 0; i < n; i++) {
        string give;
        cin >> give;
        int tot, t;
        cin >> tot >> t;
        if (t == 0) {
            continue;
        } else {
            int x = tot / t, y = tot % t;
            gifts[give] = tot - y;
            for (int j = 0; j < t; j++) {
                string rec;
                cin >> rec;
                giftr[rec] += x;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << name[i] << " " << giftr[name[i]] - gifts[name[i]] << endl;
    }
    return 0;
}