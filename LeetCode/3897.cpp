// https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments/description/

class Solution {
public:
    long long powMod(long long x, int n, int M) {
        long long res = 1LL;
    
        while (n >= 1) {
            if (n & 1) {
                res = (res * x) % M;
                n--;
            } else {
                x = (x * x) % M;
                n /= 2;
            }
        }
        return res;
    }
    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        const int MOD = 1e9 + 7;
        
        vector<pair<int, int>> v;
        int count = 0;
        
        for (int i = 0; i < nums1.size(); ++i) {
            v.push_back({nums1[i], nums0[i]});
            count += nums1[i] + nums0[i];
        }
    
        sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if ((a.second == 0) != (b.second == 0))
                return a.second == 0;
            
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });

        // for (int i = 0; i < v.size(); ++i) {
        //     cout << v[i].first << ' ' << v[i].second << endl;
        // }
        
        long long ans = 0LL;
        for (int i = 0; i < v.size(); ++i) {
            for (int _ = 0; _ < v[i].first; ++_) {
                ans = (ans + powMod(2LL, count-1, MOD)) % MOD;
                count--;
            }
            count -= v[i].second;
        }

        return ans;
    }
};