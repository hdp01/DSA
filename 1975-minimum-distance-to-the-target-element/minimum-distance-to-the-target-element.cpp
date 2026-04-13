class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int temp=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                int cdist = abs(i-start);
                if(cdist<temp){
                    temp=cdist;
                }
            }
        }
        return temp;
    }
};