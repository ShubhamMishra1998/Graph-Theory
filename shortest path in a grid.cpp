#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> dr = { -1,1,0,0 }, dc = { 0,0,1,-1 };
ll f1(string s1[100],ll R,ll C,ll a,ll b)
{
	ll dist[100][100];
	dist[a][b]=0;
	queue<ll> qr, qc;
	qr.push(a);
	qc.push(b);
	vector<bool> visited[100];
	for(ll i=0;i<R;i++)
	visited[i].assign(C,false);
	visited[a][b] = true;
	while (!qr.empty())
	{
		ll r = qr.front();
		ll c = qc.front();
		qr.pop();
		qc.pop();
		if (r==R-1&&c==C-1)
			return dist[r][c];
		for (ll i = 0; i < 4; i++)
		{
			ll rr = r + dr[i];
			ll cc = c + dc[i];
			if (rr < 0 || cc < 0)
				continue;
			if (rr >= R || cc >= C)
				continue;
			if (visited[rr][cc])
				continue;
			if (s1[rr][cc] == '*')
				continue;
				if(s1[rr][cc]=='x')
				continue;

			qr.push(rr);
			qc.push(cc);
			visited[rr][cc] = true;
			dist[rr][cc] = dist[r][c] + 1;
		}

	}
	return -1;
}
int main()
{
	ll r, c,i,j,f=0;
	cin >> c >> r;
	string s1[100];
	for (i = 0; i < r; i++)
	{
		cin>>s1[i];
	}
	for(i=0;i<r;i++)
	{
	    for(j=0;j<c;j++)
	    {
	        if(s1[i][j]=='o')
	        {
	            cout<<f1(s1,r,c,i,j)<<'\n';
	            f=1;
	            break;
	        }
	    }
	    if(f==1)
	    break;
	}
}
