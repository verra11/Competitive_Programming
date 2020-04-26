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
#define MAX 1000000
#define N   100001
ll spf[MAX];
ll pfx[N];
ll nfx[N];
ll pfy[N];
ll nfy[N];
ll ans;

void sieve()
{
    spf[1]=1;
    for(ll i=2;i<MAX;i++)
        spf[i]=i;
    for(ll i=4;i<MAX;i+=2)
        spf[i]=2;
    for(ll i=3;i*i<MAX;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=i*i;j<MAX;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

vector <pll> genPF(ll x)
{
    vector <ll> v;
    while(x!=1)
    {
        v.pb(spf[x]);
        x/=spf[x];
    }
    sort(v.begin(),v.end());
    vector <pll> p;
    for(ll i=0;i<v.size();i++)
    {
        if(p.size()==0)
        {
            p.pb({v[i],1});
        }
        else if(v[i]==p[p.size()-1].F)
            p[p.size()-1].S++;
        else
            p.pb({v[i],1});
    }
    return p;
}

void findFact(ll a,vector <pll> p,ll currDiv,ll currRes,ll flag)
{
    if(currDiv==p.size())
    {
        if(currRes>100000 || a/currRes>100000) return;
        if(flag&1)
        {
            if((pfy[currRes]&1) && (nfy[a/currRes]&1))
            {
                ans++;
            }

        }
        else
        {
            if((pfx[currRes]&1) && (nfx[a/currRes]&1))
            {
                ans++;
            }
        }
        return;
    }
    for(ll i=0;i<=p[currDiv].S;i++)
    {
        findFact(a,p,currDiv+1,currRes,flag);
        currRes*=p[currDiv].F;
    }
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