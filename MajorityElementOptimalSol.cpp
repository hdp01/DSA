#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int ele;
        for(int i=0; i<n; i++){
            if(count == 0){
                count = 1;
                ele = nums[i];
            } else if(nums[i]==ele){
                count++;
            } else {
                count--;
            }
        }
        int count1= 0;
        for(int i=0; i<n; i++){
            if(nums[i]==ele){
                count1++;
            }
        }
        if(count1>n/2){
            return ele;
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
