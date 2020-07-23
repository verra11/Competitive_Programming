class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     
        int ans=0,n=nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++) if(nums[i]==0) nums[i]=-1;
        vector <int> pre;
        map <int,int> m;
        m[0]=0;
        pre.emplace_back(nums[0]);
        for(int i=1;i<nums.size();i++) pre.emplace_back(nums[i]+pre[i-1]);
        for(int i=0;i<pre.size();i++)
        {
            if(m.find(pre[i])==m.end()) m[pre[i]]=i+1;
            else ans=max(ans,(i+1-m[pre[i]]));
        }
        return ans;
        
    }
};