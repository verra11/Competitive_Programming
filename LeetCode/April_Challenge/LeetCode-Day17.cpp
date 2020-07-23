class Solution {
public:
    
    int d1[4]={1,0,-1,0};
    int d2[4]={0,1,0,-1};
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        
        
        bool vis[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) vis[i][j]=0;
        
        int cnt=0;
        queue <pair <int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==1 || grid[i][j]=='0') continue;
                cnt++;
                vis[i][j]=1;
                q.push({i,j});
                while(!q.empty())
                {
                    pair <int,int> p=q.front();
                    q.pop();
                    int x=p.first,y=p.second;
                    for(int k=0;k<4;k++)
                    {
                        x+=d1[k],y+=d2[k];
                        if(x>=0 && x<m && y<n && y>=0 && vis[x][y]==0 && grid[x][y]=='1')
                        {
                            q.push({x,y});
                            vis[x][y]=1;
                        }
                        x-=d1[k],y-=d2[k];
                    }
                }
            }
        }
        return cnt;
    }
};