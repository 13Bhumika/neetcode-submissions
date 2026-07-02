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
    int solution(TreeNode* root, int &result){
        if(!root) return 0;

        int left_node= solution(root->left,result);
        int right_node= solution(root->right,result);
        result= max(result, left_node+right_node);
        return max(left_node, right_node)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result=0;
        solution(root,result);
        return result;
    }
};