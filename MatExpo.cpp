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

void multiply(ll a[4][4],ll b[4][4])
{
	ll mul[4][4];
	for(ll i=0;i<4;i++)
		for(ll j=0;j<4;j++)
		{
			mul[i][j]=0;
			for(ll k=0;k<4;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];
				mul[i][j]%=mod;
			}
		}

	for(ll i=0;i<4;i++)
		for(ll j=0;j<4;j++)
			a[i][j]=mul[i][j];
}

ll modpow(ll F[4][4],ll n)
{
	ll res[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	
	while(n>0)
	{
		if(n&1)
			multiply(res,F);
		n>>=1;
		multiply(F,F);
	}
	return (2*res[0][0]+res[0][1]+5*res[0][2]+res[0][3])%mod;
}

ll solve(ll n)
{
	ll F[4][4]={{2,3,1,0},{1,0,0,0},{0,0,2,3},{0,0,1,0}};
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	return modpow(F,n-1);
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

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<solve(n)<<'\n';
	}
}