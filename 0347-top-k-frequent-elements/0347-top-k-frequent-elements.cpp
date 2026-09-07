class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto it = mp.begin(); it != mp.end(); it++){
            int element = it->first;
            int frequency = it->second;

            bucket[frequency].push_back(element);
        }
        vector<int> ans;
        for(int i = nums.size(); i >= 1 && ans.size() < k; i--){
            for(int j = 0; j < bucket[i].size() && ans.size() < k; j++){
                ans.push_back(bucket[i][j]);
            }
        }
        return ans;
    }
};