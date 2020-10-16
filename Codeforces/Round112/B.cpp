#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
bool check(int x) {
	int ret = 0;
	for (int k = 1; x / k > 0; k *= K) {
		ret += x / k;
	}
	return ret >= N;
}

int main()
{
	freopen("in.txt", "r", stdin);
	cin >> N >> K;
	int l = 1, r = N, ret;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << ret << endl;
	return 0;
}
