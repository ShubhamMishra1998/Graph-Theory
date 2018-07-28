#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll id = 0, rootcountedges = 0;
vector<ll> ids(100, 0), low(100, 0);
vector<bool> visited(100, false), artpoint(100, false);
void dfs(vector<ll> v1[100], ll root, ll at, ll parent)
{
	if (parent == root) rootcountedges++;

	visited[at] = true;
	low[at] = ids[at] = id++;

	for (auto it = v1[at].begin(); it != v1[at].end(); it++) {
		if (*it == parent) continue;
		if (!visited[*it]) {
			dfs(v1, root, *it, at);
			low[at] = min(low[at], low[*it]);
			if (ids[at] <= low[*it]) {
				artpoint[at] = true;
			}
		}
		else {
			low[at] = min(low[at], ids[*it]);
		}
	}

}
void findartpoints(vector<ll> v1[100], ll v)
{
	for (ll i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			rootcountedges = 0;
			dfs(v1, i, i, -1);
			artpoint[i] = (rootcountedges > 1);
		}
	}
	for (ll i = 0; i <v; i++)
	{
		if (artpoint[i] == true)
			cout << i << ' ';
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
	findartpoints(v1, v);
}
