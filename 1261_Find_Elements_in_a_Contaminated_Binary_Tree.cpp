class FindElements {
private:
    unordered_set<int> values; // 存儲所有恢復後的值

    void changeElements(TreeNode* root, int val) {
        if (!root) return;
        root->val = val;
        values.insert(val);
        if (root->left) changeElements(root->left, 2 * val + 1);
        if (root->right) changeElements(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root) {
            changeElements(root, 0); // 恢復二叉樹
        }
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }
};