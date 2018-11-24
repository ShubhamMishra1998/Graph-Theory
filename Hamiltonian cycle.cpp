#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll f = 0;
void print(vector<ll> &path)
{
	for (ll i = 0; i < path.size(); i++)
	  cout << path[i] << ' ';
	  cout << '\n';
	f = 1;
}
void ham_path(vector<ll> v1[], vector<bool> &visited, vector<ll> &path, ll s, ll v,bool g[100][100])
{
	
	if (path.size() == v)
	{
		if (g[path[path.size() - 1]][path[0]]==1)
		{
			
			print(path);
			return;
		}

	}
	for (auto it = v1[s].begin(); it != v1[s].end(); it++)
	{
		if (!visited[*it])
		{
			visited[*it] = true;
			path.push_back(*it);
			ham_path(v1, visited, path, *it, v,g);
			visited[*it] = false;
			path.pop_back();

		}
	}
}
void ham_cycle(vector<ll> v1[], bool g[100][100], ll v)
{
	vector<bool> visited(v + 2, false);
	vector<ll> path;
	path.push_back(1);
	visited[1] = true;
	ham_path(v1, visited, path, 1, v, g);
	if (f == 0)
		cout << "NO" << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		f = 0;
		ll v, e, a, b;
		bool g[100][100];
		memset(g, 0, 10000);
		vector<ll> v1[100];
		cin >> v >> e;
		for (ll i = 0; i < e; i++)
		{
			cin >> a >> b;
			v1[a].push_back(b);
			v1[b].push_back(a);
			g[a][b] = 1;
			g[b][a] = 1;
		}
		ham_cycle(v1, g, v);
	}
}
