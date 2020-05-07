class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        multiset <int, greater <int>> m;
        for(int x: stones) m.insert(x);
        while(m.size()>1)
        {
            int x=*m.begin();
            m.erase(m.begin());
            int y=*m.begin();
            m.erase(m.begin());
            x-=y;
            if(x>0)
                m.insert(x);
        }
        if(m.size()==0) return 0;
        return *m.begin();
    }
};