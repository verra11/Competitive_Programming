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
#define N (ll)(2e6+1)
bool prime[N];
ll sum=0;

void sieve()
{
	memset(prime,true,sizeof prime);
	prime[0]=0;
	prime[1]=0;
	for(ll i=2;i*i<N;i++)
		if(prime[i])
		{
			for(ll j=i*i;j<N;j+=i)
				prime[j]=0;
		}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("/home/dinesh_verra/cpp/input.txt","r",stdin);
	// freopen("/home/dinesh_verra/cpp/output.txt","w",stdin);
	#endif

	// Using Sieve of eratosthenes to find primes under 2 million in O(n root n)

	sieve();
	for(ll i=2;i<N;i++) if(prime[i]) sum+=i;
	cout<<sum<<'\n';
}