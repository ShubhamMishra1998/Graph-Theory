#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 999999999
typedef pair<ll, ll> pii;
void DIJKSTRA(vector<pii> v1[100], ll s, ll V)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	vector<ll> dist((V + 1), INF);
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty())
	{
		ll u = pq.top().second;
		pq.pop();
		for (auto it = v1[u].begin(); it != v1[u].end(); it++)
		{
			ll v = it->first;
			ll w = it->second;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	for (ll i = 1; i <= V; i++)
		cout << dist[i] << ' ';
}
int main()
{
	vector<pii> v1[100];
	ll a, b, w, v, e;
	cin >> v >> e;
	for (ll i = 0; i < e; i++)
	{
		cin >> a >> b >> w;
		v1[a].push_back(make_pair(b, w));
		v1[b].push_back(make_pair(a, w));
	}
	DIJKSTRA(v1, 1, v);
}
