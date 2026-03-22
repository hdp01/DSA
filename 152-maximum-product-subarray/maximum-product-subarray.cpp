class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0];        
        for (int i = 0; i < nums.size(); i++) {
            int current_product = 1;
            for (int j = i; j < nums.size(); j++) {
                current_product *= nums[j];
                maxp = max(maxp, current_product);
            }
        }
        return maxp;
    }
};