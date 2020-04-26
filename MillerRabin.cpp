#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define F first
#define S second
#define inf LLONG_MAX
#define mod 1000000007
#define vll vector <ll>
#define pll pair <ll,ll>
#define dbg(n) cout<<n<<' '
#define cu continue
#define br break
#define N 100005

ll modpowexp(ll x,ll y,ll m)
{
    ll res=1;
    x=(x%m);
    while(y>0)
    {
        if(y&1)
            res=(res*x)%m;
        y>>=1;
        x=(x*x)%m;
    }
    return res;
}

bool check_comp(ll n,ll a,ll d,ll s)
{
    ll x=modpowexp(a,d,n);
    if(x==1 || x==n-1)
        return false;
    for(ll i=1;i<s;i++)
    {
        x=(x*x)%n;
        if(x==n-1)
            return false;
    }
    return true;
}

bool MillerRabin(ll n)
{
    if(n<2)
    return false;
    ll s=0;
    ll d=n-1;
    while(!(d&1))
    {
        d>>=1;
        s++;
    }
    for(ll a: {2,3,5,7,11,13,17,19,23,29,31,37})
    {
        if(n==a)
            return true;
        if(check_comp(n,a,d,s))
            return false;
    }
    return true;
}

bool is_prime(ll p)
{
    return MillerRabin(p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/r0b0t/Documents/C++/input.txt","r",stdin);
    // freopen("/home/r0b0t/Documents/C++/output.txt","w",stdout);
    #endif

    
}