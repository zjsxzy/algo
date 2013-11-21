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

map<string, int> cntTot;
map<string, vector<int> > perPass;
int num_Passage;

bool character(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void insert(string word) {
	cntTot[word]++;
	if (perPass[word].size() > 1) {
		int num = perPass[word][perPass[word].size() - 1];
		if (num != num_Passage)
			perPass[word].PB(num_Passage);
	} else {
		perPass[word].PB(num_Passage);
	}
}

string shapeHeadTail(string &word) {
	if (!character(word[0])) {
		word.erase(word.begin());
	}
		
	if (!character(word[word.size() - 1])) {
		word.erase(word.end() - 1);
	}
	return word;
}

map<int, vector<string> > mp;
void output() {
	map<string, int>::iterator it;
	FOREACH(it, cntTot) {
		mp[it->second].PB(it->first);
	}
	map<int, vector<string> >::iterator iter = mp.end();
	mp[0].PB("#");
	for (iter--; iter != mp.begin(); iter--) {
		vector<string> sVec = iter->second;
		for (int i = 0; i < sVec.size(); i++) {
			string s = sVec[i];
			cout << s << " " << cntTot[s] << " " << perPass[s].size() << endl;
		}
	}
}

int main() {
	string word;
	num_Passage = 1;
	while (cin >> word) {
		if (word == "#") {
			num_Passage++;
			continue;
		}

		if (word.find('-') != string::npos) {
			vector<string> wordVec;
			int cur = 0, i;
			for (i = 0; i < word.size(); i++) {
				if (word[i] == '-') {
					wordVec.PB(word.substr(cur, i - cur));
					while (i < word.size() && word[i] == '-') {
						i++;
					}
					cur = i;
					i--;
				}
			}
			wordVec.PB(word.substr(cur, i - cur));
			for (int i = 0; i < wordVec.size(); i++) {
				shapeHeadTail(wordVec[i]);
				insert(wordVec[i]);
			}
		} else {
			shapeHeadTail(word);
			insert(word);
		}
	}

	/*
	map<string, int>::iterator it;
	FOREACH(it, cntTot) {
		cout << it->first << " " << it->second << " " << perPass[it->first].size() << endl;
	}
	*/

	output();

	//cout << endl;

	return 0;
}
