/*
ID: frankzh1
TASK: window
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 100;
struct Window{
    int x1, x2, y1, y2; char c;
    Window(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, int _c = 0) {
        x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2, c = _c;
    }
    bool operator == (const Window &p) const {
        return c == p.c;
    }
    bool operator < (const Window &p) const {
        if(x1 != p.x1) return x1 < p.x1;
        if(y1 != p.y1) return y1 < p.y1;
        if(x2 != p.x2) return x2 < p.x2;
        return y2 < p.y2;
    }
}a[MAXN], win[300];
int used[300], cnt = 0;
double ans = 0, tot = 0;

void delet(Window x){
    int pos;
    for(int i = 1; i <= cnt; i++)
        if (a[i] == x) pos = i;
    used[x.c] = 0, win[x.c] = (Window){ 0, 0, 0, 0, 0 };
    for(int i = pos + 1; i <= cnt; i++) a[i - 1] = a[i];
    cnt--;
}

void move(Window x, int f){
    int pos = 0;
    for (int i = 1; i <= cnt; i++)
        if (a[i] == x) {
            pos = i;
            break;
        }
    if (f == 0) {
        for (int i = pos; i >= 2; i--)
            swap(a[i], a[i - 1]);
    } else {
        for(int i = pos; i < cnt; i++)
            swap(a[i], a[i + 1]);
    }
}

void dfs(int k, int x1, int y1, int x2, int y2){
    if (x1 == x2 || y1 == y2) return;
    if (!k) { ans += (double)(x2 - x1) * (y2 - y1); return; }
    int a1 = a[k].x1, b1 = a[k].y1, a2 = a[k].x2, b2 = a[k].y2;
    if(a2 < x1 || a1 > x2 || b2 < y1 || b1 > y2){
        dfs(k - 1, x1, y1, x2, y2);
        return;
    }
    if(a1 <= x1 && b1 <= y1 && x2 <= a2 && y2 <= b2) return;
    dfs(k - 1, x1, min(y2, b2), min(x2, a2), y2); // up
    dfs(k - 1, min(x2, a2), max(y1, b1), x2, y2); // right
    dfs(k - 1, max(x1, a1), y1, x2, max(y1, b1)); // down
    dfs(k - 1, x1, y1, max(x1, a1), min(y2, b2)); // left
}

void solve() {
    char opt, id;
    int x1, y1, x2, y2, pos;
    Window temp;
    while (cin >> opt) {
        if (opt != 's') {
            scanf("(%c,%d,%d,%d,%d)", &id, &x1, &y1, &x2, &y2);
            if(x1 > x2) swap(x1, x2); if(y1 > y2) swap(y1, y2);
            temp = (Window){ x1, y1, x2, y2, id };
            if(opt == 'w'){
                if(used[id]) continue;
                win[id] = a[++cnt] = temp, move(temp, 0);
            }
            if(opt == 't') move(temp, 0);
            if(opt == 'b') move(temp, 1);
            if(opt == 'd') delet(temp);
        } else {
            scanf("(%c)", &id); pos = 0;
            for(int i = 1; i <= cnt; i++)
                if(a[i] == win[id]) pos = i;
            ans = 0;
            tot = (double)(a[pos].x2 - a[pos].x1) * (a[pos].y2 - a[pos].y1);
            dfs(pos - 1, a[pos].x1, a[pos].y1, a[pos].x2, a[pos].y2);
            printf("%.3f\n", ans * 100 / tot);
            //cout << fixed << setprecision(3) << ans * 100 / tot << endl;
        }
        opt = getchar();
    }
}

int main() {
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);
    solve();
    return 0;
}

