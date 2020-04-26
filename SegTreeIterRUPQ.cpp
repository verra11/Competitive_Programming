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
	-Range updates
	-Point queries
*/

const ll N=1e5;

ll n;
ll t[2*N];

void modify(ll l,ll r,ll val)
{
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
			t[l++]+=val;
		if(r&1)
			t[--r]+=val;
	}
}

ll query(ll p)
{
	ll res=0;
	for(p+=n;p>0;p>>=1)
		res+=t[p];
	return res;
}

void push()
{
	for(ll i=1;i<n;i++)
	{
		t[i<<1]+=t[i];
		t[i<<1|1]+=t[i];
		t[i]=0;
	}
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
	ll q;
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		if(x&1)
		{
			ll y,z,w;
			cin>>y>>z>>w;
			modify(y,z+1,w);
		}
		else
		{
			ll y;
			cin>>y;
			cout<<query(y)<<'\n';
		}
	}
}