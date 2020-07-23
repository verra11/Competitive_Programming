class Solution {
public:
    int findComplement(int num) {
        
        bool f=0;
        for(int i=30;i>=0;i--)
        {
            if(!f && (num>>i)&1) f=1;
            if(f) num^=((1<<i));
        }
        return num;
        
    }
};