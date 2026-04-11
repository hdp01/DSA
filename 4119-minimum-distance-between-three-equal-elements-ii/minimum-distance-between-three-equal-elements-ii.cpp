class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1);
        vector<int> last(n + 1, -1);

        for (int i = n - 1; i >= 0; i--) {
            int value = nums[i];
            next[i] = last[value];
            last[value] = i;
        }

        int answer = INT_MAX;

        for (int i = 0; i < n; i++) {
            int second = next[i];
            if (second == -1) {
                continue;
            }

            int third = next[second];
            if (third == -1) {
                continue;
            }

            answer = min(answer, (third - i) * 2);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};