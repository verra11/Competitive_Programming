/*
	Author: Dinesh Verra
	College: ABV-IIITM
	Date: 18/04/2020
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

    // Bruteforce

    ll ans=0;
    for(ll i=1;i<1000;i++)
    {
    	for(ll j=1;j<1000;j++)
    	{
    		ll k=1000-i-j;
    		if(k<=0) br;
    		if((i*i+j*j)==k*k)
    			ans=i*j*k;
    	}
    }
    cout<<ans<<'\n';
}