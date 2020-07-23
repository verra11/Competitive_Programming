/*
	Author: Dinesh Verra
	College: ABV-IIITM
	Date: 02/06/2020
*/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp> 
// using namespace boost::multiprecision; 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define cu continue
#define br break
#define pb push_back
#define mp make_pair
#define mod 998244353
#define inf 1000000000
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 
#define F first
#define S second
#define vll vector <ll>
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define all(v) v.begin(),v.end()

template <typename A1>
void prn(A1&& arg)
{
	cout<<arg<<'\n';
}
template <typename A1, typename... A>
void prn(A1&& arg, A&&... args)
{
	cout<<arg<<' ';
	prn(args...);
}

vll z_function(string& s)
{
	ll l=0,r=0,n=s.length();
	vll z(n,0);
	for(ll i=1;i<n;i++)
	{
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while((i+z[i])<n && s[z[i]]==s[i+z[i]])
			++z[i];
		if((i+z[i]-1)>r)
		{
			l=i,r=i+z[i]-1;
		}
		return z;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("/home/dinesh_verra/cpp/input.txt","r",stdin);
	// freopen("/home/dinesh_verra/cpp/output.txt","w",stdout);
	#endif


}