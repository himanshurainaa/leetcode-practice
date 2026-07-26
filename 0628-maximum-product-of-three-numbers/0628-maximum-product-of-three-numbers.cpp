#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Option 1: Product of the three largest numbers
        int product1 = nums[n-1] * nums[n-2] * nums[n-3];
        
        // Option 2: Product of the two smallest (negative) numbers and the largest number
        int product2 = nums[0] * nums[1] * nums[n-1];
        
        // Return the maximum of the two options
        return max(product1, product2);
    }
};