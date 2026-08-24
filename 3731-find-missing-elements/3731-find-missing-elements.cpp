class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> missing;
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            // Expected value at index i is: nums[0] + i + diff
            // Instead, we can think: at index i, we should have something close to nums[0] + i
            while (nums[i] > nums[0] + i + diff) {
                missing.push_back(nums[0] + i + diff);
                diff++;
            }
            // If nums[i] == nums[0] + i + diff, then no gap here; just continue
        }

        return missing;
    }
};