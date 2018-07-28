#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
#define INF 9999999999
void DIJKSTRA(vector<pii> v1[100], ll s,ll V)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	vector<ll> dist(V + 1, INF);
	vector<bool> visited(V + 1, false);
	vector<ll> parent(V + 1, 0);
	dist[s] = 0;
	pq.push(make_pair(dist[s], s));
	while (!pq.empty())
	{
		ll u = pq.top().second;
		ll c = pq.top().first;
		pq.pop();
		visited[u] = true;
		if (dist[u] < c)
			continue;
		for (auto it = v1[u].begin(); it != v1[u].end(); it++)
		{
			if (visited[it->first] == true)
				continue;
			ll v = it->first;
			ll w = it->second;
			if (dist[v] > dist[u] + w)
			{
				parent[v] = u;
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}

	}
	for (ll i = 1; i <= V; i++)
	{
		cout << dist[i] << " ";
	}
	cout << '\n';
	for (ll i = 1; i <= V; i++)
	{
		cout <<parent[i] << " ";
	}
}
int main()
{
	ll v, e, w, a, b;
	vector<pii> v1[100];
	cin >> v >> e;
	for (ll i = 0; i < e; i++)
	{
		cin >> a >> b >> w;
		v1[a].push_back(make_pair(b, w));
		v1[b].push_back(make_pair(a, w));
	}
	DIJKSTRA(v1, 1,v);
	cin >> v;
}

