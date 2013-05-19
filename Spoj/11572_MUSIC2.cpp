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

int main() {
	map<string, string> mp;
	mp["A#"] = "Bb"; mp["Bb"] = "A#";
	mp["C#"] = "Db"; mp["Db"] = "C#";
	mp["D#"] = "Eb"; mp["Eb"] = "D#";
	mp["F#"] = "Gb"; mp["Gb"] = "F#";
	mp["G#"] = "Ab"; mp["Ab"] = "G#";
	int cas = 1;
	string s1, s2;
	while (cin >> s1 >> s2) {
		printf("Case %d: ", cas++);
		if (mp.find(s1) != mp.end()) {
			cout << mp[s1] << " " << s2 << endl;
		} else {
			cout << "UNIQUE" << endl;
		}
	}
	return 0;
}