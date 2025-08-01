#include<bits/stdc++.h>
using namespace std;
int findSecondLargest(vector<int>& arr){
	int temp = arr[0];
	int secondLargest = -1;
	for(int i=1; i<arr.size();i++){
		if(arr[i]>temp){
			secondLargest = temp;
			temp = arr[i];
		} else if (arr[i] < temp && arr[i] > secondLargest){
			secondLargest = arr[i];
		}
	}
	return secondLargest;
}
int main(){
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	vector<int> arr;
	for(int i=0; i<n; i++){
		int element;
		cout<<"enter element: ";
		cin>>element;
		arr.push_back(element);
	}
	int ans = findSecondLargest(arr);
	cout<<"second largest element = "<<ans;
	return 0;
}
