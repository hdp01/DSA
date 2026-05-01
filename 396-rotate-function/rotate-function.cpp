class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int current = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            current += i * nums[i];
        }
        int answer = current;
        for (int i = n - 1; i > 0; i--) {
            current += total - n * nums[i];
            answer = max(answer, current);
        }
        return answer;
    }
};