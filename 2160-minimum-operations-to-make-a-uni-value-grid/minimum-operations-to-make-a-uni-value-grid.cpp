class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        vector<int> nums;
        nums.reserve(totalElements);
        int firstRemainder = grid[0][0] % x;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != firstRemainder) {
                    return -1; 
                }
                nums.push_back(grid[i][j]);
            }
        }
        auto median_it = nums.begin() + (totalElements / 2);
        nth_element(nums.begin(), median_it, nums.end());
        int median = *median_it;
        int operations = 0;
        for (int val : nums) {
            operations += abs(val - median) / x;
        }     
        return operations;
    }
};