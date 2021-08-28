/*
ID: frankzh1
TASK: contact
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct Contact {
    string s;
    int cnt;
    Contact(string s, int cnt) {
        this->s = s;
        this->cnt = cnt;
    }
    bool operator < (const Contact& p) {
        if (cnt == p.cnt) {
            if (s.size() == p.s.size()) {
                return s < p.s;
            } else {
                return s.size() < p.s.size();
            }
        } else {
            return cnt > p.cnt;
        }
    }
};

void solve() {
    int A, B, n;
    cin >> A >> B >> n;
    string text, s;
    while (cin >> s) {
        text += s;
    }

    map<string, int> idx;
    vector<Contact> contact;
    int tot = 0;
    for (int i = 0; i + A <= text.size(); i++) {
        for (int j = A; j <= B; j++) {
            if (i + j > text.size()) continue;
            string sub = text.substr(i, j);
            if (idx.find(sub) == idx.end()) {
                idx[sub] = tot;
                contact.emplace_back(sub, 1);
                tot++;
            } else {
                contact[idx[sub]].cnt++;
            }
        }
    }
    /*
    for (auto &[k, v]: idx) {
        cout << v << " " << k << endl;
    }
    for (auto &c: contact) {
        cout << c.s << " " << c.cnt << endl;
    }
    */
    sort(contact.begin(), contact.end());
    int ans = 0;
    for (int i = 0; i < tot; i++) {
        printf("%d\n", contact[i].cnt);
        int it = 0;
        while (i + 1 < tot && contact[i].cnt == contact[i + 1].cnt) {
            //printf("%s", contact[i].s);
            cout << contact[i].s;
            it++;
            if (it % 6 == 0) puts("");
            else printf(" ");
            i++;
        }
        //printf("%s\n", contact[i].s);
        cout << contact[i].s << endl;
        ans++;
        if (ans == n) break;
    }
}

int main() {
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    solve();
    return 0;
}

