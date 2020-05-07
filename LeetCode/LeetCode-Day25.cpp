class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size(),t=0;
        for(int i=n-2;i>=0;i--)
        {
            t++;
            if(nums[i]>=t) t=0;
        }
        return t==0?1:0;        
    }
};