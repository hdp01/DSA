class Solution {
    static constexpr int MOD = 1'000'000'007;
    static constexpr int K_LOG = 17; 

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<int> ans;
        vector<int> depth(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        vector<vector<int>> parent(K_LOG, vector<int>(n + 1, -1));

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(1, -1, graph, parent, depth);
        for (int k = 1; k < K_LOG; ++k) {
            for (int v = 1; v <= n; ++v) {
                if (parent[k - 1][v] != -1) {
                    parent[k][v] = parent[k - 1][parent[k - 1][v]];
                }
            }
        }
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            if (u == v) {
                ans.push_back(0);
            } else {
                int lcaNode = lca(u, v, parent, depth);
                int d = depth[u] + depth[v] - 2 * depth[lcaNode];
                ans.push_back(modPow(2, d - 1));
            }
        }
        return ans;
    }

private:
    void dfs(int u, int p, const vector<vector<int>>& graph, vector<vector<int>>& parent, vector<int>& depth) {
        parent[0][u] = p;
        for (int v : graph[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, graph, parent, depth);
            }
        }
    }

    int lca(int u, int v, const vector<vector<int>>& parent, const vector<int>& depth) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int k = K_LOG - 1; k >= 0; --k) {
            if (parent[k][u] != -1 && depth[parent[k][u]] >= depth[v]) {
                u = parent[k][u];
            }
        }
        if (u == v) return u;
        for (int k = K_LOG - 1; k >= 0; --k) {
            if (parent[k][u] != -1 && parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    long modPow(long base, long exp) {
        long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
};   