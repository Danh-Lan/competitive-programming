// https://leetcode.com/problems/jump-game-v/description/

class Solution {
public:
    int cnt[1000];

    int dfs(int i, vector<int>& arr, int n, int d) {
        if (cnt[i]) return cnt[i];

        int best = 1;
        int mxLeft = 0, mxRight = 0;
        for (int j = i-1; j >= max(i-d, 0); j--) {
            mxLeft = max(mxLeft, arr[j]);
            if (mxLeft < arr[i]) best = max(best, 1 + dfs(j, arr, n, d));
            else break;
        }
        for (int j = i+1; j <= min(i+d, n-1); j++) {
            mxRight = max(mxRight, arr[j]);
            if (mxRight < arr[i]) best = max(best, 1 + dfs(j, arr, n, d));
            else break;
        }

        return cnt[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        memset(cnt, 0, sizeof(cnt));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, n, d));
        }

        return ans;
    }
};