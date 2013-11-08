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

const int maxn = 500000 + 50;
int n, m;
struct Node {
	int pi;
	Node *prev;
} node[maxn * 2], *curNode;

Node* newNode(int pi) {
	curNode->prev = NULL;
	curNode->pi = pi;
	return curNode++;
}

Node* newNode(Node* node) {
	if (node == NULL)
		return NULL;
	curNode->pi = node->pi;
	curNode->prev = node->prev;
	return curNode++;
}

struct Robbot {
	// 0是学习的，1是垃圾的
	Node *last[2];
	void learn(int pi) {
		Node *node = newNode(pi);
		node->prev = last[0];
		last[0] = node;
	}
	void rollback() {
		Node* nLast0 = newNode(last[0]->prev);
		Node* nLast1 = last[0];
		Node* preLast1 = newNode(last[1]);
		nLast1->prev = preLast1;
		last[0] = nLast0;
		last[1] = nLast1;
	}
	void relearn() {
		Node* nLast1 = newNode(last[1]->prev);
		Node* nLast0 = last[1];
		Node* preLast0 = newNode(last[0]);
		nLast0->prev = preLast0;
		last[1] = nLast1;
		last[0] = nLast0;
	}
	int check() {
		return last[0]->pi;
	}
} robot[maxn], *curRobot;

void clone(int bi) {
	memset(curRobot, 0, sizeof(robot[0]));
	curRobot->last[0] = newNode(robot[bi].last[0]); 
	curRobot->last[1] = newNode(robot[bi].last[1]); 
	curRobot++;
}

char cmd[100];
int main() {
	while (~scanf("%d %d", &n, &m)) {
		curNode = node + 0;
		curRobot = robot + 0;
		curRobot->last[0] = newNode(-1);
		curRobot->last[1] = NULL;
		curRobot++;

		int bi, pi;
		while (n-- > 0) {
			scanf("%s", cmd);
			if (cmd[0] == 'l') {
				scanf("%d %d", &bi, &pi);
				bi--;
				robot[bi].learn(pi);
			} else if (cmd[0] == 'r' && cmd[1] == 'o') {
				scanf("%d", &bi);
				bi--;
				robot[bi].rollback();
			} else if (cmd[0] == 'r' && cmd[1] == 'e') {
				scanf("%d", &bi);
				bi--;
				robot[bi].relearn();
			} else if (cmd[0] == 'c' && cmd[1] == 'l') {
				scanf("%d", &bi);
				bi--;
				clone(bi);
			} else {
				scanf("%d", &bi);
				bi--;
				int res = robot[bi].check();
				if (res == -1)
					puts("basic");
				else
					printf("%d\n", res);
			}
		}
	}
	return 0;
}
