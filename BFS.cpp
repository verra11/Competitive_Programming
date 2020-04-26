#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

void bfs(ll x,vector <ll> v[],bool b[])
{
	b[x]=1;
	queue <ll> q;
	q.push(x);
	while(!q.empty())
	{
		ll node=q.front();cout<<node<<'\n';
		q.pop();
		for(ll i=0;i<v[node].size();i++)
		{
			if(b[v[node][i]]==0)
			{
				b[v[node][i]]=1;
				q.push(v[node][i]);
			}
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
	bfs(src,v,vis);
}