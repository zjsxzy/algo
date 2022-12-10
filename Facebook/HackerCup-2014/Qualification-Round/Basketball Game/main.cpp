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

const int maxn = 35;
struct Person {
	string name;
	int shot, height;
	int draft;
	int time;
	bool in;
	bool operator == (const Person &pt) const {
		return draft == pt.draft;
	}
}per[maxn];
int n, p, m;
vector<Person> t1, t2;

bool cmp(const Person &A, const Person &B) {
	return A.shot == B.shot ? A.height > B.height : A.shot > B.shot;
}

bool cmpName(const Person &A, const Person &B) {
	return A.name < B.name;
}

int main() {
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		t1.clear(); t2.clear();
		printf("Case #%d:", cas);
		cin >> n >> m >> p;
		for (int i = 0; i < n; i++) {
			cin >> per[i].name >> per[i].shot >> per[i].height;
		}

		sort(per, per + n, cmp);
		for (int i = 0; i < n; i++) {
			per[i].time = 0;
			per[i].draft = i + 1;
			per[i].in = false;
		}

		for (int i = 0; i < n; i += 2)
			t1.PB(per[i]);
		for (int i = 1; i < n; i += 2)
			t2.PB(per[i]);

		if (t1.size() > p || t2.size() > p) {
			vector<Person> g1, g2;
			for (int i = 0; i < p; i++) {
				g1.PB(t1[i]);
				t1[i].in = true;
			}
			for (int i = 0; i < p; i++) {
				g2.PB(t2[i]);
				t2[i].in = true;
			}
			for (int time = 1; time <= m; time++) {
				for (int i = 0; i < p; i++) {
					g1[i].time++; g2[i].time++;
					for (int j = 0; j < t1.size(); j++)
						if (g1[i].draft == t1[j].draft)
							t1[j].time = g1[i].time;
					for (int j = 0; j < t2.size(); j++)
						if (g2[i].draft == t2[j].draft)
							t2[j].time = g2[i].time;
					//cout << g1[i].name << " " << g1[i].time << endl;
				}

				int mn1 = 0, mn2 = 0;
				for (int i = 1; i < p; i++) {
					if (g1[i].time > g1[mn1].time || (g1[i].time == g1[mn1].time && g1[i].draft > g1[mn1].draft)) {
						mn1 = i;
					}
					if (g2[i].time > g2[mn1].time || (g2[i].time == g2[mn2].time && g2[i].draft > g2[mn2].draft)) {
						mn2 = i;
					}
				}

				int mx1 = 0, mx2 = 0;
				for (int i = 1; i < t1.size(); i++) {
					if (t1[i].in) continue;
					if (t1[i].time < t1[mx1].time || (t1[i].time == t1[mx1].time && t1[i].draft < t1[mx1].draft)) {
						mx1 = i;
					}
				}
				for (int i = 1; i < t2.size(); i++) {
					if (t2[i].in) continue;
					if (t2[i].time < t2[mx2].time || (t2[i].time == t2[mx2].time && t2[i].draft < t2[mx2].draft)) {
						mx2 = i;
					}
				}

				/*
				cout << g1[mn1].name << endl;
				cout << g2[mn1].name << endl;
				*/
				for (int i = 0; i < t1.size(); i++)
					if (g1[mn1].draft == t1[i].draft)
						t1[i].in = false;
				for (int i = 0; i < t2.size(); i++)
					if (g2[mn1].draft == t2[i].draft)
						t2[i].in = false;
				g1.erase(g1.begin() + mn1);
				g2.erase(g2.begin() + mn2);

				/*
				cout << t1[mx1].name << endl;
				cout << t2[mx2].name << endl;
				*/
				t1[mx1].in = true;
				t2[mx2].in = true;
				g1.push_back(t1[mx1]);
				g2.push_back(t2[mx2]);

				/*
				for (int i = 0; i < t1.size(); i++)
					cout << t1[i].name << " " << t1[i].time << endl;
				*/
				//cout << endl;
			}
			vector<string> ans;
			for (int i = 0; i < p; i++) {
				ans.PB(g1[i].name);
				ans.PB(g2[i].name);
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				cout << " " << ans[i];
			cout << endl;
		} else {
			sort(per, per + n, cmpName);
			for (int i = 0; i < n; i++)
				cout << " " << per[i].name;
			cout << endl;
		}
	}
	return 0;
}

