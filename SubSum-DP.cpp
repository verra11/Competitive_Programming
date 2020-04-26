#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf 1000000000
#define min_pq priority_queue <pair <ll,ll> ,vector <pair <ll,ll> >, greater <pair <ll,ll> > > 

string solve(ll a[],ll n,ll k)
{
	ll dp[n+1][k+1];
	for(ll i=0;i<=n;i++)
		dp[i][0]=1;
	for(ll i=0;i<=k;i++)
		dp[0][i]=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=k;j++)
		{
			dp[i][j]=0;

			dp[i][j]|=dp[i-1][j];
			if(j-a[i]>=0)
				dp[i][j]|=dp[i-1][j-a[i]];
		}
	}
	if(dp[n][k]&1)
		return "YES";
	else
		return "NO";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif

	ll n,k;
	cin>>n>>k;
	ll a[n+1];
	for(ll i=0;i<n;i++)
		cin>>a[i+1];
	cout<<solve(a,n,k)<<'\n';
}