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

    void preorder(TreeNode *root, vector<int> &a)
    {
        if(!root)
        return;

        a.push_back(root->val);
        preorder(root->left,a);
        preorder(root->right,a);
    }

    void flatten(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        if(!root)
        return;

        if(root->left==NULL && root->right==NULL)
        return;

        vector<int> a;
        preorder(root,a);
        root->val=a[0];
        root->right=NULL;
        root->left=NULL;
        TreeNode *curr=root;
        for(int i=1;i<a.size();++i)
        {
            TreeNode *newer = new TreeNode(a[i]);
            curr->right=newer;
            curr=newer;
        }
    }
};