class Solution {
public:
    bool checkValidString(string s) {
        
        int x=0,open=0,close=0,star=0;
        for(char c:s)
            if(c=='(') open++;
            else if(c==')') close++;
            else star++;
        for(char c:s)
        {
            if(c=='(' || c=='*') x++;
            else
            {
                x--;
                if(x<0) return 0;
            }
        }
        reverse(s.begin(),s.end());
        for(char& c:s)
            if(c=='(') c=')';
            else if(c==')') c='(';
        x=0;
        for(char c:s)
            if(c=='(' || c=='*')
            {
                x++;
            }
            else
            {
                x--;
                if(x<0) return 0;
            }
        return 1;
    }
};