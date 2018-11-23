#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll f = 0;
void print(vector<ll> path)
{
	for (ll i = 0; i < path.size()-1; i++)
		cout << path[i] << ' ';
	cout << '\n';
}
bool is_safe(bool v1[100][100],ll v, vector<ll> path, ll pos)
{
	if (v1[path[pos - 1]][v] !=1)
		return false;
	for (ll i = 0; i < pos; i++)
	{
		if (path[i] == v)
			return false;
	}
	return true;
}
void hem_util(bool v1[100][100], ll v, ll pos,vector<ll> &path)
{
	if (pos == v)
	{
		if (v1[path[pos - 1]][path[0]] == 1)
		{
			print(path);
			f = 1;
		}
	}
	for (ll i = 2; i < v+1; i++)
	{
		if (is_safe(v1, i, path, pos))
		{
			path[pos] = i;
			hem_util(v1, v, pos + 1, path);
			path[pos] = -1;
		}
	}
	return;
}
void hem_cycle(bool v1[100][100], ll v)
{
	vector<ll> path(v+1,-1);
	path[0] = 1;
	hem_util(v1, v, 1, path);
	if (f==0)
	{
		cout << "NO";
		return;
	}
	else
	{
		cout << "YES";
	}
}
int main()
{
	ll v, e, a, b;
	cin >> v >> e;
	bool v1[100][100];
	for (ll i = 0; i <e; i++)
	{
		cin >> a >> b;
		v1[a][b] = 1;
		v1[b][a] = 1;

	}
	hem_cycle(v1, v);
	cin >> v;
}
