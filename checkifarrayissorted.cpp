//check if the array is sorted
#include<bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int>& nums){
	if (nums.size() <= 1) {
        return true;
    }
	for(int i=0; i<nums.size()-1; i++){
		if (nums[i] > nums[i+1]) {
            return false;
        }
	}
	return true;
}
int main(){
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	vector<int> nums;
	for(int i=0; i<n; i++){
		int element;
		cout<<"enter "<<i<<" element: ";
		cin>>element;
		nums.push_back(element);
	} 
	bool ans = checkSorted(nums);
	cout<<"is array sorted? "<<ans;
	return 0;
}
