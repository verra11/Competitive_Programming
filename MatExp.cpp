#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define pb push_back
#define F first
#define S second
#define inf LLONG_MAX
#define mod 1000000007
#define PI 3.1415926536
#define vll vector <ll>
#define pll pair <ll,ll>
#define dbg(n) cout<<n<<' '
#define cu continue
#define br break

ll M[2][2],A[2][1];

void mul(ll x[2][2],ll y[2][2])
{
    ll temp[2][2];
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            temp[i][j]=0;
            for(ll k=0;k<2;k++)
            {
                temp[i][j]=(temp[i][j]+(x[i][k]*y[k][j]))%mod;
            }
        }
    }
    y[0][0]=temp[0][0];
    y[0][1]=temp[0][1];
    y[1][0]=temp[1][0];
    y[1][1]=temp[1][1];
}

void modpowexp(ll y)
{
    ll res[2][2]={{1,0},{0,1}};
    while(y>0)
    {
        if(y&1)
            mul(M,res);
        y>>=1;
        mul(M,M);
    }
    M[0][0]=res[0][0];
    M[0][1]=res[1][0];
    M[1][0]=res[0][1];
    M[1][1]=res[1][1];
}

ll fib(ll n)
{
    M[0][0]=1;
    M[0][1]=1;
    M[1][0]=1;
    M[1][1]=0;

    A[0][0]=1;
    A[1][0]=1;
    modpowexp(n);
    return ((M[0][0]*A[0][0])%mod+(M[0][1]*A[1][0])%mod)%mod;
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

    ll t;
    cin>>t;
    while(t--)
    {
        char c;
        ll n;
        cin>>c>>n;
        if(c=='m')
            n--;
        cout<<fib(n)<<'\n';
    }
}