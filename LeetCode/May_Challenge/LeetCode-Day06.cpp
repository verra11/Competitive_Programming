class Solution {
    
    unordered_map <int,int> m;
    
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        for(int x:nums) m[x]++;
        for(int x:nums)
        {
            if(m[x]>=ceil(1.0*n/2))
                return x;
        }
        return -1;
    }
};