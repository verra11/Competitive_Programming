#include <bits/stdc++.h>
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

void lps(ll f[],string s)
{
	ll k=1;
	ll n=s.length();
	f[0]=0;
	for(ll i=1;i<n;i++)
	{
		ll j=f[i-1];
		while(j>0 && s[i]!=s[j])
			j=f[j-1];
		if(s[i]==s[j]) ++j;
		f[i]=j;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("/home/dinesh_verra/cpp/input.txt","r",stdin);
    // freopen("/home/r0b0t/Documents/C++/output.txt","w",stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	ll n=s.length();
    	string x="",y="";
    	ll cnt=0;
    	for(ll i=0;i<n/2;i++)
    	{
    		if(s[i]==s[n-i-1])
    		{
    			x+=s[i];
    			cnt++;
    		}
    		else
    			br;
    	}
    	y=x;
    	reverse(y.begin(),y.end());
    	string tmp="";
    	for(ll i=cnt;i<n-cnt;i++)
    		tmp+=s[i];
    	string tmp2=tmp;
    	reverse(tmp2.begin(),tmp2.end());
    	string a=tmp+"#"+tmp2;
    	string b=tmp2+"#"+tmp;
    	ll A=a.length(),B=b.length();
    	ll lpsa[A+1],lpsb[B+1];
    	lps(lpsa,a);
    	lps(lpsb,b);
    	tmp="";
    	tmp2="";
    	if(lpsa[A-1]>lpsb[B-1] && a.size()>1)
    	{
    		for(ll i=0;i<lpsa[A-1];i++)
    			tmp+=a[i];
    	}
    	else if(b.size()>1)
    	{
    		for(ll i=0;i<lpsb[B-1];i++)
    			tmp+=b[i];
    		if(tmp.empty())
    		tmp+=b[0];
    	}
    	cout<<x+tmp+y<<'\n';
    }
}       
