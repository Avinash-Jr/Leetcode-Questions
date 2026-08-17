class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;   // to store unique numbers
        // traverse the vector
        for (int i = 0; i < nums.size(); i++) {
            // if nums[i] already present in set → duplicate
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            // insert into set
            s.insert(nums[i]);
        }
        // no duplicates found
        return false;
    }
};