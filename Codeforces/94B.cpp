#include <cstdio>

int t[6];
int main()
{
	freopen("a", "r", stdin);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		t[a]++;
		t[b]++;
	}
	for (int i = 1; i <= 5; i++)
		if (t[i] >= 3 || 4 - t[i] >= 3)
		{
			printf("WIN\n");
			return 0;
		}
	printf("FAIL\n");
	return 0;
}
