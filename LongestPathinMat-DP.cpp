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

ll findpath(ll i,ll j,ll *a,ll *dp,ll n)
{
	ll x=0,y=0,z=0,w=0;
	if(i<0 || j<0 || i>=n || j>=n)
		return 0;
	if(*(dp+i*n+j)!=-1)
		return *(dp+i*n+j);
	if(i<n-1 && (*(a+i*n+j)+1==*(a+(i+1)*n+j)))
		x=1+findpath(i+1,j,a,dp,n);
	if(j<n-1 && (*(a+i*n+j)+1==*(a+i*n+(j+1))))
		y=1+findpath(i,j+1,a,dp,n);
	if(i>0 && (*(a+i*n+j)+1==*(a+(i-1)*n+j)))
		z=1+findpath(i-1,j,a,dp,n);
	if(j>0 && (*(a+i*n+j)+1==*(a+i*n+(j-1))))
		w=1+findpath(i,j-1,a,dp,n);
	return max(x,max(y,max(z,max(w,1ll))));
}

ll solve(ll *a,ll n)
{
	ll dp[n][n],res=0;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			dp[i][j]=-1;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
		{
			if(dp[i][j]==-1)
				dp[i][j]=findpath(i,j,a,&dp[0][0],n);
			res=max(res,dp[i][j]);
		}

	return res;
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

	ll n;
	cin>>n;
	ll a[n][n];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin>>a[i][j];
	cout<<solve(&a[0][0],n)<<'\n';
}