#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
char st[1000005];
int sum[1000005];

int main()
{
	freopen("in.txt", "r", stdin);
	cin >> K;
	scanf("%s", st);
	N = strlen(st);
	for (int i = 1; i <= N; i++) {
		int t = (st[i - 1] == '1');
		sum[i] = sum[i - 1] + t;
	}

	long long ret = 0;
	for (int i = 1; i <= N; i++) {
		int find = sum[i - 1] + K;
		if (sum[N] < find) continue;
		int t1 = lower_bound(sum + i, sum + N + 1, find) - sum;
		int t2 = upper_bound(sum + i, sum + N + 1, find) - sum;
		ret += (long long)(t2 - t1);
	}
	cout << ret << endl;
	return 0;
}
