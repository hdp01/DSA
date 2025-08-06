#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int num){
	for(int i=0; i<arr.size();i++){
		if(arr[i]==num){
			return i;
		}
	}
	return -1;
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
	int find;
	cout<<"element to find? ";
	cin>>find;
	int index = linearSearch(arr, find);
	cout<<"element found on the index : "<<index;
	return 0;
}
