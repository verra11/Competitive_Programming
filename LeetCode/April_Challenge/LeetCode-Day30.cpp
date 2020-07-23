class Solution {

	int n;

	bool dfs(Treenode* node, vector<int>& a, int i) {

		if(i==n) return true;
		if(node==NULL) return false;
		if(node->val!=a[i]) return false;
		bool left=dfs(node->left, a, i+1);
		bool right=dfs(node->right, a, i+1);
		return left|right;

	}

public:
	bool isValidSequence(TreeNode* root, vector<int>& arr) {

		n=arr.size();
		return dfs(root, arr, 0);

	}

};