class Solution {
public:
    vector<int> dx={-1,0,0,1};
    vector<int> dy={0,-1,1,0};
    void dfs(vector<vector<int>> &grid,int r,int c,vector<vector<bool>> &visited,int n,int m,string &s1){
        //   string s="";
           visited[r][c]=true;
           for(int i=0;i<4;i++){
               int rr=r+dx[i];
               int cc=c+dy[i];
               if(rr<0 or cc<0 or rr>=n or cc>=m or visited[rr][cc] or grid[rr][cc]==0)
               continue;
               if(i==0){
                   s1+="U";
                   dfs(grid,rr,cc,visited,n,m,s1);
               }else if(i==1){
                    s1+="L";
                   dfs(grid,rr,cc,visited,n,m,s1);
               }else if(i==2){
                    s1+="R";
                   dfs(grid,rr,cc,visited,n,m,s1);
               }else{
                    s1+="D";
                   dfs(grid,rr,cc,visited,n,m,s1);
               }
           }
           s1+='z';
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        unordered_map<string,int> m1;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and visited[i][j]==false){
                    string s1="n";
                    dfs(grid,i,j,visited,n,m,s1);
                    m1[s1]++;
                }
            }
        }
        return m1.size();
    }
};
