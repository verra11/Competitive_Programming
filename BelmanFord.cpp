#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf LLONG_MAX

void belman_ford(ll s,ll d,ll n,vector <pair <pair <ll,ll>,ll > > e)
{
	ll dist[n+1];
	for(ll i=0;i<=n;i++)
		dist[i]=inf;
	dist[s]=0;
	for(ll i=0;i<n-1;i++)
	{
		for(ll j=0;j<e.size();j++)
		if(dist[e[j].f.s]>dist[e[j].f.f]+e[j].s)
			dist[e[j].f.s]=dist[e[j].f.f]+e[j].s;
	}
	// for(ll i=0;i<n-1;i++)
	// {
	// 	for(ll j=0;j<e.size();j++)
	// 	if(dist[e[j].f.s]>dist[e[j].f.f]+e[j].s)
	// 		dist[e[j].f.s]=-inf; //negative cycles
	// }
	cout<<dist[d]<<endl;
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
	vector <pair <pair <ll,ll>,ll> > e;
	for(ll i=0;i<m;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		e.pb({{x,y},w});
	}
	ll src,dest;
	cin>>src>>dest;

	belman_ford(src,dest,n,e);
}