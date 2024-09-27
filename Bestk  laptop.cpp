#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int low = prices[0];
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < low) {
            low = prices[i];
        } else {
            int profit = prices[i] - low;
            max_profit = max(max_profit, profit);
        }
    }

    cout << max_profit;
    return 0;
}

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int low = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < low) {
                low = prices[i];
            } else {
                int profit = prices[i] - low;
                max_profit = max(max_profit, profit);
            }
        }
        return max_profit;
    }
};