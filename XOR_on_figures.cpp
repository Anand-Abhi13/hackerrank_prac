
https://codeforces.com/contest/1270/problem/I
-----------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
 
using ll = unsigned long long;
 
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k;
	cin >> k;
	int n = (1 << k);
	vector<vector<ll> > a(n, vector<ll> (n, 0));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	int t;
	cin >> t;
	vector<pair<int,int> > shape(t);
	for(int i = 0; i < t; i++) cin >> shape[i].first >> shape[i].second;
	for(int r = 0; r < k; r++){
		vector<vector<ll> > b(n, vector<ll>(n, 0));
		for(int c = 0; c < t; c++){
			for(int i = 0; i < (1 << k); i++){
				for(int j = 0; j < (1 << k); j++){
					b[(i + shape[c].first) & ((1 << k) - 1)][(j + shape[c].second) & ((1 << k) - 1)] ^= a[i][j];
				}
			}
		}
		a = b;
		for(int c = 0; c < t; c++){
			shape[c].first = (shape[c].first * 2) % n;
			shape[c].second = (shape[c].second * 2) % n;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(a[i][j]) ans++;
	cout << ans << '\n';
}
----------------------------------------------------------------------------------

//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1007;
 
int n, k;
ll tab[nax][nax];
ll zwr[nax][nax];
 
vector <pii> wek;
 
void rek(int a, int b)
{
	//~ debug() << a << " " << b;
	if (a==1 && b==1)
	{
		zwr[0][0]=tab[0][0];
		return;
	}
	if (a>1)
	{
		for (int i=0; i<a/2; i++)
		{
			for (int j=0; j<b; j++)
			{
				tab[i][j]^=tab[i+a/2][j];
			}
		}
		rek(a/2, b);
		for (int i=0; i<a/2; i++)
		{
			for (int j=0; j<b; j++)
			{
				tab[i][j]^=tab[i+a/2][j];
				zwr[i+a/2][j]=zwr[i][j];
			}
		}
		for (int i=a/2; i<a; i++)
		{
			for (int j=0; j<b; j++)
			{
				for (pii l : wek)
				{
					tab[(i+l.first)%a][(j+l.second)%b]^=zwr[i][j];
				}
			}
		}
		rek(a/2, b);
		for (int i=a/2; i<a; i++)
		{
			for (int j=0; j<b; j++)
			{
				for (pii l : wek)
					tab[(i+l.first)%a][(j+l.second)%b]^=zwr[i][j];
				zwr[i][j]^=zwr[i-a/2][j];
			}
		}
		return;
	}
	for (int i=0; i<a; i++)
	{
		for (int j=0; j<b/2; j++)
		{
			tab[i][j]^=tab[i][j+b/2];
		}
	}
	rek(a, b/2);
	for (int i=0; i<a; i++)
	{
		for (int j=0; j<b/2; j++)
		{
			tab[i][j]^=tab[i][j+b/2];
			zwr[i][j+b/2]=zwr[i][j];
		}
	}
	for (int i=0; i<a; i++)
	{
		for (int j=b/2; j<b; j++)
		{
			for (pii l : wek)
			{
				tab[(i+l.first)%a][(j+l.second)%b]^=zwr[i][j];
			}
		}
	}
	rek(a, b/2);
	for (int i=0; i<a; i++)
	{
		for (int j=b/2; j<b; j++)
		{
			for (pii l : wek)
				tab[(i+l.first)%a][(j+l.second)%b]^=zwr[i][j];
			zwr[i][j]^=zwr[i][j-b/2];
		}
	}
}
 
int main()
{
	scanf("%d", &n);
	for (int i=0; i<(1<<n); i++)
	{
		for (int j=0; j<(1<<n); j++)
		{
			scanf("%lld", &tab[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i=0; i<k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		wek.push_back({a, b});
	}
	rek(1<<n, 1<<n);
	
	
	//~ for (int i=0; i<(1<<n); i++)
		//~ debug() << range(zwr[i], zwr[i]+(1<<n));
	ll wyn=0;
	for (int i=0; i<(1<<n); i++)
		for (int j=0; j<(1<<n); j++)
			wyn+=(zwr[i][j]>0);
	printf("%lld\n", wyn);
	return 0;
}