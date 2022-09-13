#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool find_substring(vector<int>& pattern, vector<int>& text, int k) {
	int n = pattern.size();
	vector<int> next(n + 1, 0);
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0) {
			j = next[j];
			if (pattern[j] == pattern[i]) {
				next[i + 1] = j + 1;
				break;
			}
		}
	}

	int m = text.size();
	for (int i = 0, j = 0; i < m; i++) {
		if (j < n && text[i] == pattern[j]) {
			j++;
		} else {
			while (j > 0) {
				j = next[j];
				if (text[i] == pattern[j]) {
					j++;
					break;
				}
			}
		}
		if (j == n) {
            if (k >= 2 || i >= n) return true;
		}
	}
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (k == 0) {
        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if (n == 2) {
        if (a == b && k % 2 == 0) {
            cout << "YES" << endl;
        } else if (k % 2 == 1 && a[0] == b[1] && a[1] == b[0]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        a.push_back(a[i]);
    }
    bool sub = find_substring(b, a, k);
    if (sub) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

