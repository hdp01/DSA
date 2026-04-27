class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m * n);
        componentSize.assign(m * n, 1);
        for (int i = 0; i < m * n; i++) {
            parent[i] = i;
        }
        vector<int> patterns = {0, 0b1010, 0b0101, 0b1100, 0b0110, 0b1001, 0b0011};
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int pattern = patterns[grid[row][col]];
                for (int dir = 0; dir < 4; dir++) {
                    if ((pattern & (1 << dir)) == 0) {
                        continue;
                    }
                    int nextRow = row + dirs[dir][0];
                    int nextCol = col + dirs[dir][1];
                    if (
                        nextRow >= 0 && nextRow < m &&
                        nextCol >= 0 && nextCol < n &&
                        (patterns[grid[nextRow][nextCol]] & (1 << ((dir + 2) % 4))) != 0
                    ) {
                        unite(row * n + col, nextRow * n + nextCol);
                    }
                }
            }
        }
        return find(0) == find(m * n - 1);
    }

private:
    vector<int> parent;
    vector<int> componentSize;
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return;
        }
        if (componentSize[rootA] < componentSize[rootB]) {
            swap(rootA, rootB);
        }
        parent[rootB] = rootA;
        componentSize[rootA] += componentSize[rootB];
    }
};