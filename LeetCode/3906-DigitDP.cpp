// https://leetcode.com/problems/count-good-integers-on-a-grid-path/

// dp state: current position, value of last digit on the path, tight constraint
class Solution {
public:
    bool onPath[16];
    long long memo[17][10][2];
    string s;

    long long dp(int pos, int lastD, bool t) {
        if (pos == 16) return 1;

        if (memo[pos][lastD][t] != -1) {
            return memo[pos][lastD][t];
        }

        long long res = 0;
        int lim = t ? (s[pos] - '0') : 9;

        for (int d = 0; d <= lim; d++) {
            if (onPath[pos]) {
                if (d >= lastD) {
                    res += dp(pos+1, d, t && d == lim);
                }
            } else {
                res += dp(pos+1, lastD, t && d == lim);
            }
        }

        memo[pos][lastD][t] = res;

        return res;
    }

    long long calc(long long n) {
        memset(memo, -1, sizeof(memo));

        s = to_string(n);
        string append = string(16 - s.length(), '0');
        s = append + s;

        return dp(0, 0, true);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        onPath[0] = true;

        int i = 0;
        for (char d: directions) {
            if (d == 'D') i += 4;
            else i++;
            onPath[i] = true;
        }

        return calc(r) - calc(l-1);
    }
};