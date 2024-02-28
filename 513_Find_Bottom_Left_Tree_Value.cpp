class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> ans = getLeftInfo(root); // value, height
        return ans.first;
    }
    std::pair<int, int> getLeftInfo(TreeNode* root){
        if(!root) return std::make_pair(-1, -1);

        pair<int, int> left = getLeftInfo(root -> left);
        pair<int, int> right = getLeftInfo(root -> right);

        if(right.second == -1 && left.second == -1) return std::make_pair(root->val, 1);
        if(right.second > left.second) return std::make_pair(right.first, right.second + 1);
        return std::make_pair(left.first, left.second + 1);
    }
};