#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto it : mpp) {
            if (it.second > n / 2) {
                return it.first;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};

    int majority = sol.majorityElement(nums);

    cout << "The majority element is: " << majority << endl;

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    int majority2 = sol.majorityElement(nums2);
    cout << "The majority element is: " << majority2 << endl;
    
    return 0;
}
