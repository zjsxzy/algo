#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
 
int t,R,C,m,n,r[25],c[25],d,X,Y,tot,temp,out;
bool br[105],bc[105];
 
void dfs(int z)
{
//printf("%d  %d\n",z,tot);
	if (tot<out)
	{
		if (z==n)
		{
			if (tot>=n+m)
			{
				out=tot;
			}
			else
			{
				for (int i=0; i<=R-X; i++)
				{
					temp=tot+i*(C-Y);
					if (temp>=n+m)
					{
						out=min(out,temp);
					}
					else
					{
						temp+=((n+m-temp+(R-X-i)-1)/(R-X-i))*(R-X-i);
						out=min(out,temp);
					}
				}
			}
		}
		else
		{
//printf("%d  row     %d\n",z,tot);
			if (br[r[z]])
			{
				br[r[z]]=false;
				X++;
				tot+=C-Y;
				dfs(z+1);
				br[r[z]]=true;
				X--;
				tot-=C-Y;
			}
			else
			{
				dfs(z+1);
			}
//printf("%d  col      %d                                %d  %d\n",z,tot,c[4],bc[c[4]]);
			if (bc[c[z]])
			{
				bc[c[z]]=false;
				Y++;
				tot+=R-X;
//printf("%d  col      %d\n",z,tot);
				dfs(z+1);
				bc[c[z]]=true;
				Y--;
				tot-=R-X;
			}
			else
			{
				dfs(z+1);
			}
		}
	}
}
 
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d",&R,&C,&n,&m);
//printf("%d %d %d %d\n",R,C,n,m);
		for (int i=0; i<n; i++)
		{
			scanf("%d%d%d",&r[i],&c[i],&d);
//printf("%d %d %d\n",r[i],c[i],d);
		}
		X=0;
		Y=0;
		memset(br,true,sizeof(br));
		memset(bc,true,sizeof(bc));
//printf("bc[46]                 %d\n",bc[46]);
		tot=0;
		out=10000;
		dfs(0);
		printf("%d\n",out);
	}
	return 0;
}