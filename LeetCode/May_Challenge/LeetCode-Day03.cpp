class Solution {
    
    int f1[26],f2[26];
    
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        for(int i=0;i<26;i++) f1[i]=0,f2[i]=0;
        for(char c:ransomNote)
            f1[c-'a']++;
        for(char c:magazine)
            f2[c-'a']++;
        bool fl=1;
        for(int i=0;i<26;i++)
            if(f1[i]>f2[i])
            {
                fl=0;
                break;
            }
        return fl;
        
    }
};