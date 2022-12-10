#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

double jie[500];

double dp[202][21];

int main()
{
    int n,k,i,j;

    for(i=2;i<500;i++)
	jie[i]=jie[i-1]+log(i+0.0);

    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
	dp[i][0]=i;
    double p;
    int miss;
    if(n-k<=k)
    {
	puts("0.0000000000000");
	return 0;
    }
    n-=k;
    for(i=1;i<=n;i++)
	for(j=1;j<=min(k,i-1);j++)
	{
	    for(int kill=1;kill<i;kill++)
	    {
		int M=min(kill,j);
		double tmp=0;
		for(int zhong=0;zhong<=M;zhong++)
		{
		    miss=kill-zhong;
		    p=exp(jie[j]+jie[i-j]+jie[kill]+jie[i-kill]-jie[j-zhong]-jie[zhong]-jie[miss]-jie[i-j-miss]-jie[i]);
		    
		    if(j-zhong)
			tmp+=dp[i-kill-min(j-zhong,i-kill-j+zhong)][j-zhong]*p;
		    else
			tmp+=dp[i-kill][0]*p;
		}
		dp[i][j]=max(dp[i][j],tmp);
	    }
	}
    printf("%.12lf\n",dp[n][k]);
}
