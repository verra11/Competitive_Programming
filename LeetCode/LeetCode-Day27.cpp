class Solution {
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1') dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
        for(int i=1;i<m;i++) dp[i][0]+=dp[i-1][0];
        for(int j=1;j<n;j++) dp[0][j]+=dp[0][j-1];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        int l=0,r=max(m,n),res=0,mid,tmp;
        while(l<=r)
        {
            mid=r-(r-l)/2;
            for(int i=mid-1;i<m && i>=0;i++)
            {
                for(int j=mid-1;j<n && j>=0;j++)
                {
                    tmp=dp[i][j];
                    if(i-mid>=0) tmp-=dp[i-mid][j];
                    if(j-mid>=0) tmp-=dp[i][j-mid];
                    if(i-mid>=0 && j-mid>=0) tmp+=dp[i-mid][j-mid];
                    if(tmp==(mid*mid)) break;
                }
                if(tmp==mid*mid) break;
            }
            if(tmp==(mid*mid))
            {
                res=tmp;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return res;
                
    }
};