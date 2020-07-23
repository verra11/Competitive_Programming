#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf 1000000000
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 

ll egg_drop(ll k,ll n)
{
	ll dp[k+1][n+1];
	for(ll i=0;i<=n;i++)
	{
		dp[0][i]=0;
		dp[1][i]=i;
	}
	for(ll i=0;i<=k;i++)
	{
		dp[i][0]=0;
		dp[i][1]=1;
	}
	for(ll i=2;i<=k;i++)
	{
		for(ll j=2;j<=n;j++)
		{
			dp[i][j]=inf;
			for(ll x=1;x<=j;x++)
			{
				dp[i][j]=min(dp[i][j],1+max(dp[i-1][x-1],dp[i][j-x]));
			}
		}
	}
	return dp[k][n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("/home/dinesh_verra/cpp/input.txt","r",stdin);
	// freopen("/home/r0b0t/Documents/C++/output.txt","w",stdout);
	#endif

	ll t;
	cin>>t;
	while(t--)
	{
		ll k,n;
		cin>>k>>n;
		cout<<egg_drop(k,n)<<'\n';
	}
}