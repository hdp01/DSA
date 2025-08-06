#include<bits/stdc++.h>
using namespace std;

void movezerostoend(vector<int>& arr){
	int j=-1;
    for(int i=0; i<arr.size();i++){
	    if(arr[i]==0){
            j=i;
            break;
        }
	}
    if(j==-1){
    	return;
    } else {
        for(int i=j+1; i<arr.size();i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
//		vector<int> temp;
//	    for(int i=0; i<arr.size(); i++){
//		    if(arr[i]!=0){
//			    temp.push_back(arr[i]);
//		    }
//	    }
//        int nonz=temp.size();
//	    for(int i=0; i<temp.size(); i++){
//		    arr[i] = temp[i];
//	    }
//	    for(int i=nonz; i<arr.size(); i++){
//		    arr[i]=0;
//	    }
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
	movezerostoend(arr);
	return 0;
}
