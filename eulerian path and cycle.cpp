#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(vector<ll> v1[], vector<bool> &visited,ll i)
{
	visited[i] = true;
	for (auto it = v1[i].begin(); it != v1[i].end(); it++)
	{
		if (!visited[*it])
			dfs(v1, visited, *it);
	}
}
bool isConected(vector<ll> v1[], ll n)
{
	vector<bool> visited(n + 1, false);
	ll i;
	for (i = 0; i < n; i++)
	{
		if (v1[i].size() > 0)
			break;
	}
	if (i == n)
		return true;
	dfs(v1, visited, i);
	for (ll i = 0; i < n; i++)
	{
		if (visited[i] == false && v1[i].size() > 0)
			return false;
	}
	return true;
}

ll isEulerian(vector<ll> v1[], ll n)
{
	if (isConected(v1, n) == false)
		return 0;
	ll odd = 0;
	for (ll i = 0; i < n; i++)
	{
		if (v1[i].size() % 2)
			odd++;
	}
	if (odd > 2)
		return 0;
	return odd ? 1 : 2;
}
int main()
{
	ll v, e, a, b;
	cin >> v >> e;
	vector<ll> v1[100];
	//cin >> v >> e;
	for (ll i = 0; i < e; i++)
	{
		cin >> a >> b;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}
	ll f = isEulerian(v1, v);
	if (f == 1)
		cout << "Eulerian path";
	else if (f == 2)
		cout << "Eulerian cycle";
	else
		cout << "Not Eulerian";
	//cin >> v;
}
