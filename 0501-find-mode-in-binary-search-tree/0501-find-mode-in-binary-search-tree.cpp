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
    void findMaxFreq(TreeNode* node, int& prevVal, int& prevCount, int& maxCount) {
        //inorder traveral: left - self - right
        if (node->left) {
            findMaxFreq(node->left, prevVal, prevCount, maxCount);            
        }
        //
        if (prevVal==node->val) {
            prevCount++;
            maxCount=max(maxCount, prevCount);
        }
        else {
            prevCount=1;
            prevVal=node->val;
            maxCount=max(maxCount, prevCount);
        }
        //
        if (node->right) {
            findMaxFreq(node->right, prevVal, prevCount, maxCount);
        }        
    }
    void collectWithFreq(TreeNode* node, int& prevVal, int& prevCount, int targetCount, vector<int>& result) {
        if (node->left) {
            collectWithFreq(node->left, prevVal, prevCount, targetCount, result);            
        }
        //
        if (prevVal==node->val) {
            prevCount++;
        }
        else {
            prevCount=1;
            prevVal=node->val;
        }
        if (prevCount==targetCount) {
            result.push_back(prevVal);
        }
        //
        if (node->right) {
            collectWithFreq(node->right, prevVal, prevCount, targetCount, result);
        }        
    }
    vector<int> findMode(TreeNode* root) {        
        vector<int> result;
        //since inorder traversal = sorted, we can calculate max freq easily
        int prevVal=root->val, prevCount=0, maxCount=0;
        findMaxFreq(root, prevVal, prevCount, maxCount);
        //maxCount now holds maximum frequency
        prevVal=root->val, prevCount=0;
        collectWithFreq(root, prevVal, prevCount, maxCount, result);
        //
        return result;
    }    
};