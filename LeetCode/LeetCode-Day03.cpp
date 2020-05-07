class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int mn=INT_MIN;
        int sum=0,mx=0;
        bool flag=1;
        for(int i=0;i<nums.size();i++)
        {
            mn=max(mn,nums[i]);
        	sum+=nums[i];
        	if(sum>=mx)
            {
                mx=sum;
                flag=0;
            }
        	sum=max(sum,0);
        }
        if(flag) return mn;
        return mx;
    }
};