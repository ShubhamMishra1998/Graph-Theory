#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v1[100];
void IterativeTopological(ll v)
{
	vector<ll> indegree(100);
	queue<ll> q;
	for(ll i=1;i<=v;i++)
	{
		for(auto it=v1[i].begin();it!=v1[i].end();it++)
		{
			indegree[*it]=indegree[*it]+1;
		}
	}
	for(ll i=1;i<=v;i++)
	{
		if(indegree[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		ll f=q.front();
		q.pop();
		cout<<f<<' ';
		for(auto it=v1[f].begin();it!=v1[f].end();it++)
		{
			indegree[*it]=indegree[*it]-1;
			if(indegree[*it]==0)
				q.push(*it);
		}
	}
}
int main()
{
	ll a,b,v,e,i;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		v1[a].push_back(b);
	}
      IterativeTopological(v);
}
