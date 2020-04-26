#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define f first
#define s second
#define inf 1000000000
#define min_pq priority_queue <pair <ll,ll> ,vector <pair <ll,ll> >, greater <pair <ll,ll> > > 

/* Iterative Segment tree with :
	-Point update
	-Range sum queries
*/

const ll N=1e5;

ll n;
ll t[2*N];

void build()
{
	for(ll i=n-1;i>0;i--)
		t[i]=t[i<<1]+t[i<<1|1];
}

void modify(ll p,ll val)
{
	for(t[p+=n]=val;p>1;p>>=1)
		t[p>>1]=t[p]+t[p^1];
}

ll query(ll l,ll r)
{
	ll res=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
			res+=t[l++];
		if(r&1)
			res+=t[--r];
	}
	return res;
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

	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>t[n+i];
	build();
	ll q;
	cin>>q;
	while(q--)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		if(x&1)
		{
			modify(y,z);
		}
		else
		{
			cout<<query(y,z+1)<<'\n';
		}
	}
}