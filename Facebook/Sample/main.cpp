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

int N, K;
map<string, int> d;
map<string, string> pred;

void output(string state) {
	if (pred[state] != "#") {
		output(pred[state]);
		//cout << state << endl;
		for (int k = 0; k < state.size(); k++) {
			if (state[k] != pred[state][k]) {
				cout << pred[state][k] << " " << state[k] << endl;
				break;
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	int x;
	string st;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		st.push_back(char('0' + x));
	}
	string ed;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		ed.push_back(char('0' + x));
	}

	d[st] = 0;
	pred[st] = "#";
	queue<string> q;
	q.push(st);
	bool find = false;
	while (!q.empty()) {
		string state = q.front(); q.pop();
		for (int i = 1; i <= K && !find; i++) {
			int pos = -1;
			for (int k = 0; k < state.size(); k++) {
				if (state[k] == char('0' + i)) {
					pos = k;
					break;
				}
			}
			if (pos == -1) continue;
			for (int j = 1; j <= K && !find; j++) {
				if (i == j) continue;
				int edpos = -1;
				for (int k = 0; k < state.size(); k++) {
					if (state[k] == char('0' + j)) {
						edpos = k;
						break;
					}
				}
				if (edpos == -1 || edpos > pos) {
					string newstate = state;
					newstate[pos] = '0' + j;
					if (d.find(newstate) == d.end()) {
						d[newstate] = d[state] + 1;
						pred[newstate] = state;
						if (newstate == ed) {
							printf("%d\n", d[newstate]);
							output(newstate);
							find = true;
							break;
						}
						q.push(newstate);
					}
				}
			}
		}
	}
	return 0;
}

