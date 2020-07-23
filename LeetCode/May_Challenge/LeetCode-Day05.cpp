class Solution {
    
    int f[26];
    
public:
    int firstUniqChar(string s) {
        
        int res=-1;
        for(int i=0;i<26;i++) f[i]=0;
        for(char c:s)
            f[c-'a']++;
        for(int i=0;i<s.length();i++)
            if(f[s[i]-'a']==1)
            {
                res=i;
                break;
            }
        return res;
        
    }
};