class Solution {

public:
	string stringShift(string s, vector<vector<int>>& shift) {

		int cnt=0;
		if(shift.size()==0) return s;
		int n=s.length();
		for(vector<int> v:shift)
		{
			if(v[0]==0) cnt-=v[1];
			else cnt+=v[1];
		}
		if(cnt<0) cnt+=n;
		cnt%=n;
		string tmp="";
		for(int i=(n-cnt);i<n;i++) tmp+=s[i];
		for(int i=0;i<(n-cnt);i++) tmp++s[i];
		return tmp;
	}

};