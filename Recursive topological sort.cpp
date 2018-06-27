#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void Topologicalsort(vector<ll> v1[100], vector<bool> &visited, stack<ll> &st, ll a)
{
	visited[a] = true;
	for (auto it = v1[a].begin(); it!= v1[a].end(); it++)
	{
		if (!visited[*it])
			Topologicalsort(v1, visited, st, *it);
	}
	st.push(a);
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
	}
	vector<bool> visited(1000, false);
	stack<ll> st;
	for (ll i = 1; i <= v; i++)
	{
		if (!visited[i])
			Topologicalsort(v1, visited, st, i);
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}
