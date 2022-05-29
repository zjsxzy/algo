#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int inf = 1e9;
int dist[55][55][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
class Jetpack {
	public:
	int travel(vector <string> maze, int T) {
        int n = maze.size(), m = maze[0].size();
        int stx = -1, sty = -1, edx = -1, edy = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'A') stx = i, sty = j;
                if (maze[i][j] == 'B') edx = i, edy = j;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j][0] = dist[i][j][1] = inf;
            }
        }
        priority_queue<pair<int, pair<pair<int, int>, int>>> pq;
        dist[stx][sty][0] = 0;
        pq.push({0, {{stx, sty}, 0}});
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int d = -p.first;
            int x = p.second.first.first;
            int y = p.second.first.second;
            int f = p.second.second;
            if (d > dist[x][y][f]) continue;
            if (x == edx && y == edy) return d;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#') {
                    if (maze[nx][ny] == '_' && f == 0) continue;
                    int nf = f;
                    if (maze[nx][ny] == 'C') nf = 1;
                    int nd = d + 1;
                    if (maze[nx][ny] == '_') nd += T;
                    if (nd < dist[nx][ny][nf]) {
                        dist[nx][ny][nf] = nd;
                        pq.push({-nd, {{nx, ny}, nf}});
                    }
                }
            }
        }
        return -1;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A###B",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 6; verify_case(0, Arg2, travel(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A#.#B",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = -1; verify_case(1, Arg2, travel(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A#.#B",
 ".._C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(2, Arg2, travel(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"B_C_C_CA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 37; verify_case(3, Arg2, travel(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"___B__.",
 "C#####.",
 "AC....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 8; verify_case(4, Arg2, travel(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"___B__.",
 "C#####.",
 "AC....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 31; verify_case(5, Arg2, travel(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Jetpack ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
