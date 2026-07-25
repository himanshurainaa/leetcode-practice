class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int start, end;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            start = i + 1;
            end = nums.size() - 1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target) {
                    return sum;
                }   
                if(abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                if(sum < target) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        
        return closestSum;
    }
};