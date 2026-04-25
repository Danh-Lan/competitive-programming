// https://leetcode.com/problems/maximum-points-activated-with-one-addition/description/

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
            int rootI = find(i), rootJ = find(j);
            if (rootI != rootJ) {
                par[rootI] = rootJ;
            }
        }
    };

    int maxActivated(vector<vector<int>>& points) {
        DSU dsu(2 * points.size());

        unordered_map<int, int> mx, my;
        int index = 0;

        for (auto p: points) {
            int x = p[0], y = p[1];
            if (!mx.count(x)) mx[x] = index++;
            if (!my.count(y)) my[y] = index++;
            dsu.merge(mx[x], my[y]);
        }

        unordered_map<int, int> count;
        for (auto p: points) {
            count[dsu.find(mx[p[0]])]++;
        }

        vector<int> sizes;
        for (auto it: count) {
            sizes.push_back(it.second);
        }
        sort(sizes.begin(), sizes.end(), greater<int>());

        int ans = 0;
        if (sizes.size() == 1) {
            ans = sizes[0] + 1;
        } else {
            ans = sizes[0] + sizes[1] + 1;
        }

        return ans;
    }
};