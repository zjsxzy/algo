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

const int MAXN = 1000 + 5;
int n, m, K;

int main() {
	cin >> n >> m >> K;
	vector<pair<int, int> > vec;
	for (int c = 0; c < n; c++) {
		vector<int> arr(m);
		for (int i = 0; i < m; i++)
			cin >> arr[i];
		if (K == 0) {
			for (int i = 0; i < m; i++)
				for (int j = i + 1; j < m; j++)
					if (arr[j] < arr[i]) {
						swap(arr[i], arr[j]);
						vec.PB(MP(i + 1, j + 1));
					}
		} else {
			for (int i = 0; i < m; i++) {
				for (int j = i + 1; j < m; j++) {
					if (arr[j] > arr[i]) {
						swap(arr[i], arr[j]);
						vec.PB(MP(j + 1, i + 1));
					}
				}
			}
		}
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i].first << " " << vec[i].second << endl;
	return 0;
}

