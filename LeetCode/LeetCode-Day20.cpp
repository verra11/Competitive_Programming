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
    
    void insert_node(TreeNode root, TreeNode x)
    {
        if(x.val>root.val)
        {
            if(root.right==NULL)
            {
                root.right=&x;
                return;
            }
            else
            {
                root=&root.right;
                insert_node(root,x);
            }
        }
        else
        {
            if(root.left==NULL)
            {
                root.left=&x;
                return;
            }
            else
            {
                root=&root.left;
                insert_node(root,x);
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size()==0) return NULL;
        TreeNode root = TreeNode(preorder[0]);
        root.left=NULL;
        root.right=NULL;
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode tmp = root;
            TreeNode x =TreeNode(preorder[i]);
            x.left=NULL;
            x.right=NULL;
            insert_node(tmp,x);
        }
        return root;
    }
};