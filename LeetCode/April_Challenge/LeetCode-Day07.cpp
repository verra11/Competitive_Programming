class Solution {

public:
	int countElements(vector<int>& arr) {

		unordered_map <int,int> m;
		int cnt=0;
		for(int x:arr) m[x]++;
		for(int x:arr)
		{
			if(m.find(x+1)!=m.end()) cnt++;
		}
		return cnt;
	}

};