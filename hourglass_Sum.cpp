
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
    ll n,i,j;
    int temp=0,sum=-63,a[6][6];
    for(i=0;i<6;i++)
    {

        for(j=0;j<6;j++)
        {
            cin>>a[i][j];
        }
    }
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            cout<<a[i][j]<<endl;
            temp = a[i][j]+a[i][j+1]+a[i][j+2]+ a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            cout<<"temp is"<<temp<<endl;

            if (temp>sum)
            {
                cout<<temp;
                sum=temp;

            }
        }
    }
    cout<<sum;
    return 0;
}
