/*
ID: frankzh1
TASK: clocks
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int step[9][9] = {{1, 1, 0, 1, 1, 0, 0, 0, 0},
                  {1, 1, 1, 0, 0, 0, 0, 0, 0},
                  {0, 1, 1, 0, 1, 1, 0, 0, 0},
                  {1, 0, 0, 1, 0, 0, 1, 0, 0},
                  {0, 1, 0, 1, 1, 1, 0, 1, 0},
                  {0, 0, 1, 0, 0, 1, 0, 0, 1},
                  {0, 0, 0, 1, 1, 0, 1, 1, 0},
                  {0, 0, 0, 0, 0, 0, 1, 1, 1},
                  {0, 0, 0, 0, 1, 1, 0, 1, 1}};
int vis[300000];

struct node {
    vector<int> clocks;
    vector<int> moves;
    int next; // 当前操作
    node(vector<int> &clocks, vector<int> &moves, int next) : clocks(clocks), moves(moves), next(next) {}
};

struct cmp {
    bool operator()(const node &a, const node &b) {
        if (a.moves.size() == b.moves.size()) {
            for (int i = 0; i < a.moves.size(); i++) {
                if (a.moves[i] != b.moves[i]) return a.moves[i] > b.moves[i];
            }
            return true;
        }
        return a.moves.size() > b.moves.size();
    }
};


int getCode(vector<int> &clocks) {
    int code = 0;
    for (int i = 0; i < 9; i++) {
        code <<= 2;
        code += clocks[i];
    }
    return code;
}

node bfs(vector<int>& clocks) {
    priority_queue<node, vector<node>, cmp> q;
    vector<int> moves;
    q.push(node(clocks, moves, 0));
    vis[getCode(clocks)] = 1;
    while (!q.empty()) {
        node u = q.top(); q.pop();
        int code = getCode(u.clocks);
        if (code == 0) return u;
        vis[code] = 1;
        if (u.next == 9) continue;
        int s = u.next++;
        if (s == 4 && u.clocks[0] != 0) continue; // 后面的操作不会再操作A
        q.push(u);
        for (int i = 0; i < 3; i++) { // 操作4次回到初始位置，所以同一操作最多三次
            for (int j = 0; j < u.clocks.size(); j++) {
                u.clocks[j] = (u.clocks[j] + step[s][j]) % 4;
            }
            u.moves.push_back(s + 1);
            if (vis[getCode(u.clocks)]) continue;
            q.push(u);
        }
    }
    return node(clocks, moves, 0);
}

void solve() {
    vector<int> clocks(9);
    for (int i = 0; i < 9; i++) {
        cin >> clocks[i];
        clocks[i] = (clocks[i] / 3) % 4;
    }
    memset(vis, 0, sizeof(vis));
    node ans = bfs(clocks);
    for (int i = 0; i < ans.moves.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans.moves[i];
    }
    cout << endl;
}

int main() {
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    solve();
    return 0;
}

