class Solution {
public:
      int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>> q;
       int n=grid.size() , m=grid[0].size() ,cnt=0, total=0 , min_time=0 ,k;
       if(grid.empty()) return 0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]!=0){
                   total++;
                    if(grid[i][j]==2){
                    q.push({i,j});
                    }
               }
           }
       }
       int dx[]={1,-1,0,0};
       int dy[]={0,0,1,-1};
       while(!q.empty()){
           k=q.size();
           cnt+=k;
           while(k--){
           int x=q.front().first;
           int y=q.front().second;
           q.pop();
           for(int i=0;i<4;i++){
               int nx=dx[i]+x;
               int ny=dy[i]+y;
               if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1) continue;
               grid[nx][ny]=2;
               q.push({nx,ny});
             }
           }
           if(!q.empty()) min_time++;
           
           }
       return cnt==total?min_time : -1;
       
    }
};