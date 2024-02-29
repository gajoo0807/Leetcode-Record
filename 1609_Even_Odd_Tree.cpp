class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;

        std::queue<TreeNode*> queue;
        int level = 0;
        queue.push(root);

        while(!queue.empty()){
            int size = queue.size();
            int prev_val = (level % 2 == 0) ? numeric_limits<int>::min() : numeric_limits<int>::max();

            for(int i = 0; i < size; i ++){
                TreeNode* node = queue.front();
                queue.pop();


                // if(!((level & 1 == node->val & 1) && (level & 1) ^ (node->val < prev_val)))
                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev_val)) ||
                    (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev_val))) {
                    return false;
                }

                prev_val = node->val;

                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            level++;
        }
        return true;
    }
};