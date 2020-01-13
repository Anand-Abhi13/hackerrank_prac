
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
/*int leftrotate(int n, int d, int ar[n])
{   int temp,temp2;
    for (i=0;i<n-1;i++)
    {   if(i==0)
    {
        temp=ar[n-1];
        ar[n-1]=ar[0];
    }
        if(i==n-1)
        {
            ar[n-1]=temp;
        }
        temp2=ar[i];
        ar[i]=ar[i+1];
    }
}*/
int main()
{
    boost1;boost2;
    ll n,i,j,d;
    cin>>n;
    cin>>d;
    int ar[n], newar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    if(d>n)
    {
        d=d%n;
    }
    int init=n-d;
    for(i=0;i<d;i++)
    {
        newar[init]=ar[i];
        init++;
    }
    init=0;
    for(i=d;i<n;i++)
    {
        newar[init]=ar[i];
        init++;
    }
    for(int k=0;k<n;k++)
    {cout<<newar[k]<<" ";
    }
    return 0;
}
