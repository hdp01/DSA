#include<bits/stdc++.h>
using namespace std;

int findLargest(vector<int>& nums) {
    int temp = nums[0];
    for(int i=1; i<nums.size(); i++){
        if(nums[i]>temp){
            temp = nums[i];
        }
    }
    return temp;
}

int main(){
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	vector<int> nums;
	for(int i=0; i<n; i++){
		int element;
		cout<<"enter element: ";
		cin>>element;
		nums.push_back(element);
	}
	int ans = findLargest(nums);
	cout<<"largest element = "<<ans;
	return 0;
}
