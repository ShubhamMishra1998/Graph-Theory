#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int vertex;
    int distance;
};
int doBFS(vector<int> &Board,vector<int> &visited,int N)
{
    queue<Node> q1;
    Node temp;
    temp.vertex=0;
    temp.distance=0;
    visited[0]=true;
    q1.push(temp);
    while(!q1.empty())
    {
        Node temp=q1.front();
        q1.pop();
        int vertex=temp.vertex;
        if(vertex==N-1)
        return temp.distance;
        for(int i=1;i<=6;i++)
        {
            int x=vertex+i;
            if((x<N)&&(!visited[x]))
            {
                Node temp1;
                visited[x]=true;
                if(Board[x]!=-1)
                temp1.vertex=Board[x];
                else
                {
                    temp1.vertex=x;
                }
                temp1.distance=temp.distance+1;
                q1.push(temp1);


            }
        }
    }
    return 0;
}
void minimumMoves(vector<pair<int,int> > &v1,int n,int N)
{
    vector<int> Board(N+1,-1);
    vector<int> visited(N+1,false);
    for(int i=0;i<n;i++)
    {
        Board[v1[i].first-1]=v1[i].second-1;
    }
    int MinMoves=doBFS(Board,visited,N);
    cout<<MinMoves<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n;
        vector<pair<int,int> > v1;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            v1.push_back(make_pair(a,b));
        }
        minimumMoves(v1,n,30);

    }
}
