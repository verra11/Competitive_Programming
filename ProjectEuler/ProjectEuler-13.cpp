/*
	Author: Dinesh Verra
	College: ABV-IIITM
	Date: 02/05/2020
*/
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define cu continue
#define br break
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 1000000000000
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

	// Using Boost library

	ll n=100;
	int512_t x,s=0;
	for(ll i=0;i<n;i++)
	{
		cin>>x;
		s+=x;
	}
	int512_t tmp=s;
	ll cnt=0;
	while(tmp>0)
	{
		cnt++;
		tmp/=10;
	}
	while(cnt>10)
	{
		cnt--;
		s/=10;
	}
	cout<<s<<endl;
}