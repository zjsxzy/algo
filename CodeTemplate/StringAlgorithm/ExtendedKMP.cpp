void ExtendedKMP(char a[], char b[], int M, int N, int nxt[], int ret[]) {
	int i, j, k;
	for (j = 0; 1 + j < M && a[j] == a[1 + j]; j++);
	nxt[1] = j;
	k = 1;
	for (i = 2; i < M; i++) {
		int len = k + nxt[k], L = nxt[i - k];
		if (L < len - i) {
			nxt[i] = L;
		} else {
			for (j = max(0, len - i); i + j < M && a[j] == a[i + j]; j++);
			nxt[i] = j;
			k = i;
		}
	}
	for (j = 0; j < N && j < M && a[i] == b[j]; j++);
	ret[0] = j;
	k = 0;
	for (i = 1; i < N; i++) {
		int len = k + ret[k], L = nxt[i - k];
		if (L < len - i) {
			ret[i] = L;
		} else {
			for (j = max(0, len - i); j < M && i + j < N && a[i] == b[i + j]; j++);
			ret[i] = j;
			k = i;
		}
	}
}
