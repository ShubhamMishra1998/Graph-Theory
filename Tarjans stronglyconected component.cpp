#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(vector<ll> v1[100], ll at, vector<ll> &ids, vector<ll> &low, map<ll, bool> &onStack, stack<ll> &Stack, ll *scc, ll *id)
{
	Stack.push(at);
	onStack[at] = true;
	ids[at] = low[at] = *id;
		*id= *id + 1;
	for (auto it = v1[at].begin(); it != v1[at].end(); it++)
	{
		if (ids[*it] == -1)
			dfs(v1, *it, ids, low, onStack, Stack, scc, id);

		if (onStack[*it]==true)
			low[at] = min(low[at], low[*it]);
	}
	if (ids[at] == low[at])
	{
		while (!Stack.empty())
		{
			ll node = Stack.top();
			Stack.pop();
			onStack[node] = false;
			low[node] = ids[at];
			if (node == at)
				break;
			//cout << node << ' ';
		}
		//cout << '\n';
		*scc = *scc + 1;
	}

}
void stronglyConnectedComponents(vector<ll> v1[100], ll v)
{
	ll id = 0, scc = 0, unvisited = -1;
	vector<ll> ids(v + 1, -1), low(v + 1, 0);
	map<ll, bool> onStack;
	stack<ll> Stack;
	for (ll i = 0; i < v; i++)
	{
		if (ids[i] == unvisited)
			dfs(v1, i, ids, low, onStack, Stack, &scc, &id);
	}
	cout << scc << '\n';
	for (ll i = 0; i < v; i++)
		cout << i << ' ' << low[i] << '\n';
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
		//v1[b].push_back(a);
	}
	stronglyConnectedComponents(v1, v);
}
