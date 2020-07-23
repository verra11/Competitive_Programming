class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map <string,vector <string> > m;

        string s;
        for(int i=0;i<strs.size();i++)
        {
        	s=strs[i];
        	sort(s.begin(),s.end());
        	m[s].emplace_back(strs[i]);
        }
        vector <vector<string>> ans;
        for(auto x:m)
        	ans.emplace_back(x.second);
        return ans;
    }
};