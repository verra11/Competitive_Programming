class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        unsigned int x,y,tmp,diff;
        y=m,x=n;
        diff=x-y;
        if(diff==0) return m;
        unsigned int ans=0;
        for(int i=31;i>=0;i--)
        {
            tmp=(1<<i);
            if(((x>>i)&1)&&((y>>i)&1))
            {
                if(diff<tmp)
                    ans|=tmp;
            }
        }
        return ans;
        
    }
};