class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> nodeStack;
        int i = 0, n = traversal.size();
        while (i < n) {
            int depth = 0;
            // 計算當前節點的深度（數 `-` 的個數）
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            // 讀取節點值
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            // 創建新節點
            TreeNode* node = new TreeNode(value);
            // 如果 `stack` 深度超過 `depth`，則回溯到正確深度
            while (nodeStack.size() > depth) {
                nodeStack.pop();
            }
            // 若 `stack` 不為空，表示當前節點有父節點
            if (!nodeStack.empty()) {
                if (!nodeStack.top()->left) {
                    nodeStack.top()->left = node;
                } else {
                    nodeStack.top()->right = node;
                }
            }
            // 把當前節點壓入 `stack`
            nodeStack.push(node);
        }
        // 根節點即為 `stack` 底部的節點
        while (nodeStack.size() > 1) {
            nodeStack.pop();
        }
        return nodeStack.top();
    }
};