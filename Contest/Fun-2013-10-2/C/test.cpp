#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned int uint;

#define N 200005
int n , m , P;
struct stree
{
  int mx , mn , add;
}t[N << 2];
#define MID int mid = (l + r) >> 1;
#define Left l , mid
#define Right mid + 1 , r
int top , bot , val;
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}
void pushup(int p)
{
    int LL = p << 1 , RR = p << 1 | 1;
    t[p].mx = max(t[LL].mx , t[RR].mx);
    t[p].mn = min(t[LL].mn , t[RR].mn);
}
void pushdown(int p)
{
    int LL = p << 1 , RR = p << 1 | 1;;
    if (t[p].add)
    {
        t[LL].mx += t[p].add;
        t[LL].mn += t[p].add;
        t[LL].add += t[p].add;
        t[RR].mx += t[p].add;
        t[RR].mn += t[p].add;
        t[RR].add += t[p].add;
        t[p].add = 0;
    }
}

void update(int p , int l , int r)
{
    if (top <= l && r <= bot)
    {
        if (t[p].mx < P)
        {
            t[p].mx += val;
            t[p].mn += val;
            t[p].add += val;
            return;
        }
        if (t[p].mn >= P)
        {
            t[p].mx += val + val;
            t[p].mn += val + val;
            t[p].add += val + val;
            return;
        }
    } MID; pushdown(p);
    if (top <= mid) update(p << 1 , Left);
    if (bot > mid) update(p << 1 | 1 , Right);
    pushup(p);
}
void Build(int p , int l , int r)
{
    t[p].mn = t[p].mx = t[p].add = 0;
    if (l != r)
    {
        MID; 
        Build(p << 1 , l , mid);
        Build(p << 1 | 1 , mid + 1 , r);
    }
}
void Print(int p , int l , int r)
{
    if (l != r)
    {
        MID;pushdown(p);
        Print(p << 1 , l , mid);
        Print(p << 1 | 1 , mid + 1 , r);
    }
    else
        printf("%d%c" , t[p].add , " \n"[l == n]);
}

void work()
{
    Build(1 , 1 , n);
    while (m --)
    {
        RD(top) , RD(bot) , RD(val);
        update(1 , 1 , n);
    }
    Print(1 , 1 , n);
}

int main()
{
    while (~scanf("%d%d%d",&n , &m , &P))
        work();
    return 0;
}
