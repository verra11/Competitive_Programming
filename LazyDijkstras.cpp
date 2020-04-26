#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf LLONG_MAX

//-->priority queue
//indexed pq
//d-ary heap
// fibonacci heap

ll dijkstras(ll s,ll d,ll n,vector <pair <ll,ll> > v[])
{
	priority_queue <pair <ll,ll>,vector <pair <ll,ll> >,greater <pair <ll,ll> > > pq;
	bool b[n+1]={0};
	ll dist[n+1];
	for(ll i=0;i<=n;i++)
		dist[i]=inf;
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		ll val=pq.top().f,x=pq.top().s;
		b[x]=1;
		pq.pop();
		if(val>dist[x])
			continue;
		for(ll i=0;i<v[x].size();i++)
		{
			if(!b[v[x][i].f])
			{
				ll new_dist=dist[x]+v[x][i].s;
				if(dist[v[x][i].f]>new_dist)
				{
					dist[v[x][i].f]=new_dist;
					pq.push({new_dist,v[x][i].f});
				}
			}
		}
	}
	return dist[d];
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
	ll src,dest;
	cin>>src>>dest;
	cout<<dijkstras(src,dest,n,v)<<'\n';
}