// https://leetcode.com/problems/smallest-unique-subarray/description/

// to reduce collision : use 2 pair of modulus and base, modulus pick a large prime number, i.e. 10^9+7, 998244353, ...
// the base doesn't have to be a prime

class Solution {
public:
    const int A = 1e5 + 3, MOD = 1e9 + 7;
    vector<long long> pow;

    void initPow(int base, int n, int mod) {
        pow[0] = 1ll;
        for (int i = 1; i < n; i++) {
            pow[i] = (pow[i-1] * base) % mod;
        }
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        pow.resize(n);
        initPow(A, n, MOD);

        int l = 1, r = n;
        while (l < r) {
            int m = (l+r)/2;

            bool unique = false;
            unordered_map<int, int> freq;

            long long h = 0ll;
            for (int i = 0; i < m; i++) {
                h = (h * A + nums[i]) % MOD;
            }

            freq[h]++;
            for (int i = 1; i <= n-m; i++) {
                h = (h - nums[i-1] * pow[m-1]) % MOD;
                if (h < 0) h += MOD;
                h = (h * A + nums[i+m-1]) % MOD;

                freq[h]++;
            }

            for (auto [hash, cnt] : freq) {
                if (cnt == 1) {
                    unique = true;
                    break;
                }
            }

            if (unique) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return l;
    }
};