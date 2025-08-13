#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int start = 0;
        int arrStart = -1, arrEnd = -1;
        long long maxi = LLONG_MIN;
        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (sum == 0) {
                start = i;
            }
            
            sum += arr[i];

            if (sum > maxi) {
                maxi = sum;
                arrStart = start;
                arrEnd = i;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        cout << "The subarray with the largest sum is: [ ";
        for (int i = arrStart; i <= arrEnd; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int maxSum = sol.maxSubArray(nums);
    
    cout << "The maximum sum is: " << maxSum << endl;

    return 0;
}
