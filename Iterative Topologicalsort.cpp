#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void topologicalsort(vector<ll> v1[100], ll v)
{
	queue<ll> q;
	vector<ll> indegree(100), v2;
	for (ll i = 1; i <= v; i++)
	{
		for (auto it = v1[i].begin(); it != v1[i].end(); it++)
			indegree[*it]++;
	}
	for (ll i = 1; i <= v; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	ll c = 0;
	while (!q.empty())
	{
		ll f = q.front();
		v2.push_back(f);
		q.pop();
		for (auto it = v1[f].begin(); it != v1[f].end(); it++)
		{
			indegree[*it] = indegree[*it] - 1;
			if (indegree[*it] == 0)
				q.push(*it);
		}
		c++;
	}
	if (c != v)
	{
		cout << "cycle";
		return;
	}
	for (ll i = 0; i < v2.size(); i++)
		cout << v2[i] << ' ';
}
int main()
{
	vector<ll> v1[100];
	ll v, e, a, b;
	cin >> v >> e;
	for (ll i = 0; i < e; i++)
	{
		cin >> a >> b;
		v1[a].push_back(b);
	}
	topologicalsort(v1, v);
}
