// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

class Solution {
public:
    struct DSU {
        vector<int> par;
        DSU(int n) : par(n) {
            for (int i = 0; i < n; ++i) par[i] = i;
        }
        int find(int i) {
            return (par[i] == i ? i : (par[i] = find(par[i])));
        }
        void merge(int i, int j) {
            i = find(i); j = find(j);
            if (i != j) par[i] = j;
        }
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        DSU dsu(source.size());

        for (int i = 0; i < allowedSwaps.size(); i++) {
            dsu.merge(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        unordered_map<int, unordered_map<int,int>> count;
        for (int i = 0; i < source.size(); i++) {
            int par = dsu.find(i);

            count[par][source[i]]++;
            count[par][target[i]]--;
        }

        int ans = 0;
        for (auto it: count) {
            for (auto [node, count]: it.second) {
                if (count > 0) ans += count;
            }
        }

        return ans;
    }
};v