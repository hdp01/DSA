class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(1);
        vector<bool> seen(n + 1, false);
        seen[1] = true;
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            depth++; 
            for (int i = 0; i < size; ++i) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (!seen[v]) {
                        seen[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        if (depth <= 1) return 0;
        long long mod = 1e9 + 7;
        return modPow(2, depth - 2, mod);
    }
private:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};   