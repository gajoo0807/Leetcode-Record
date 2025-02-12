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
    int max_value = 0;
    int maxAncestorDiff(TreeNode* root) {
        findMaxValue(root, root->val, root->val);
        return max_value;
    }
    void findMaxValue(TreeNode* root, int max, int min){
        if(!root) return;
        int absMax = std::abs(max - root->val);
        int absMin = std::abs(min - root->val);
        int value = absMax > absMin ? absMax: absMin;
        if(max_value < value) max_value = value;
        if(min > root->val) min = root->val;
        if(max < root->val) max = root->val;
        findMaxValue(root->left, max, min);
        findMaxValue(root->right, max, min);
    }
};