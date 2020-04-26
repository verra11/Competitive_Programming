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

ll lps(string s)
{
	ll n=s.length();
	ll dp[n][n];
	for(ll i=0;i<n;i++)
		dp[i][i]=1;
	for(ll k=2;k<=n;k++)
	{
		for(ll i=0;i<=n-k;i++)
		{
			ll j=i+k-1;
			if(k==2 && s[i]==s[j])
			{
				dp[i][j]=2;
			}
			else if(s[i]!=s[j])
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
			else
			{
				dp[i][j]=2+dp[i+1][j-1];
			}
		}
	}
	return dp[0][n-1];
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

	string s;
	cin>>s;
	cout<<lps(s)<<'\n';
}