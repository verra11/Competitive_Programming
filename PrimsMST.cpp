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

void add_edges(ll x,bool b[],vector <pair <ll,ll> > v[],min_pq &pq)
{
	b[x]=1;
	for(ll i=0;i<v[x].size();i++)
	{
		if(!b[v[x][i].f])
		{
			pq.push({v[x][i].s,v[x][i].f});
		}
	}
}

void prims_mst(ll s,ll n,vector <pair <ll,ll> > v[])
{
	ll min_cost=0;
	min_pq pq;
	bool b[n+1]={0};
	add_edges(s,b,v,pq);
	while(!pq.empty())
	{
		ll wt=pq.top().f;
		ll x=pq.top().s;
		pq.pop();
		if(b[x])
			continue;
		min_cost+=wt;
		add_edges(x,b,v,pq);
	}
	cout<<min_cost<<'\n';
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
	vector <pair <ll,ll> > v[n+1];
	for(ll i=0;i<m;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		v[x].pb({y,w});
	}
	ll src;
	cin>>src;
	prims_mst(src,n,v);
}