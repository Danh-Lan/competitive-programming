// https://leetcode.com/problems/sum-of-distances/description/

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        for (auto it: m) {
            int sz = it.second.size();
            if (sz == 1) continue;

            long long sum = 0;
            for (int i = 1; i < sz; i++) {
                sum += (it.second[i] - it.second[0]);
            }

            ans[it.second[0]] = sum;
            for (int i = 1; i < sz; i++) {
                sum += (2*i - sz) * (it.second[i] - it.second[i-1]);
                ans[it.second[i]] = sum;
            }
        }

        return ans;
    }
};