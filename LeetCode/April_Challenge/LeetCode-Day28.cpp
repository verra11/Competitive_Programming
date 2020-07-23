class FirstUnique {

	unordered_map <int,int> m;
	queue <int> q;

public:
	FirstUnique(vector<int>& nums) {

		for(int x:nums) add(x);

	}

	int showFirstUnique() {

		while(!q.empty() && m[q.front()]>1)
			q.pop();
		if(q.empty) return -1;
		return q.front;

	}

	void add(int value) {

		m[value]++;
		q.push(value);
		
	}
	
};