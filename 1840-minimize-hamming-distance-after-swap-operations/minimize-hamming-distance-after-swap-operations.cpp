class Solution {
public:
    vector<int> parent;
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (auto& edge : allowedSwaps) {
            int a = edge[0], b = edge[1];  
            parent[find(a)] = find(b);
        }
        unordered_map<int, unordered_map<int, int>> compFreq;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            compFreq[root][source[i]]++;
        }
        int distance = 0;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            if (compFreq[root][target[i]] > 0) {
                compFreq[root][target[i]]--;
            } else {
                distance++;
            }
        }
        return distance;
    }
};   