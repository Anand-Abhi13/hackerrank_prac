#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
int main()
{
    int n,m,a,b,k;
    ll max=0;
    cin>>n;
    cin>>m;
    ll ans[n]={0};
    for(ll i=1;i<=m;i++)
    {   cin>>a;
        cin>>b;
        cin>>k;
        ans[a-1]=ans[a-1]+k;
        ans[b]=ans[b]-k;

        /*for(int j=0;j<n;j++)
        {
            cout<<ans[j]<<" ";
        }
        cout<<endl;*/
    }
    for(ll i=1;i<n;i++)
        {ans[i]=ans[i]+ans[i-1];
        //cout<<ans[i]<<" ";
        if (ans[i]>max)
            {max=ans[i];}}
    cout<<max;
    return 0;
}
