/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair <int,int> dfs(TreeNode* root)
    {
        if(root==NULL)
            return {0, 0};
        pair <int,int> l = dfs(root->left);
        pair <int,int> r = dfs(root->right);
        
        int diameter = max({l.first, r.first, l.second+r.second});
        return {diameter, max(l.second, r.second)+1};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;       
    }
};