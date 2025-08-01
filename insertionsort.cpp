#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		int j=i;
		while(j>0 && arr[j-1]>arr[j]){
			int temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			
			j--;
		}
	}
	cout<<"sorted array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int n;
	cout<<"enter size of array:";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cout<<"enter number:";
		cin>>arr[i];
	}
	cout<<"entered array: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	insertionSort(arr,n);
	return 0;
}
