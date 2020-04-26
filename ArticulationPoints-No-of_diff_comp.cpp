#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf 1000000000
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 

ll cnt,tote,totv,timer;
vector <ll> diff_cmp(100001,0);

void dfs(ll x,vector <ll> v[],bool b[],ll p[],ll comp[])
{
	b[x]=1;
	comp[x]=cnt;
	totv++;
	tote+=v[x].size();
	for(ll i=0;i<v[x].size();i++)
	{
		if(b[v[x][i]]==0)
		{
			p[v[x][i]]=x;
			dfs(v[x][i],v,b,p,comp);
		}
	}
}

void dfs2(ll x,bool b[],ll tin[],ll low[],vector <ll> v[],ll p=-1)
{
	b[x]=1;
	tin[x]=timer;
	low[x]=timer;
	timer++;
	ll children=0;
	bool ap=0;
	ll f=0;
	for(ll i=0;i<v[x].size();i++)
	{
		if(v[x][i]==p)
			continue;
		if(b[v[x][i]])
			low[x]=min(low[x],tin[v[x][i]]);
		else
		{
			dfs2(v[x][i],b,tin,low,v,x);
			low[x]=min(low[x],low[v[x][i]]);
			if(low[v[x][i]]>=tin[x] && p!=-1)
			{
				ap=1;
			}
			else
				f++;
			++children;
		}
	}
	
	if(ap && p!=-1)
		diff_cmp[x]=children-f+1;
	else
		diff_cmp[x]=1;

	if(p==-1 && children>1)
	{
		diff_cmp[x]=children;
	}
}

void find_ap(ll n,vector <ll> v[])
{
	timer=0;
	bool b[n+1]={0};
	ll tin[n+1],low[n+1];
	for(ll i=0;i<=n;i++)
	{
		tin[i]=-1;
		low[i]=-1;
	}
	for(ll i=1;i<=n;i++)
		if(!b[i])
			dfs2(i,b,tin,low,v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("/home/r0b0t/Documents/C++/input.txt","r",stdin);
	// freopen("/home/r0b0t/Documents/C++/output.txt","w",stdout);
	#endif

	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector <ll> v[n+1];
		for(ll i=0;i<m;i++)
		{
			ll x,y;
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		bool b[n+1]={0};
		ll comp[n+1]={0},p[n+1]={0};
		vector <pair <ll,ll> > ve;
		cnt=0;
		timer=0;
		for(ll i=1;i<=n;i++)
		{
			tote=0;
			totv=0;
			if(b[i]==0)
			{
				dfs(i,v,b,p,comp);
				tote/=2;
				ve.pb({totv,tote});
				cnt++;
			}
		}
		ll cyc[cnt]={0};
		for(ll i=0;i<cnt;i++)
		{
			if(ve[i].s>=ve[i].f)
				cyc[i]=1;
		}
		ll temp=0,idx=-1;
		for(ll i=0;i<cnt;i++)
			if(cyc[i]==1)
			{
				temp++;
				idx=i;
			}
		if(temp!=1)
		{
			cout<<-1<<'\n';
			continue;
		}

		find_ap(n,v);

		// for(ll i=1;i<=n;i++)
		// 	cout<<diff_cmp[i]<<" ";
		// cout<<endl;
		ll mn=inf;
		ll te=ve[idx].s,tv=ve[idx].f;
		for(ll i=1;i<=n;i++)
		{
			if(comp[i]==idx)
			{
				ll tempv=tv-1;
				ll tempe=te-v[i].size();
				ll k=diff_cmp[i];

				if(tempe<=(tempv-k))
				{
					mn=min(mn,i);
				}
			}
		}
		if(mn==inf)
			mn=-1;
		cout<<mn<<'\n';
	}
}