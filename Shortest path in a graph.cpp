#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v1[100];
void SHORTESTPATH(ll d,ll v)
{
	vector<bool> visited(v+1);
	visited.assign(v+1,false);
	vector<ll> dist(v+1);
	queue<ll> q;
	q.push(1);
	visited[1]=true;
	while(!q.empty())
	{
		ll f=q.front();
		q.pop();
		for(auto i=v1[f].begin();i!=v1[f].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				q.push(*i);
				dist[*i]=dist[f]+1;
			}
		}
	}
	cout<<dist[d]<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll v,e,a,b,d;
	cin>>v>>e;
	for(ll i=0;i<e;i++)
	{
		cin>>a>>b;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	SHORTESTPATH(v,v);
}
