#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = sol.maxSubArray(nums1);
    cout << "Max subarray sum for first array: " << result1 << endl;

    vector<int> nums2 = {5, 4, -1, 7, 8};
    int result2 = sol.maxSubArray(nums2);
    cout << "Max subarray sum for second array: " << result2 << endl;

    return 0;
}
