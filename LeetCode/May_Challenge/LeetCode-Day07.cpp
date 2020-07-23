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
    
    int px=0,py=0,lx=-1,ly=-2,X,Y;
    
    void dfs(TreeNode* node, int lvl, int tmp=-1)
    {
        if(node==NULL) return;
        if(node->val==X)
        {
            lx=lvl;
            px=tmp;
            return;
        }
        if(node->val==Y)
        {
            ly=lvl;
            py=tmp;
            return;
        }
        dfs(node->left, lvl+1, node->val);
        dfs(node->right, lvl+1, node->val);
        
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        X=x,Y=y;
        dfs(root,0);
        if(lx==ly && px!=py) return 1;
        return 0;
        
    }
};