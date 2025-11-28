class Solution {
public:
    int ans = 0; // 記錄合法的區塊數量

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // 1. 建圖
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // 2. DFS
        dfs(0, -1, adj, values, k);
        return ans;
    }

    // 回傳值：以 u 為根的子樹，對 k 取模後的餘數
    long long dfs(int u, int p, vector<vector<int>>& adj, vector<int>& values, int k) {
        long long current_sum = values[u];

        for (int v : adj[u]) {
            if (v == p) continue; // 避免走回頭路
            current_sum += dfs(v, u, adj, values, k);
        }

        // 3. 判斷切分
        if (current_sum % k == 0) {
            ans++; // 發現一個合法區塊，切！
            return 0; // 對父節點貢獻為 0
        }

        return current_sum % k; // 沒切掉，把餘數往上傳
    }
};