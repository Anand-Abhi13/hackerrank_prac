//It’s never too late to become what you might have been....
 #include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define S second
#define F first
#define boost1 ios::sync_with_stdio(false);
#define boost2 cin.tie(0);
#define mem(a,val) memset(a,val,sizeof a)
#define endl "\n"
#define maxn 100001
ll cnt[200];
int main()
{
	boost1;boost2;
	ll i,j,n,x,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		cnt[x]++;
	}
	for(i=1;i<=100;i++)
	ans+=cnt[i]/2;
	cout<<ans;
	return 0;
}