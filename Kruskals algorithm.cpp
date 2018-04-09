#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll> Parent;
map<ll,ll> Rank;
vector<pair<ll,pair<ll,ll> > > v1;
void Insert(ll a,ll b,ll w)
{
	v1.push_back(make_pair(w,make_pair(a,b)));
	v1.push_back(make_pair(w,make_pair(b,a)));
}
ll Find(ll x)
{
	if(Parent[x]==x)
		return x;
	else
		return Find(Parent[x]);
}
void Union(ll a,ll b)
{
	ll x=Find(a);
	ll y=Find(b);
	if(x==y)
		return;
	else if(Rank[x]>Rank[y])
		Parent[y]=x;
	else if(Rank[y]>Rank[x])
		Parent[x]=y;
	else
	{
		Parent[y]=x;
		Rank[x]++;
	}
}
int main()
{
	ll a,b,w,v,e,c=0;
	vector<ll> v2;
    cin>>v>>e;
    for(ll i=0;i<100;i++)
    {
    	v2.push_back(i+1);
    }
    for(ll i=0;i<100;i++)
    {
    	Parent[v2[i]]=v2[i];
    	Rank[v2[i]]=0;
    }
    for(ll i=0;i<e;i++)
    {
    	cin>>a>>b>>w;
    	Insert(a,b,w);
    }
      sort(v1.begin(),v1.end());
      for(ll i=0;i<2*e;i++)
      {
      	ll x=Find(v1[i].second.first);
      	ll y=Find(v1[i].second.second);
      	if(x==y)
      		continue;
      	else
      	{
          Union(x,y);
          c+=v1[i].first;
      	}
      }
      cout<<c;
}
