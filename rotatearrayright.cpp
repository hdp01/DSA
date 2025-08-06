#include<bits/stdc++.h>
using namespace std;

void rotateRight(vector<int>& nums, int k){
	int n = nums.size();
	for(int j=0; j<k; j++){
		int temp = nums[n-1];
		for(int i=n-2; i>=0; i--){
			nums[i+1] = nums[i];
		}
		nums[0] = temp;
	}
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
	int k;
	cout<<"enter number of steps for rotation: ";
	cin>>k;
	rotateRight(nums, k);
	cout<<"array after rotation: ";
	for(int i=0; i<n; i++){
		cout<<"value on "<<i<<" element: "<<nums[i]<<endl;
	}
	return 0;
}
