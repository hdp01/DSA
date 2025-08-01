#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
	int temp;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	cout<<"sorted array"<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<endl;
	}
}

int main(){
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cout<<"enter data: ";
		cin>>arr[i];
	}
	bubble_sort(arr, n);
}
