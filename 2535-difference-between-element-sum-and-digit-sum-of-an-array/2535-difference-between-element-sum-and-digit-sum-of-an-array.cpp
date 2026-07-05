class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elemSum = 0, digitSum = 0;
        for (int n : nums) {
            elemSum += n;
            while (n > 0) {
                digitSum += n % 10;
                n /= 10;
            }
        }
        return abs(elemSum - digitSum);
    }
};