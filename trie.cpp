#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

#define N 26

struct node
{
	bool b;
	char c;
	ll f,ans;
	struct node * a[N];
};

struct node * createNode(char c)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->c=c;
	temp->f=1;
	temp->ans=0;
	temp->b=false;
	for(ll i=0;i<N;i++)
		temp->a[i]=NULL;
	return temp;	
}

struct node * insert(struct node * root,char c,ll i,ll m)
{
	struct node * p;
	p=root;
	if(p->a[c-'a']!=NULL)
	{
		p=p->a[c-'a'];
		p->f++;
		p->ans+=(m-i-1);
		if(i==m-1)
			p->b=true;
		return p;
	}
	p->a[c-'a']=createNode(c);
	p=p->a[c-'a'];
	p->ans+=(m-i-1);
	if(i==m-1)
		p->b=true;
	return p;
}

void lls(struct node * root)
{
	if(root==NULL)
		return;
	struct node * p;
	p=root;
	for(ll i=25;i>=0;i--)
	{
		if(p->a[i]!=NULL)
		{
			p=p->a[i];
			cout<<p->c;
			lls(p);
			break;
		}
	}
}

void lss(struct node * root)
{
	if(root==NULL)
		return;
	struct node * p;
	p=root;
	for(ll i=0;i<26;i++)
	{
		if(p->b==true)
				break;
		if(p->a[i]!=NULL)
		{
			p=p->a[i];
			cout<<p->c;
			if(p->b==true)
				break;
			lss(p);
			break;
		}
	}
	return;
}

struct node * sol(struct node * root,char c)
{
	struct node * p;
	p=root;
	if(p->a[c-'a']!=NULL)
	{
		p=p->a[c-'a'];
		return p;
	}
	return NULL;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif
	
	ll n;
	cin>>n;

	struct node * root = createNode('A');
	struct node * p = NULL;

	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		p=root;
		ll m=s.length();
		for(ll i=0;i<m;i++)
		{
			p=insert(p,s[i],i,m);
		}
	}

	struct node * temp = NULL;

	ll q;
	cin>>q;
	while(q--)
	{
		ll flag=0;
		p=root;
		string s2;
		cin>>s2;

		for(ll i=0;i<s2.length();i++)
		{
			p=sol(p,s2[i]);
			if(p==NULL)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<-1<<"\n";
			continue;
		}
		temp=p;
		cout<<p->ans<<" ";
		
		cout<<s2;
		lss(p);
		cout<<' ';
		p=temp;
		cout<<s2;
		lls(p);
		cout<<'\n';
	}
}