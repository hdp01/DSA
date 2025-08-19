#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = sol.maxProfit(prices);
    cout << "The maximum profit is: " << profit << endl;
    return 0;
}
