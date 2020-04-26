#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

ll R,C,sr,sc,dr,dc;
ll d1[]={1,0,-1,0};
ll d2[]={0,1,0,-1};
bool dest=false;
queue <ll> q1,q2;

void next_neighbours(ll r,ll c,bool *b,char *m,ll &nxt)
{
	ll rr,cc;
	for(ll i=0;i<4;i++)
	{
		rr=r+d1[i];
		cc=c+d2[i];

		if(rr<0 || cc<0) continue;
		if(rr>=R || cc>=C) continue;
		if(*(m+C*rr+cc)=='#') continue;
		if(*(b+C*rr+cc)==1) continue;

		if(rr==dr && cc==dc)
		{
			dest=true;
			return;
		}
		*(b+C*rr+cc)=1;
		q1.push(rr);
		q2.push(cc);
		nxt++;
	}
}

void find_path(char *m)
{
	bool b[R][C];
	for(ll i=0;i<R;i++)
		for(ll j=0;j<C;j++)
			b[i][j]=0;
	while(!q1.empty())
	{
		q1.pop();q2.pop();
	}
	q1.push(sr);
	q2.push(sc);
	b[sr][sc]=1;
	ll cnt=0;
	ll curr_level=1,nxt_level=0;
	while(!q1.empty())
	{
		ll r=q1.front();
		ll c=q2.front();
		q1.pop();
		q2.pop();
		next_neighbours(r,c,&b[0][0],m,nxt_level);
		if(dest==true)
		{
			break;
		}
		curr_level--;
		if(curr_level==0)
		{
			cnt++;
			curr_level=nxt_level;
			nxt_level=0;
		}
	}
	if(dest)
	{
		cout<<cnt<<'\n';
	}
	else
	{
		cout<<-1<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("grid.txt","r",stdin);
	#endif

	cin>>R>>C;
	char m[R][C];
	for(ll i=0;i<R;i++)
		for(ll j=0;j<C;j++)
		{
			cin>>m[i][j];
			if(m[i][j]=='S')
			{
				sr=i;
				sc=j;
			}
			if(m[i][j]=='D')
			{
				dr=i;
				dc=j;
			}
		}
	find_path(&m[0][0]);
}