class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        vector<long long> answer(n);
        for (auto& [value, indices] : groups) {
            long long total = 0;
            for (int index : indices) {
                total += index;
            }
            long long prefix = 0;
            int size = indices.size();
            for (int i = 0; i < size; i++) {
                int index = indices[i];
                long long left = 1LL * i * index - prefix;
                long long right = (total - prefix - index) - 1LL * (size - i - 1) * index;
                answer[index] = left + right;
                prefix += index;
            }
        }
        return answer;
    }
};