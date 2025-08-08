#include<bits/stdc++.h>
using namespace std;

int missingVal(vector<int>& nums){
	int n = nums.size();
	int expected = n * (n + 1) / 2;
	int actual = 0;
	for(int i=0; i<n; i++){
		actual += nums[i];
	}
	return expected-actual;
}

int main() {
    vector<int> numbers = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int missing_number = missingVal(numbers);
    cout << "The input vector is: {9, 6, 4, 2, 3, 5, 7, 0, 1}" << endl;
    cout << "The missing number is: " << missing_number << endl;
    return 0;
}
