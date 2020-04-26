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

ll min_diff_partition(ll n,ll a[])
{
	ll sum=0;
	for(ll i=0;i<n;i++)
		sum+=a[i];
	ll dp[n+1][sum+1];
	for(ll i=1;i<=sum;i++)
		dp[0][i]=0;
	for(ll i=0;i<=n;i++)
		dp[i][0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=sum;j++)
		{
			dp[i][j]=0;
			dp[i][j]|=dp[i-1][j];
			if(j-a[i-1]>=0)
				dp[i][j]|=dp[i-1][j-a[i-1]];
		}
	}
	ll mn=inf;
	for(ll j=0;j<=sum/2;j++)
	{
		if(dp[n][j]==1)
			mn=min(mn,sum-2*j);
	}
	return mn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("/home/r0b0t/Documents/C++/input.txt","r",stdin);
	// freopen("/home/r0b0t/Documents/C++/output.txt","w",stdout);
	#endif

	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	cout<<min_diff_partition(n,a)<<'\n';
}