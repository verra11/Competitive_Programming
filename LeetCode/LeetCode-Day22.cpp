class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n==0) return 0;
        unordered_map <int,int> m;
        int sum=0;
        m[sum]++;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans+=(m[sum-k]);
            m[sum]++;
        }
        return ans;
    }
};