#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define F first
#define S second
#define inf 1000000000
#define mod 1000000007
#define vll vector <ll>
#define pll pair <ll,ll>
#define dbg(n) cout<<n<<' '
#define cu continue
#define br break
string s;

/*  Calculates/Evaluates expressions in the form (x4(y2z3)3)2   
    To calculate atomic weights.    */


ll val(char c)
{
    return c=='x'? 2:(c=='y'? 4:10);
}

ll dfs(ll L,ll R)
{
    if(s[L]=='(')
    {
        ll top=0;
        for(ll i=L;i<=R;i++)
        {
            if(s[i]=='(') top--;
            if(s[i]==')') top++;
            if(top!=0) cu;
            ll cnt=0;
            for(ll j=i+1;j<=R;j++)
            {
                if(s[j]>='0' && s[j]<='9') cnt=(cnt*10+(s[j]-'0'));
                else
                    return max(1ll,cnt)*dfs(L+1,i-1)+dfs(j,R);
            }
            return max(cnt,1ll)*dfs(L+1,i-1);
        }
    }
    ll cnt=0;
    for(ll i=L+1;i<=R;i++)
    {
        if(s[i]>='0' && s[i]<='9') cnt=(cnt*10+(s[i]-'0'));
        else
        return max(cnt,1ll)*val(s[L])+dfs(i,R);
    }
    return max(1ll,cnt)*val(s[L]);
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
        s.clear();
        cin>>s;
        ll n=s.length();
        cout<<dfs(0,n-1)<<'\n';
    }
}