/*
	Author: Dinesh Verra
	College: ABV-IIITM
	Date: 29/04/2020
*/
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
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

	// Using boost library to find 2^1000

	int1024_t x=1;
	for(ll i=0;i<1000;i++) x*=2;
	ll sum=0;
	while(x>0)
	{
		sum+=(x%10);
		x/=10;
	}	
	cout<<sum<<'\n';
}