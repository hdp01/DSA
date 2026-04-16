class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        unordered_map<int, int> lastPosition;
        for (int i = -n; i < n; i++) {
            int index = ((i % n) + n) % n;
            if (i >= 0) {
                auto it = lastPosition.find(nums[i]);
                left[i] = it == lastPosition.end() ? i - n : it->second;
            }
            lastPosition[nums[index]] = i;
        }
        lastPosition.clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;
            if (i < n) {
                auto it = lastPosition.find(nums[i]);
                right[i] = it == lastPosition.end() ? i + n : it->second;
            }
            lastPosition[nums[index]] = i;
        }
        vector<int> answer;
        answer.reserve(queries.size());
        for (int query : queries) {
            if (query - left[query] == n) {
                answer.push_back(-1);
            } else {
                answer.push_back(min(query - left[query], right[query] - query));
            }
        }
        return answer;
    }
};