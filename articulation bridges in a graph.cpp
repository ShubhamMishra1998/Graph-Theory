#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll id = 0;
vector<ll> ids(100, 0), lower(100, 0), bridges;
vector<bool> visited(100, false);
void dfs(vector<ll> v1[100],ll parent,ll at)
{
	visited[at] = true;
	lower[at]=ids[at]=++id;
	for (auto it = v1[at].begin(); it != v1[at].end(); it++)
	{
		if (*it == parent)
			continue;
		if (!visited[*it])
		{
			dfs(v1,at,*it);
			lower[at] = min(lower[at], lower[*it]);
			if (ids[at] < lower[*it])
			{
				//cout << at << ' ' << *it << '\n';
				bridges.push_back(at);
				bridges.push_back(*it);
			}
		}
		else
			lower[at] = min(lower[at], ids[*it]);
	}

}
void findBridges(vector<ll> v1[100], ll v)
{
	for (ll i = 0; i < v; i++)
	{
		if (!visited[i])
			dfs(v1,-1, i);
	}
	for (ll i = 0; i < bridges.size(); i++)
	{
		cout << bridges[i] << ' ';
	}
}
int main()
{
	ll v, e, a, b;
	cin >> v >> e;
	vector<ll> v1[100];
	for (ll i = 0; i < e; i++)
	{
		cin >> a >> b;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	findBridges(v1, v);
}
