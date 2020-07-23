/*
	Author: Dinesh Verra
	College: ABV-IIITM
	Date: 03/07/2020
	https://www.codechef.com/ENJU2020/problems/ECJN207
	DIGIT DP
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
#define eb emplace_back
#define mod 1000000007
#define inf 1000000000
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 
#define F first
#define S second
#define vll vector <ll>
#define vpll vector <pll>
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define all(v) v.begin(),v.end()
#define nl cout<<'\n'

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

#define N 105
#define M 100005

ll f[N];
bool p[M];
ll dp[N][2600][2];

void sieve()
{
	for(ll i=0;i<M;i++) p[i]=1;
	p[0]=p[1]=0;
	for(ll i=2;i*i<M;i++)
		if(p[i])
			for(ll j=i*i;j<M;j+=i)
				p[j]=0;
}

ll solve(ll pos, ll n, ll sum, ll flag)
{
	if(pos>n)
	{
		if(p[sum]) return 1;
		return 0;
	}

	if(dp[pos][sum][flag]!=-1) return dp[pos][sum][flag];

	ll limit=25,res=0,fl;
	if(flag) limit=f[pos];

	for(ll i=0;i<=limit;i++)
	{
		if(!flag || i<limit) fl=0;
		else fl=1;

		if(p[pos-1])
			res=(res+solve(pos+1,n,sum+i,fl))%mod;
		else
			res=(res+solve(pos+1,n,sum,fl))%mod;
	}

	return dp[pos][sum][flag]=res;
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

	sieve();
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll n=s.length();
		memset(dp, -1, sizeof dp);
		for(ll i=0;i<n;i++)
			f[i+1]=(s[i]-'a');
		prn(solve(1,n,0,1));
	}
}