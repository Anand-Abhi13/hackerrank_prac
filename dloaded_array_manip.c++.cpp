#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,i,j,k;
long long maxi,a[10000009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
while(m)
{
    m--;
    scanf("%d",&i);
    scanf("%d",&j);
    scanf("%d",&k);
    a[i]+=k;
    a[j+1]-=k;
}
for(i=1;i<=n;i++)
{
    a[i]+=a[i-1];
    if(a[i]>maxi) maxi=a[i];
}
printf("%lld\n",maxi);
return 0;
}
