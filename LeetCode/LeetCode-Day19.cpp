class Solution {
public:
    
    int bp(vector <int> &v, int x)
    {
        int l=0,r=v.size()-1;
        int mid,res=-1;
        while(l<=r)
        {
            mid=r-(r-l)/2;
            if(v[mid]>=x)
            {
                res=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(res==-1) res=v.size()-1;
        return res;
    }
    
    int bs(vector <int> &v, int x, int l,int r)
    {
        while(l<=r)
        {
            int mid=r-(r-l)/2;
            if(v[mid]>x)
            {
                r=mid-1;    
            }
            else if(v[mid]<x)
            {
                l=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0) return -1;
        int x=nums[0];
        
        int idx=bp(nums, x);
        
        int y=bs(nums,target,0,idx);
        if(y!=-1) return y;
        y=bs(nums,target,idx+1,nums.size()-1);
        return y;
            
    }
};