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

ll n;

ll optstrat(ll a[],ll i,ll j,ll sum,ll *dp)
{
	if(j==i+1)
		return max(a[i],a[j]);
	if(*(dp+i*n+j)!=-1)
		return *(dp+i*n+j);
	return *(dp+i*n+j)=max(sum-optstrat(a,i+1,j,sum-a[i],dp),sum-optstrat(a,i,j-1,sum-a[j],dp));
}

ll solve(ll a[])
{
	ll sum=0,dp[n][n];
	for(ll i=0;i<n;i++)
		sum+=a[i];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			dp[i][j]=-1;
	return optstrat(a,0,n-1,sum,&dp[0][0]);
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

	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	cout<<solve(a)<<'\n';
}