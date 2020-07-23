/*
	Author: Dinesh Verra
	College: ABV-IIITM
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

bool is_palindrome(ll n)
{
	ll m=n;
	ll p=0;
	while(m>0)
	{
		p*=10;
		p+=(m%10);
		m/=10;
	}
	if(p==n) return true;
	return false;
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

    // Brute force
    // check product of all 3 digit numbers
    // whether a product is a palindrome or not

    ll ans=0;
    for(ll i=101;i<1000;i++)
    {
    	for(ll j=101;j<1000;j++)
    	{
    		if(is_palindrome(i*j)) ans=max(ans,i*j);
    	}
    }
    cout<<ans<<'\n';
}