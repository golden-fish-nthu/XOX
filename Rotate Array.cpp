#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    vector<int> num2;
    num2.assign(nums.end() - k, nums.end());
    nums.erase(nums.end() - k, nums.end());
    nums.insert(nums.begin(), num2.begin(), num2.end());
    for (auto i : nums)
        cout << i << " ";
    return 0;
}

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        vector<int> num2;
        num2.assign(nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
        nums.insert(nums.begin(), num2.begin(), num2.end());
    }
};