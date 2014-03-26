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

int N;
int m[105][105],d[105];
int work(){
    cin>>N;
	bool flag = true;
    for(int i=0;i<N*N;i++)
        for(int j=0;j<N*N;j++) {
            cin>>m[i][j];
			if (m[i][j] > N * N) {
				flag = false;
			}
		}
	if (!flag) {
		cout << "No" << endl;
		return 0;
	}
    for(int i=0;i<N*N;i++){
        memset(d,0,sizeof(d));
        for(int j=0;j<N*N;j++)
            if(m[i][j]!=0) d[m[i][j]]+=1;
        for(int j=1;j<=N*N;j++)
            if(d[j] == 0 || d[j]>=2){
				cout << "No" << endl;
                return 0;
            }
    }
    for(int i=0;i<N*N;i++){
        memset(d,0,sizeof(d));
        for(int j=0;j<N*N;j++)
            if(m[j][i]!=0) d[m[j][i]]+=1;
        for(int j=1;j<=N*N;j++)
            if(d[j] == 0 || d[j]>=2){
				cout << "No" << endl;
                return 0;
            }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            memset(d,0,sizeof(d));
            for(int k=N*i;k<N*i+N;k++)
                for(int l=N*j;l<N*j+N;l++)
                    if(m[k][l]!=0) d[m[k][l]]+=1;
            for(int k=1;k<=N*N;k++)
                if(d[k] == 0 || d[k]>=2){
					cout << "No" << endl;
                    return 0;
                }
        }
	cout << "Yes" << endl;
	return 0;
}

int main() {
	int Test;
	cin >> Test;
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d: ", cas);
		work();
	}
	return 0;
}
