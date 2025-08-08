#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0;
    int count=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==1){
            count++;
            maxi = max(maxi,count);
        } else {
            count=0;
        }
    }
    return maxi;
}

int main() {
    vector<int> test_nums = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int max_ones = findMaxConsecutiveOnes(test_nums);
    cout << "For the input vector: {1, 1, 0, 1, 1, 1, 0, 1, 1}" <<endl;
    cout << "The maximum number of consecutive ones is: " << max_ones <<endl;
    return 0;
}
