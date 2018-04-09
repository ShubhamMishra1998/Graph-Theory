#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll> parent;
map<ll,ll> Rank;
ll Find(ll x)
{
	if(parent[x]==x)
		return x;
	else
		return Find(parent[x]);
}
void Union(ll a,ll b)
{
	ll x=Find(a);
	ll y=Find(b);
	if(x==y)
		return ;
	else if(Rank[x]>Rank[y])
		parent[y]=x;
	else if(Rank[y]>Rank[x])
		parent[x]=y;
	else 
	{
        parent[y]=x;
        Rank[x]++;
	}
}
int main()
{
	ll a,i;
	vector<ll> v1(100);
	for(i=0;i<100;i++)
	{
		v1[i]=(i+1);
	}
	for(i=0;i<100;i++)
	{
		parent[v1[i]]=v1[i];
		Rank[v1[i]]=0;
	}
	Union(1,2);
	Union(2,3);
	Union(3,4);
	Union(4,5);
	Union(1,7);
	Union(7,6);
    i=5;
    while(i--)
    {
    	cin>>a;
    	cout<<Find(a)<<'\n';
    }
}
