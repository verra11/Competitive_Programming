class Solution {
public:

	int squareSum(int n)
	{
		int s=0;
		while(n>0)
		{
			s+=((n%10)*(n%10));
			n/=10;
		}
		return s;
	}

    bool isHappy(int n) {

    	for(int i=0;i<1000000;i++)
    		n=squareSum(n);
    	if(n==1) return true;
    	return false;
    }
};