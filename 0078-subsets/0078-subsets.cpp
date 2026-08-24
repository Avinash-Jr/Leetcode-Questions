class Solution {
public:

    /*
        For every element, we have 2 choices:
            1. Include the element
            2. Don't include the element      
    */

    void solve(
        vector<int>& nums,
        int index,
        vector<int>& current,
        vector<vector<int>>& ans
    )
    {
        // BASE CASE:
        // We have processed all elements.
        if (index == nums.size())
        {
            // Store the current subset.
            ans.push_back(current);
            return;
        }
        // OPTION 1: INCLUDE nums[index]
        current.push_back(nums[index]);
        solve(nums, index + 1, current, ans);

        // BACKTRACK
        // Remove the element before trying
        // the second possibility.
        current.pop_back();
        // OPTION 2: EXCLUDE nums[index]
        solve(nums, index + 1, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> current;
        solve(nums, 0, current, ans);
        return ans;
    }
};