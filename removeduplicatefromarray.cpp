#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums){
	int i=0;
	for(int j=1; j<nums.size(); j++){
		if (nums[j]!=nums[i]) {
            nums[i+1] = nums[j];
            i++;
        }
	}
	return i+1;
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
	int ans = removeDuplicates(nums);
	cout<<"unique element count: "<<ans;
	return 0;
}
