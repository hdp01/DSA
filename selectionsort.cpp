#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, temp;
	cout<<"enter size of array: ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cout<<"enter data: ";
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		int min_idx = i;
		for(int j=i+1; j<n; j++){
			if(arr[min_idx]>arr[j]){
				min_idx = j;
			}
		}
		if (min_idx != i) {
            temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
        }
	}
	cout<<"sorted array"<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
