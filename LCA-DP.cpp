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

ll D,n;

void bfs_lca(ll s,vector <ll> v[],ll lvl[],ll *p)
{
	bool b[n+1]={0};
	queue <ll> q;
	q.push(s);
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		b[x]=1;
		for(ll i=0;i<v[x].size();i++)
		{
			if(!b[v[x][i]])
			{
				q.push(v[x][i]);
				lvl[v[x][i]]=1+lvl[x];
				*(p+(n+1)*0+v[x][i])=x;
			}
		}
	}

	for(ll k=1;k<=D;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			ll mid=*(p+(n+1)*(k-1)+i);
			if(mid!=-1)
				*(p+(n+1)*k+i)=*(p+(n+1)*(k-1)+mid);
		}
	}
}

ll walk(ll i,ll k,ll *p)
{
	for(ll d=0;d<=D && i!=-1;d++)
	{
		if(((1<<d)&k)>0)
			i=*(p+(n+1)*d+i);
	}
	return i;
}

ll lca(ll x,ll y,ll lvl[],ll *p)
{
	if(lvl[x]>lvl[y])
		x=walk(x,lvl[x]-lvl[y],p);
	if(lvl[y]>lvl[x])
		y=walk(y,lvl[y]-lvl[x],p);
	if(x==y)
		return x;
	for(ll d=D;d>=0;d--)
	{
		if(*(p+(n+1)*d+x)!=*(p+(n+1)*d+y))
		{
			x=*(p+(n+1)*d+x);
			y=*(p+(n+1)*d+y);
		}
	}
	return *(p+(n+1)*0+x);
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

	ll q;
	cin>>n>>q;
	ll m=n-1;
	vector <ll> v[n+1];
	for(ll i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	D=(ll)floor(log2(n));
	ll lvl[n+1]={0},p[D+1][n+1];
	for(ll i=0;i<=D;i++)
		for(ll j=0;j<=n;j++)
			p[i][j]=-1;
	bfs_lca(1,v,lvl,&p[0][0]);
	cout<<lca(3,5,lvl,&p[0][0])<<'\n';
}