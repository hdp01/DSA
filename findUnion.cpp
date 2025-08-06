#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b){
//	set<int> temp;
//	vector<int> uni;
//	for (int element : arr) {
//        temp.insert(element);
//    }
//    for (int element : num) {
//        temp.insert(element);
//    }
//    for (int element : temp) {
//        uni.push_back(element);
//    }
//	cout<<"union of both the arrays : ";
//	for(int i=0;i<uni.size();i++){
//		cout<<uni[i]<<" ";
//	}
	int n1=a.size();
	int n2=b.size();
	int i=0;
	int j=0;
	vector<int> unionarr;
	while(i<n1 && j<n2){
		if(a[i]<=b[j]){
			if (unionarr.size()==0 || unionarr.back()!=a[i]){
				unionarr.push_back(a[i]);
			} 
			i++;
		} else {
			if(unionarr.size()==0 || unionarr.back()!=b[j]){
				unionarr.push_back(b[j]);
			}
			j++;
		}
	}
	while(j<n2){
		if(unionarr.size()==0 || unionarr.back()!=b[j]){
			unionarr.push_back(b[j]);
		}
		j++;
	}
	while(i<n1){
		if(unionarr.size()==0 || unionarr.back()!=a[i]){
			unionarr.push_back(a[i]);
		}
		i++;
	}
	return unionarr;
}

int main(){
	int n,m;
	cout<<"enter size of 1st array: ";
	cin>>n;
	vector<int> arr1, arr2;
	for(int i=0; i<n; i++){
		int element;
		cout<<"enter element in 1st array: ";
		cin>>element;
		arr1.push_back(element);
	}
	cout<<"enter size of 2nd array: ";
	cin>>m;
	for(int i=0; i<m; i++){
		int element;
		cout<<"enter element in 2nd array: ";
		cin>>element;
		arr2.push_back(element);
	}
	vector<int> result = findUnion(arr1, arr2);
    cout << "Union of both the arrays: ";
    for (int element : result) {
        cout << element << " ";
    }
	return 0;
}
