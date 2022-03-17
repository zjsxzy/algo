#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
const int maxn = 10005;
const int inf = 1000000;
vector<edge> adj[maxn];
int n, m, N;
vector<int> dijkstra(int st) {
    // construct graph: adj[u].emplace_back(v, c)
    vector<int> dist(N, inf);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if (p.first > dist[v]) continue;
        for (edge e : adj[v]) {
            int nd = p.first + e.cost;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist;
}

class EllysBreakout {
	public:
	int getCount(vector <string> plan) {
        n = plan.size();
        if (n == 0) return 0;
        m = plan[0].size();
        N = n * m + 1;
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 < n) {
                    add_edge(get_index(i, j), get_index(i + 1, j), plan[i + 1][j] == '#');
                }
                if (j + 1 < m) {
                    add_edge(get_index(i, j), get_index(i, j + 1), plan[i][j + 1] == '#');
                }
                if (i - 1 >= 0) {
                    add_edge(get_index(i, j), get_index(i - 1, j), plan[i - 1][j] == '#');
                }
                if (j - 1 >= 0) {
                    add_edge(get_index(i, j), get_index(i, j - 1), plan[i][j - 1] == '#');
                }
            }
        }
        for (int i = 0; i < n; i++) {
            add_edge(n * m, get_index(i, 0), plan[i][0] == '#');
            add_edge(n * m, get_index(i, m - 1), plan[i][m - 1] == '#');
        }
        for (int j = 0; j < m; j++) {
            add_edge(n * m, get_index(0, j), plan[0][j] == '#');
            add_edge(n * m, get_index(n - 1, j), plan[n - 1][j] == '#');
        }
        vector<int> dist = dijkstra(n * m);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (plan[i][j] == '.') {
                    mx = max(mx, dist[get_index(i, j)]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (plan[i][j] == '.') {
                    res += dist[get_index(i, j)] == mx;
                }
            }
        }
        return res;
	}

    int get_index(int i, int j) {
        return i * m + j;
    }

    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#............",
 ".#####........",
 ".#.#..#.......",
 ".##.#.#.......",
 ".#.#..#..####.",
 ".#...##..#.##.",
 "..####...###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"..#",
 "...",
 ".#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#",
 "#.#.#.#.#.#.#.#.#.",
 ".#.#.#.#.#.#.#.#.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"#########",
 "#########",
 "#########",
 "#########",
 "####.####",
 "####.####",
 "####.####",
 "#########",
 "#########",
 "#########",
 "#########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"#...##.......#..#..#..#.#..#..###............##...",
 "....#.....#....#...###..#....#......#.#.......#.#.",
 "......#....#..#.....#.#..#...#.#..##.......#.....#",
 "................#..#......##........#..#....##...#",
 "###..#..#.#....##...#...........#.##..###..##.....",
 ".##..#......#...........#.##...##..#.....#.....#..",
 "....#..##...#..#.#........##.#....................",
 ".#.#.#.##.....#.........#......#.......#..#.##.#..",
 "..#....#......#........#...#.#...#.#....#........#",
 "#.#....#..#.#.#.#....#.....................#.#....",
 ".#....#..#.......#.........#....#.#............##.",
 "..##......#....###..#...#.#..#.....##........#..#.",
 "........#.#..........#......#........##.#.#.#....#",
 "....#.#..####...#..#.....#.###..##....#.#.......#.",
 "....#....#...#................###.#......##.......",
 ".#.....#..#.....##....#......................##.#.",
 "#.................#.......#...#...........#....#..",
 "............#........#.....#.#.....#.#.....#..##..",
"#......#.#..#.#.##..#.........#..#.#.....#.....#..",
 "....#..###.#........#.#.....................##....",
 "......##...###..#...#.##..#..#.##....#.........##.",
 ".......#...............#....#...#......##....#..#.",
 ".#...#.##....#...#........###..##.#....#...##.....",
 "....#........#..............#..###.#.#..#.....#.##",
 ".#...#..#.....#.#...#...........#....##.....#.#...",
 "...#..#.#.#..##....#............#.....#........###",
 ".##......#.#..##.......###...##...................",
 "..........#.............#.#...#.....###...##..##..",
 ".......##...#.#...#.........#.#.....#.#..#.#...#..",
 "####.........#.#.....#....#.#......#.#.....#..#...",
 ".#.#...#..###...#.#.#.....###.#....##.....#...#..#",
 ".#..#.##.#.###....#.###..#..........#...#.........",
 "##..#.#....#..##...#.....##..#..##..............##",
 "#.##.##..........##.#....##......#...#.....##...#.",
 ".....#........#..............#.....####.######....",
 "..##............#..###.##...#.#...#.....#.#...#..#",
 "...##..#.#...#......#.#..........#..#..##..#.#..#.",
 "..##.####......#....#....#.....#......#....##.....",
 "#.......####.#......##.#.....#..#........#...##.#.",
 "..#.....#..###....#......#..#........#....####....",
 "......#.....#..................#.........#.##...#.",
 "...#....#....##......#.#.....#.....#....#......#..",
 "....#.##...#.#....#..#.#...#.......##.......#.#...",
 "...#..#.#.##.#.....###....#.###.....##.#......#...",
 ".#.#......#.....#.....#...........##...#.....#.##.",
 "..........#.....#...#.##....#..........#.....###..",
 "........##..#.....#...#....##..#......##.......#..",
 ".....#....##....#.....#....#.#.#.........#........",
 "..#...##......#.#............#....#.##...#....#...",
 "..##...#.#...#......#....##.#.#..#......#..######."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, getCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	EllysBreakout ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
