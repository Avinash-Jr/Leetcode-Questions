class Solution {
public:
        void solve(vector<int>& nums,int index,vector<int>& current,
        vector<vector<int>>& ans
    )
    {
        // BASE CASE
        if (index == nums.size()){
            ans.push_back(current);
            return;
        }
        // CASE 1: INCLUDE nums[index]
        current.push_back(nums[index]);
        solve(nums,index + 1,current,ans);

        // BACKTRACK
        current.pop_back();
        // CASE 2: EXCLUDE nums[index]
        /*
            If the next elements are duplicates,
            skip them.
                nums = [1,2,2]
                index = 1
                We exclude the first 2.
                Move directly to the end of all
                consecutive 2s.
        */
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index])
        {
            next++;
        }
        solve(nums,next,current,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> current;
        // Put duplicates together.
        sort(nums.begin(), nums.end());
        solve(nums,0,current,ans);
        return ans;
    }
};

