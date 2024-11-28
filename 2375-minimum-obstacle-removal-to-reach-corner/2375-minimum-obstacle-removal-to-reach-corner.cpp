class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        deque<vector<int>>dq;

        dq.push_front({0,0,0});
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        visit[0][0]=true;

        while(!dq.empty()){
            int x=dq.front()[0], y=dq.front()[1],dist=dq.front()[2]; dq.pop_front();
            if(x==n-1 && y==m-1){
                return dist;
            }
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0],dy=y+dir[i][1];
                if(dx<0 || dy<0 || dx==n || dy==m || visit[dx][dy]){
                    continue;
                }
                int w=grid[dx][dy];
                if(w){
                    dq.push_back({dx,dy,dist+w});
                }
                else{
                    dq.push_front({dx,dy,dist+w});
                }
                visit[dx][dy]=true;
            }
        }
        return -1;
    }
};