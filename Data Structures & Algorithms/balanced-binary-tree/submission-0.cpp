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
    int checkNode(TreeNode* root, bool &result){
        if(!root) return 0;
        if(result==false) return 0;
        
        int left_node=checkNode(root->left, result);
        int right_node=checkNode(root->right, result);
        if (abs(left_node- right_node)>1) result=false;

        return max(left_node, right_node)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool result=true;
        checkNode(root, result);
        return result;
    }
};
