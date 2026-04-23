// https://leetcode.com/problems/multi-source-flood-fill/

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        priority_queue<tuple<int,int,int>> pq; // color, r, c

        for (int i = 0; i < sources.size(); i++) {
            int r = sources[i][0], c = sources[i][1], color = sources[i][2];
            ans[r][c] = color;
            pq.push({color, r, c});
        }

        while (true) {
            priority_queue<tuple<int,int,int>> new_pq;
            
            while (!pq.empty()) {
                tuple<int,int,int> tp = pq.top();
                auto [color, r, c] = tp;
                pq.pop();

                for (int i = 0 ; i < 4; i++) {
                    int x = r + dx[i], y = c + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        if (ans[x][y] == 0) {
                            ans[x][y] = ans[r][c];
                            new_pq.push({color, x, y});
                        }
                    }
                }
            }

            if (new_pq.empty()) break;

            pq = move(new_pq);
        }

        return ans;
    }
};