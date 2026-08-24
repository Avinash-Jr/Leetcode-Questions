class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        // Count frequency
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        // Sort according to frequency
        sort(nums.begin(), nums.end(),[&](int a, int b){
            // If frequency is same
            if(mp[a] == mp[b])
                return a > b;      // Larger number first
            // Otherwise smaller frequency first
            return mp[a] < mp[b];
        });
        return nums;
    }
};