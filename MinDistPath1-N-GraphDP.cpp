#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf LLONG_MAX
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 
#define f first
#define s second
const int N=200006;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("/home/r0b0t/Documents/C++/input.txt","r",stdin);
	// freopen("/home/r0b0t/Documents/C++/output.txt","w",stdout);
	#endif

	ll n,m;
	cin>>n>>m;
	map <pair <ll,ll> ,ll> e;
	while(m--)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		e[{x,y}]=w;
		e[{y,x}]=w;
	}
	ll dp[n+1];
	for(ll i=0;i<n+1;i++)
	{
		if(e[{i,1}]==0)
		dp[i]=inf;
		else
		dp[i]=e[{i,1}];
	}
	dp[1]=0;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<=n && j!=i;j++)
		{
			if(dp[j]!=inf && e[{i,j}]!=0)
			{
				dp[i]=min(dp[i],dp[j]+e[{i,j}]);
			}
		}
	}
	cout<<dp[n]<<'\n';
}
