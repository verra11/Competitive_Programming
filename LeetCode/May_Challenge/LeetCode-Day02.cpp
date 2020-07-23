class Solution {
    
    unordered_map <char,bool> m;
    
public:
    int numJewelsInStones(string J, string S) {
        
        int cnt=0;
        for(char c:J) m[c]=1;
        for(char c:S)
        {
            auto it=m.find(c);
            if(it==m.end()) continue;
            if(it->second) cnt++;
        }
        return cnt;
    }
};