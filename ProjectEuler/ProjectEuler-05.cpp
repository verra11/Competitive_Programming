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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("/home/dinesh_verra/cpp/input.txt","r",stdin);
    // freopen("/home/dinesh_verra/cpp/output.txt","w",stdout);
    #endif

    // maintain a variable to store ans
    // keep updating it by multiplying it with num/(gcd(num,ans))
    // for all num from 1 to 20

    ll ans=1;
    for(ll i=2;i<=20;i++)
    	ans*=(i/__gcd(ans,i));
    cout<<ans<<'\n';
}