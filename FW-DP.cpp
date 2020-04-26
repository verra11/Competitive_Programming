#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf 10000

ll floyd_warshall(ll s,ll d,ll n,ll *a)
{
	ll m[n][n],next[n][n];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
		{
			if(i==j)
				m[i][j]=0;
			else if(*(a+i*n+j)==0)
				m[i][j]=inf;
			else
			{
				m[i][j]=*(a+i*n+j);
			}
			if(m[i][j]!=inf)
			next[i][j]=j;
		}

	for(ll k=0;k<n;k++)
	{
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				if(m[i][j]>m[i][k]+m[k][j])
				{
					m[i][j]=m[i][k]+m[k][j];
					next[i][j]=next[i][k];
				}
			}
		}
	}

	ll x=s;
	while(x!=d)
	{
		cout<<x<<" ";
		x=next[x][d];
	}
	cout<<x<<" ";
	cout<<'\n';
	return m[s][d];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	ll n,m;
	cin>>n>>m;
	ll a[n][n];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			a[i][j]=0;
	for(ll i=0;i<m;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		--x;--y;
		a[x][y]=w;
	}
	ll src,dest;
	cin>>src>>dest;
	--src;--dest;
	cout<<floyd_warshall(src,dest,n,&a[0][0])<<'\n';
}