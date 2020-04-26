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

ll lis(string s)
{
	ll n=s.length();
	ll dp[n];
	for(ll i=0;i<n;i++)
		dp[i]=1;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<i;j++)
		{
			if(s[j]<=s[i])
				dp[i]=max(dp[i],1+dp[j]);
		}
	}
	ll mx=0;
	for(ll i=0;i<n;i++)
		mx=max(mx,dp[i]);
	return mx;
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
	cout<<lis(s)<<'\n';
}