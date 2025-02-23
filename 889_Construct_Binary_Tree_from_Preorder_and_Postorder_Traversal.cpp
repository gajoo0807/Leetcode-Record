class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndexMap;
        int n = postorder.size();

        // 建立 postorder 索引查找表，方便快速查找索引位置
        for (int i = 0; i < n; i++) {
            postIndexMap[postorder[i]] = i;
        }

        // 呼叫遞迴函式來構建二元樹
        return buildTree(preorder, 0, n - 1, postorder, 0, n - 1, postIndexMap);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& postorder, int postStart, int postEnd,
                        unordered_map<int, int>& postIndexMap) {
        
        // Base Case: 如果範圍無效，返回 nullptr
        if (preStart > preEnd) return nullptr;
        
        // 建立根節點
        TreeNode* root = new TreeNode(preorder[preStart]);

        // 若只有一個節點，直接回傳
        if (preStart == preEnd) return root;

        // 取得左子樹的根節點（preorder[preStart + 1]）
        int leftRootVal = preorder[preStart + 1];

        // 找到左子樹的根在 postorder 中的索引
        int leftRootIndex = postIndexMap[leftRootVal];

        // 左子樹的節點數量
        int leftSubtreeSize = leftRootIndex - postStart + 1;

        // 遞迴建立左子樹
        root->left = buildTree(preorder, preStart + 1, preStart + leftSubtreeSize,
                               postorder, postStart, leftRootIndex, postIndexMap);

        // 遞迴建立右子樹
        root->right = buildTree(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                postorder, leftRootIndex + 1, postEnd - 1, postIndexMap);

        return root;
    }
};