#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf LLONG_MAX

void dfs(ll node,vector <pair <ll,ll> > v[],bool b[],vector <ll> &tp)
{
	b[node]=1;
	for(ll i=0;i<v[node].size();i++)
	{
		if(!b[v[node][i].f])
		{
			dfs(v[node][i].f,v,b,tp);
		}
	}
	tp.pb(node);
}

void topsort(ll s,ll n,vector <pair <ll,ll> > v[],vector <ll> &tp)
{
	bool b[n+1]={0};
	dfs(s,v,b,tp);
	reverse(tp.begin(),tp.end());
}

ll sssp(ll s,ll d,ll n,vector <pair <ll,ll> > v[])
{
	vector <ll> tp;
	topsort(s,n,v,tp);
	ll dist[n+1];
	for(ll i=0;i<=n;i++)
		dist[i]=inf;
	dist[s]=0;
	for(ll i=0;i<tp.size();i++)
	{
		ll x=tp[i];
		for(ll j=0;j<v[x].size();j++)
		{
			dist[v[x][j].f]=min(dist[v[x][j].f],dist[x]+v[x][j].s);
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
	cout<<sssp(src,dest,n,v)<<'\n';
}