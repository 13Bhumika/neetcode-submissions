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
private: 
    int getHeight(TreeNode*root, int &result){
        if(!root) return 0;

        int left= getHeight(root->left, result);
        int right= getHeight(root->right,result);

        result = max(result, left+right);
        return max(left, right)+1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int result =0;
        getHeight(root,result);
        return result;
        
    }
};
