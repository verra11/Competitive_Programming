/*
	Author: Dinesh Verra
	Date: 17/04/2020
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
    // freopen("/home/dinesh_verra/cpp/output.txt","w",stdout);
    #endif

    // Dividing the number by prime factors
    // maintaining the value of the largest prime factor
    // if the number is >1 after all divisions it is a prime number
    
	ll ans=1,n=600851475143;
	ll x=n;
	for(ll i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			ans=max(ans,i);
			n/=i;
		}
	}
	ans=max(ans,n);
	cout<<ans<<'\n';
}