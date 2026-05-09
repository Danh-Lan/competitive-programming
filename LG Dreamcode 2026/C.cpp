#include<bits/stdc++.h>
 
using namespace std;

const int MOD = 1e9 + 7;

void makePrefix(vector<string>& cake, int r, int c, vector<vector<vector<int>>>& pref) {
  string fruits = "SBR";

  for (int x = 0; x < 3; x++) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (cake[i][j] == fruits[x]) {
          pref[x][i][j] = 1;
        }
      }
    }
  }
  
  for (int x = 0; x < 3; x++) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (i > 0) {
          pref[x][i][j] += pref[x][i-1][j];
        }
        if (j > 0) {
          pref[x][i][j] += pref[x][i][j-1];
        }
        if (i > 0 && j > 0) {
          pref[x][i][j] -= pref[x][i-1][j-1];
        }
      }
    }
  }
}

bool query(vector<vector<int>>& pref, int r1, int c1, int r2, int c2) {
  int total = pref[r2][c2];
  int top = (r1 > 0) ? pref[r1 - 1][c2] : 0;
  int left = (c1 > 0) ? pref[r2][c1 - 1] : 0;
  int overlap = (r1 > 0 && c1 > 0) ? pref[r1 - 1][c1 - 1] : 0;

  int sum = total - top - left + overlap;
  return (sum > 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout); 
  #endif

  int tt = 1;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int r, c, n;
    cin >> r >> c >> n;

    // prefix sum
    vector<vector<vector<int>>> pref(3, vector<vector<int>>(r, vector<int>(c, 0)));
    
    vector<string> cake(r);
    for (int i = 0; i < r; i++) {
      cin >> cake[i];
    }

    makePrefix(cake, r, c, pref);

    string fav; cin >> fav;

    // dp[i][j][k]: number of ways to cut after serving k friends
    // remaining rectangle is (i, j) -> (r-1, c-1)
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(r, vector<long long>(c, 0ll)));
    dp[0][0][0] = 1;
    map<char, int> idFruit = {{'S', 0}, {'B', 1}, {'R', 2}};

    for (int k = 0; k < n-1; k++) {
      int id = idFruit[fav[k]];
      
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (dp[k][i][j] == 0) continue;

          for (int i1 = i+1; i1 < r; i1++) {
            if (query(pref[id], i, j, i1-1, c-1)) {
              dp[k+1][i1][j] = (dp[k+1][i1][j] + dp[k][i][j]) % MOD;
            }
          }

          for (int j1 = j+1; j1 < c; j1++) {
            if (query(pref[id], i, j, r-1, j1-1)) {
              dp[k+1][i][j1] = (dp[k+1][i][j1] + dp[k][i][j]) % MOD;
            }
          }
        }
      }
    }

    long long ans = 0ll;
    int idLastFruit = idFruit[fav[n-1]];
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (query(pref[idLastFruit], i, j, r-1, c-1)) {
          ans = (ans + dp[n-1][i][j]) % MOD;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}