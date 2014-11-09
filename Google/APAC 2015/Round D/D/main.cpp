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
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 100;
int mat[MAXN][MAXN];
string state[MAXN];

pair<int, int> trans(string pos) {
	return MP(pos[0] - 'A' + 1, pos[1] - '0');
}
bool dir1(pair<int, int> posA, pair<int, int> curr) {
	while (curr.first >= 1) {
		curr.first--;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool dir2(pair<int, int> posA, pair<int, int> curr) {
	while (curr.first <= 8) {
		curr.first++;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool dir3(pair<int, int> posA, pair<int, int> curr) {
	while (curr.second >= 1) {
		curr.second--;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool dir4(pair<int, int> posA, pair<int, int> curr) {
	while (curr.second <= 8) {
		curr.second++;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool dir5(pair<int, int> posA, pair<int, int> curr) {
	while (curr.first >= 1 && curr.second >= 1) {
		curr.first--; curr.second--;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool dir6(pair<int, int> posA, pair<int, int> curr) {
	while (curr.first >= 1 && curr.second <= 8) {
		curr.first--; curr.second++;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool dir7(pair<int, int> posA, pair<int, int> curr) {
	while (curr.first <= 8 && curr.second >= 1) {
		curr.first++; curr.second--;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool dir8(pair<int, int> posA, pair<int, int> curr) {
	while (curr.first <= 8 && curr.second <= 8) {
		curr.first++; curr.second++;
		if (posA == curr) return true;
		if (mat[curr.first][curr.second]) return false;
	}
	return false;
}
bool kill(string posA, string posB, char piece) {
	pair<int, int> pA = trans(posA);
	pair<int, int> pB = trans(posB);
	
	// King
	if (piece == 'K') {
		if (abs(pA.first - pB.first) <= 1 && abs(pA.second - pB.second) <= 1) {
			return true;
		} else {
			return false;
		}
	}
	
	// Queen
	if (piece == 'Q') {
		return dir1(pA, pB) || dir2(pA, pB) || dir3(pA, pB) || dir4(pA, pB) || dir5(pA, pB) || dir6(pA, pB) || dir7(pA, pB) || dir8(pA, pB);
	}
	
	// Rook
	if (piece == 'R') {
		return dir1(pA, pB) || dir2(pA, pB) || dir3(pA, pB) || dir4(pA, pB);
	}
	
	// Bishop
	if (piece == 'B') {
		return dir5(pA, pB) || dir6(pA, pB) || dir7(pA, pB) || dir8(pA, pB);
	}
	
	// Knight
	if (piece == 'K') {
		int dx = abs(pA.first - pB.first), dy = abs(pA.second - pB.second);
		return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
	}
	
	// Pawn
	if (piece == 'P') {
		if (pA.first - pB.first == 1) {
			if (abs(pA.second - pB.second) == 1) {
				return true;
			}
		} else {
			return false;
		}
	}
	return false;
}
// if A can be killed by B
bool cankill(string A, string B) {
	return kill(A.substr(0, 2), B.substr(0, 2), B[3]);
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		memset(mat, false, sizeof(mat));
		int n;
		cin >> n;
		int res = 0;
		for (int i = 0; i < n; i++) {
			cin >> state[i];
			pair<int, int> p = trans(state[i].substr(0, 2));
			mat[p.first][p.second] = true;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				res += cankill(state[i], state[j]) ? 1 : 0;
			}
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
