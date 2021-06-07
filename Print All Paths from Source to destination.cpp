#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> G[],int src,int dist,vector<bool> visited,vector<int> paths){
	visited[src]=true;
	paths.push_back(src);
	if(src==dist){
		for(int i=0;i<paths.size();i++){
			cout<<paths[i]<<' ';
		}
		cout<<endl;
		return;
	}
	for(auto it:G[src]){
		if(!visited[it]){
              //paths.push_back(it);
			dfs(G,it,dist,visited,paths);
			//paths.pop_back();
		}
	}
	paths.pop_back();
	visited[src]=false;
}
void printPath(vector<int> G[],int v,int src,int dist){
	vector<int> paths;
	vector<bool> visited(v+1,false);
	//paths.push_back(src);
	dfs(G,src,dist,visited,paths);
}
int main(){
	int v,e,a,b;
	cin>>v>>e;
	vector<int> G[v+1];
	for(int i=0;i<e;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int src,dist;
	cin>>src>>dist;
	printPath(G,v,src,dist);
}
