#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v1[100];
vector<bool> visited(100);
void BFS()
{
	queue<ll> q;
	vector<ll> v2(100);
	v2.assign(100,-1);
	q.push(1);
	v2[1]=1;
	while(!q.empty())
	{
		ll f=q.front();
		q.pop();
		for(auto it=v1[f].begin();it!=v1[f].end();it++)
		{
			if(!visited[*it])
			{
				visited[*it]=true;
				q.push(*it);
				v2[*it]=1-v2[f];
			}
			else if(v2[*it]==v2[f]){
				cout<<"false";
				return;
			}
		}
	}
	cout<<"true";
	return;
}
int main()
{
	ll a,b,v,e;
	cin>>v>>e;
	visited.assign(v,false);
	for(ll i=0;i<e;i++)
	{
		cin>>a>>b;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	BFS();
}
