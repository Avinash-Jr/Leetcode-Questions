class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int currentSum = nums[i] + nums[lo] + nums[hi];
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }
            if (currentSum == target) {
                return currentSum;
            } else if (currentSum < target) {
                lo++;
            } else {
                hi--;
            }
        }
    }
    return closestSum;
}
};