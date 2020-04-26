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

ll find(ll x,ll id[])
{
	ll root=x;
	while(root!=id[root])
	{
		root=id[root];
	}
	ll temp;
	while(x!=root)
	{
		temp=id[x];
		id[x]=root;
		x=temp;
	}
	return root;
}

void union_k(ll x,ll y,ll id[],ll size[])
{
	x=find(x,id);
	y=find(y,id);
	if(x==y)
		return;
	if(size[x]<size[y])
	{
		id[x]=id[y];
		size[y]+=size[x];
	}
	else
	{
		id[y]=id[x];
		size[x]+=size[y];
	}
}

ll kruskals(ll n,vector <pair <ll,pll> > &e)
{
	sort(e.begin(),e.end());
	ll min_cost=0;
	ll id[n+1],size[n+1];
	for(ll i=0;i<=n;i++)
	{
		id[i]=i;
		size[i]=1;
	}
	ll components=n;
	for(ll i=0;i<e.size();i++)
	{
		ll wt=e[i].f;
		ll x=e[i].s.f,y=e[i].s.s;
		if(find(x,id)!=find(y,id))
		{
			min_cost+=wt;
			union_k(x,y,id,size);
			components--;
		}
		if(!components)
			break;
	}
	return min_cost;
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
	vector <pair <ll,pll> > e;
	for(ll i=0;i<m;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		v[x].pb({y,w});
		e.pb({w,{x,y}});
	}
	cout<<kruskals(n,e)<<'\n';
}