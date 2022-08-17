#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = 1000000000;
struct Edge {
    int w = INF, to = -1;
    Edge() {}
    Edge(int _w, int _to) : w(_w), to(_to) {}
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

int prims(vector<vector<Edge>>& adj, int n) {
    int total_weight = 0;
    vector<Edge> min_e(n);
    for (int st = 0; st < n; st++) {
        if (min_e[st].w != INF) continue;
        min_e[st].w = 0;
        set<Edge> q;
        q.insert({0, st});
        vector<bool> selected(n, false);
        for (int i = 0; i < n; i++) {
            if (q.empty()) break;
            int v = q.begin()->to;
            selected[v] = true;
            total_weight += q.begin()->w;
            q.erase(q.begin());

            for (Edge& e : adj[v]) {
                if (!selected[e.to] && e.w < min_e[e.to].w) {
                    q.erase({min_e[e.to].w, e.to});
                    min_e[e.to] = {e.w, v};
                    q.insert({e.w, e.to});
                }
            }
        }
    }
    return total_weight;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

class Doors {
	public:
    int row, col;
	int build(vector <string> plan) {
        row = plan.size(), col = plan[0].size();
        vector<vector<Edge>> adj(row * col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (plan[i][j] == '.') {
                    int u = idx(i, j);
                    for (int k = 0; k < 4; k++) {
                        int ii = i + dx[k], jj = j + dy[k];
                        if (ii >= 0 && ii < row && jj >= 0 && jj < col && plan[ii][jj] == '.') {
                            int v = idx(ii, jj);
                            if (abs(i - ii) == 1) {
                                adj[u].push_back({2, v});
                            } else {
                                adj[u].push_back({1, v});
                            }
                        }
                    }
                }
            }
        }
        int res = prims(adj, row * col);
        return res;
	}

    int idx(int i, int j) {
        return i * col + j;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, build(Arg0)); }
	void test_case_1() { string Arr0[] = {".#.#.#",
 "#.#.#.",
 ".#.#.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, build(Arg0)); }
	void test_case_2() { string Arr0[] = {".#..",
 ".###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, build(Arg0)); }
	void test_case_3() { string Arr0[] = {".#.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, build(Arg0)); }
	void test_case_4() { string Arr0[] = {".....",
 "...#.",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; verify_case(4, Arg1, build(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Doors ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
