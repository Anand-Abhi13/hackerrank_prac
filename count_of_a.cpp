
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
    ll n;
    string s;
    cin>>s;
    cin>>n;
    ll l= s.length();
    char char_array[l+ 1];
    strcpy(char_array, s.c_str());
    ll count1=0, count2=0;
    ll len=s.length();
    for(ll i=0;i<len;i++)
    {
        if(char_array[i]=='a')
        {
            count1++;
        }
    }
    for(ll i=0; i<(n%len);i++)
    {
        if(char_array[i]=='a')
        {
            count2++;
        }
    }
    ll fin;
    fin=n/len;
    ll ans;
    ans=count1*fin+count2;
    cout<<ans;
    return 0;

}
