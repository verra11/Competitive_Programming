#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

void dfs(ll x,vector <ll> v[],bool b[])
{
	b[x]=1;
	for(ll i=0;i<v[x].size();i++)
	{
		if(b[v[x][i]]==0)
		{
			dfs(v[x][i],v,b);
		}
	}
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
	vector <ll> v[n+1];
	while(m--)
	{
		ll a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	ll src=1;
	bool vis[n+1]={0};
	dfs(src,v,vis);
}