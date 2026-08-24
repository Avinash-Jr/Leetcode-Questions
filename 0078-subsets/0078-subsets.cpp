class Solution {
    void solve(vector<int> ip, vector<int> op, vector<vector<int>>& res) {
        if (ip.empty()) { res.push_back(op); return; }   // BASE
        vector<int> op1 = op;              // exclude ip[0]
        vector<int> op2 = op;
        op2.push_back(ip[0]);              // include ip[0]

        ip.erase(ip.begin());              // input shrinks by one
        solve(ip, op1, res);
        solve(ip, op2, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums, {}, res);
        return res;
    }
};