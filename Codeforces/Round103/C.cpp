#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
struct node {
	int a[30];
}p[maxn], c;
char s1[maxn], s2[maxn];

bool check(int k, int l) {
	node tmp;
	for (int i = 0; i < 30; i++)
		if (k == 0) tmp.a[i] = p[l].a[i];
		else tmp.a[i] = p[l].a[i] - p[k - 1].a[i];
	for (int i = 1; i < 30; i++)
		if (tmp.a[i] > c.a[i]) return false;
	return true;
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%s", s1);
	scanf("%s", s2);
	if (strlen(s2) > strlen(s1)) {
		printf("0\n");
		return 0;
	}
	int len = strlen(s1);
	if (s1[0] == '?') p[0].a[0]++;
	else p[0].a[s1[0] - 'a' + 1]++;
	for (int i = 1; i < len; i++) {
		p[i] = p[i - 1];
		if (s1[i] == '?') p[i].a[0] = p[i - 1].a[0] + 1;
		else p[i].a[s1[i] - 'a' + 1] = p[i - 1].a[s1[i] - 'a' + 1] + 1;
	}
	len = strlen(s2);
	for (int i = 0; i < len; i++)
		c.a[s2[i] - 'a' + 1]++;
	int n = strlen(s1);

	int ret = 0;
	for (int i = 0; i + len - 1 < n; i++)
		if (check(i, i + len - 1)) ret++;
	printf("%d\n", ret);
	return 0;
}
