class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            vector<int> t;
            while (x > 0) {
                t.push_back(x % 10);  
                x /= 10;
            }
            reverse(t.begin(), t.end());  
            ans.insert(ans.end(), t.begin(), t.end());  
        }
        return ans;
    }
};   