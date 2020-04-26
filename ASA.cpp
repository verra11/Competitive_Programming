#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,x;
	cin>>n>>x;
	ll a[n];
	double b[n];
	memset(b,0,sizeof(b));
	for(ll i=0;i<n;i++)
	    cin>>a[i];
    ll k=0,i=0;
    if(a[0]<0)
    {
        while(i<n)
        {
            while(a[i]<0 && i<n)
                b[k]+=a[i++];
            k++;
	    if(i==n)
            break;
            while(a[i]>0 && i<n)
                b[k]+=a[i++];
            k++;
	    if(i==n)
            break;
        }
    }
    else
    {
        while(i<n)
        {
            while(a[i]>0 && i<n)
                b[k]+=a[i++];
            k++;
	    if(i==n)
            break;
            while(a[i]<0 && i<n)
                b[k]+=a[i++];
            k++;
	    if(i==n)
            break;
        }
    }
    double sum=0;
    for(ll i=0;i<k;i++)
    {
        sum+=b[i];
    }
    double max=0;
    for(ll i=0;i<k;i++)
    {
        if(b[i]>max)
            max=b[i];
    }
    sum-=max;
    max/=x;
    sum+=max;
    cout<<sum<<endl;
}
