class Solution {
public:
    vector<int> dx={-1,0,0,1};
    vector<int> dy={0,-1,1,0};
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
       queue<pair<int,int>> q1;
       q1.push({start[0],start[1]});
       visited[start[0]][start[1]]=true;
       while(!q1.empty()){
           int r=q1.front().first;
           int c=q1.front().second;
           q1.pop();
           if(r==destination[0] && c==destination[1])
           return true;
           for(int i=0;i<4;i++){
               int rr=r;
               int cc=c;
               while(rr>=0 and cc>=0 and rr<n and cc<m and maze[rr][cc]==0){
                   rr+=dx[i];
                   cc+=dy[i];
               }
               rr-=dx[i];
               cc-=dy[i];
               if(!visited[rr][cc]){
                   visited[rr][cc]=true;
                   q1.push({rr,cc});
               }
           }
       }
       return false;
    }
};
