class Solution {
public:
    void moveZeroes(vector<int>& nums) {
  		
  		int i,j=0,cnt=0;
  		for(i=0;i<nums.size();i++)
  		{
			if(nums[i]!=0)
			{
				nums[j]=nums[i];
				j++;
			}
			else cnt++;
  		}
  		for(i=nums.size()-cnt;i<nums.size();i++)
  			nums[i]=0;
    }
};