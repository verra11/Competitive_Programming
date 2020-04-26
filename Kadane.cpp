#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define F first
#define S second
#define inf LLONG_MAX
#define mod 1000000007
#define PI 3.1415926536
#define vll vector <ll>
#define pll pair <ll,ll>
#define dbg(n) cout<<n<<' '
#define cu continue
#define br break
#define MAX 1000005
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 

ll kadane(ll a[],ll n)
{
	ll s=0,mx=-inf;
	for(ll i=0;i<n;i++)
	{
		s+=a[i];
		mx=max(mx,s);
		s=max(s,0ll);
	}
	return mx;
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

	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	cout<<kadane(a,n)<<'\n';
}	