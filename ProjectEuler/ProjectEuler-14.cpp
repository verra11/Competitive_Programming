/*
	Author: Dinesh Verra
	College: ABV-IIITM
	Date: 29/04/2020
*/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp> 
// using namespace boost::multiprecision; 
using namespace std;
typedef long long ll;
#define cu continue
#define br break
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf LLONG_MAX
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 
#define F first
#define S second
#define vll vector <ll>
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define N (ll)1e6+1

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("/home/dinesh_verra/cpp/input.txt","r",stdin);
	// freopen("/home/dinesh_verra/cpp/output.txt","w",stdin);
	#endif

	// Brute Force - O (n log n) where n is 10^6

	ll ans=1,num=1;
	for(ll i=2;i<N;i++)
	{
		ll j=i,cnt=1;
		while(j>1)
		{
			if(j&1)
				j=3*j+1;
			else
				j>>=1;
			cnt++;
		}
		if(cnt>=ans)
		{
			ans=cnt;
			num=i;
		}
	}
	cout<<num<<'\n';
}