class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int product1 = (nums[0] - 1) * (nums[1] - 1);
        int product2 = (nums[n - 1] - 1) * (nums[n - 2] - 1);

        return max(product1, product2);
    }
};