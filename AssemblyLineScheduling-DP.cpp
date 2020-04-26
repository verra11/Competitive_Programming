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

ll alschedule(ll *a,ll *t,ll e[],ll x[])
{
	ll T[2][n];
	for(ll i=0;i<n;i++)
	{
		T[0][i]=0;
		T[1][i]=0;
	}
	T[0][0]=e[0]+*(a+0*n+0);
	T[1][0]=e[1]+*(a+n*1+0);
	for(ll j=1;j<n;j++)
	{
		T[0][j]=min(T[0][j-1]+*(a+0*n+j),T[1][j-1]+*(a+0*n+j)+*(t+1*n+j));
		T[1][j]=min(T[1][j-1]+*(a+1*n+j),T[0][j-1]+*(a+1*n+j)+*(t+0*n+j));
	}
	return min(T[0][n-1]+x[0],T[1][n-1]+x[1]);
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
	ll a[2][n],t[2][n];
	for(ll i=0;i<2;i++)
	{
		for(ll j=0;j<n;j++)
			cin>>a[i][j];
	}
	for(ll i=0;i<2;i++)
	{
		for(ll j=0;j<n;j++)
			cin>>t[i][j];
	}
	ll e[2],x[2];
	cin>>e[0]>>e[1]>>x[0]>>x[1];
	cout<<alschedule(&a[0][0],&t[0][0],e,x)<<'\n';
}