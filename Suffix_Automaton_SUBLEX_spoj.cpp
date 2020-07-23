/*
	Author: Dinesh Verra
	College: ABV-IIITM
	Date: 11/06/2020
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
#define mp make_pair
#define mod 1000000007
#define inf 1000000000
#define pll pair <ll,ll>
#define min_pq priority_queue <pll> ,vector <pll>, greater <pll> > > 
#define F first
#define S second
#define vll vector <ll>
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define all(v) v.begin(),v.end()

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

#define N 100005

struct state
{
	ll len,link,next[26];
};

ll pos=0;
ll sz=0,last;
struct state st[2*N];
ll dp[2*N];
bool vis[2*N];

void sa_init()
{
	last=0;
	sz++;
	st[0].len=0;
	st[0].link=-1;
	for(ll i=0;i<26;i++)
		st[0].next[i]=-1;
}

void sa_extend(char c)
{
	ll cur=sz++;
	st[cur].len=st[last].len+1;
	for(ll i=0;i<26;i++) st[cur].next[i]=-1;
	dp[cur]=1;

	ll p=last;
	while(p!=-1 && st[p].next[c-'a']==-1)
	{
		st[p].next[c-'a']=cur;
		p=st[p].link;
	}
	if(p==-1)
		st[cur].link=0;
	else
	{
		ll q=st[p].next[c-'a'];
		if((st[p].len+1)==st[q].len)
			st[cur].link=q;
		else
		{
			ll clone=sz++;
			dp[clone]=1;
			st[clone].len=st[p].len+1;
			st[clone].link=st[q].link;
			for(ll i=0;i<26;i++)
				st[clone].next[i]=st[q].next[i];
			while(p!=-1 && st[p].next[c-'a']==q)
			{
				st[p].next[c-'a']=clone;
				p=st[p].link;
			}
			st[q].link=st[cur].link=clone;
		}
	}
	last=cur;
}

void dfs(ll x)
{
	dp[x]=1;
	vis[x]=1;
	for(ll i=0;i<26;i++)
	{
		if(st[x].next[i]==-1) cu;
		if(!vis[st[x].next[i]])
			dfs(st[x].next[i]);
		dp[x]+=dp[st[x].next[i]];
	}
}

void search(ll a[], ll cur, ll& n)
{
	while(n>0)
	{
		for(ll i=0;i<26;i++)
		{
			if(st[cur].next[i]==-1) cu;
			if(dp[st[cur].next[i]]<n)
			{
				n-=dp[st[cur].next[i]];
			}
			else
			{
				cout<<(char)(i+'a');
				cur=st[cur].next[i];
				n--;
				br;
			}
		}
	}	
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

	string s;
	cin>>s;
	sa_init();
	ll m=s.length();
	ll a[N];
	for(ll i=0;i<m;i++)
		sa_extend(s[i]);

	dfs(0);

	ll q;
	cin>>q;
	while(q--)
	{
		ll k,n=0;
		pos=0;
		cin>>k;
		search(a,0,k);
		cout<<'\n';
	}
}