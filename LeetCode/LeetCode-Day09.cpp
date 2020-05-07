class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        int c1=0,c2=0,i=S.length()-1, j=T.length()-1;
        while(i>=0 || j>=0)
        {
        	while(i>=0)
        	{
        		if(S[i]=='#')
        		{
        			c1++;
        			i--;
        		}
        		else if(c1>0)
        		{
        			c1--;
        			i--;
        		}
        		else
        			break;
        	}
        	while(j>=0)
        	{
        		if(T[j]=='#')
        		{
        			c2++;
        			j--;
        		}
        		else if(c2>0)
        		{
        			c2--;
        			j--;
        		}
        		else break;
        	}
        	if(i>=0 && j>=0 && S[i]!=T[j])
        		return false;
        	if((i>=0)!=(j>=0))
        		return false;
        	i--;
        	j--;
        }
        return true;
    }
};
