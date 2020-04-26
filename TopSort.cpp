#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

void dfs(ll x,vector <ll> v[],bool b[],vector <ll> *tp)
{
	b[x]=1;
	for(ll i=0;i<v[x].size();i++)
	{
		if(!b[v[x][i]])
		{
			dfs(v[x][i],v,b,tp);
		}
	}
	tp->pb(x);
}

void top_sort(vector <ll> v[],ll n)
{
	bool b[n+1]={0};
	vector <ll> tp;
	for(ll i=1;i<=n;i++)
	{
		if(!b[i])
			dfs(i,v,b,&tp);
	}
	reverse(tp.begin(),tp.end());
	for(auto x:tp)
		cout<<x<<' ';
	cout<<'\n';
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
	top_sort(v,n);
}