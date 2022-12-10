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

const int MAXN = 100 + 10;
int dgr[MAXN];
bool cmp(const int &a, const int &b)
{
	return dgr[a] < dgr[b];
}
struct MaxClique
{
	bool E[MAXN][MAXN];
	int n;
	int ans, c[MAXN];
	int Stack[MAXN], ansStack[MAXN];
	void init(int n)
	{
		this->n = n;
		memset(E, 0, sizeof(E));
	}

	void intersect(int a, int *arr, int len, int *newArr, int &newLen)
	{
		newLen = 0;
		for (int i = 0; i < len; i++)
			if (E[a][arr[i]]) newArr[newLen++] = arr[i];
	}

	bool dfs(int *arr, int len, int size)
	{
		if (len == 0)
		{
			if (size > ans) 
			{
				ans = size;
				copy(Stack, Stack + ans, ansStack);
				return true;
			}
			return false;
		}
		int newArr[MAXN], newLen, a, b;
		while (len != 0 && size + len > ans)
		{
			a = arr[0];
			Stack[size] = a;
			if (size + c[a] <= ans) return false;
			arr++; len--;
			intersect(a, arr, len, newArr, newLen);
			if (dfs(newArr, newLen, size + 1)) return true;
		}
		return false;
	}

	int solve()
	{
		memset(dgr, 0, sizeof(dgr));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (E[i][j]) dgr[j]++;
		int arr[MAXN], newArr[MAXN], newLen;
		for (int i = 0; i < n; i++)
			arr[i] = i;
		sort(arr, arr + n, cmp);
		ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			intersect(arr[i], arr + i, n - i, newArr, newLen);
			Stack[0] = arr[i];
			dfs(newArr, newLen, 1);
			c[arr[i]] = ans;
		}
		return ans;
	}
}mc;

int main()
{
	freopen("a", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		mc.n = n;
		memset(mc.E, 1, sizeof(mc.E));
		for (int i = 0; i < n; i++)
			mc.E[i][i] = 0;
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			mc.E[u][v] = mc.E[v][u] = 0;
		}
		int ans = mc.solve();
		printf("%d\n", ans);
		for (int i = 0; i < ans; i++)
			printf("%d ", mc.ansStack[i] + 1);
		printf("\n");
	}
	return 0;
}
