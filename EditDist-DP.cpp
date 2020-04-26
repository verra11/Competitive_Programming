#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf LLONG_MAX
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 

ll edit_dist(string s1,string s2)
{
	ll n=s1.length();
	ll m=s2.length();
	ll dp[n+1][m+1];
	for(ll i=0;i<=n;i++)
	{
		dp[i][0]=i;
	}
	for(ll i=0;i<=m;i++)
	{
		dp[0][i]=i;
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			ll x=i+1;
			ll y=j+1;
			if(s1[i]==s2[j])
				dp[x][y]=dp[x-1][y-1];
			else
				dp[x][y]=1+min(dp[x-1][y-1],min(dp[x-1][y],dp[x][y-1]));
		}
	}
	return dp[n][m];
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

	string s1,s2;
	cin>>s1>>s2;
	cout<<edit_dist(s1,s2)<<'\n';
}