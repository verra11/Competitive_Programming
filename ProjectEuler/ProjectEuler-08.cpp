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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("/home/dinesh_verra/cpp/input.txt","r",stdin);
	// freopen("/home/dinesh_verra/cpp/output.txt","w",stdin);
	#endif

	// Brute-force

	string s;
	cin>>s;
	ll n=s.length();
	ll mx=0;
	for(ll i=0;i<(n-13);i++)
	{
		ll tmp=1;
		for(ll j=i;j<13+i;j++)
		{
			tmp*=(s[j]-'0');
		}
		mx=max(mx,tmp);
	}
	cout<<mx<<'\n';
}