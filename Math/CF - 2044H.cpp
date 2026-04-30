// https://codeforces.com/contest/2044/problem/H

#include<bits/stdc++.h>
 
using namespace std;

// answer of (x1, y1, x2, y2) query is:
// sum (i = x1 to x2, j = y1 to y2) (i*(y2-y1+1) + j - (x1*(y2-y1+1) + (y1-1))
// separate into 3 2d prefix sums and precompute

long long getSum(int x1, int y1, int x2, int y2, vector<vector<long long>>& sum) {
  return (sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
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
    int n, q; cin >> n >> q;
    int a[n][n];

    // 2d prefix: sumRow = sum a[i][j]*i, sumCol = sum a[i][j]*j
    vector<vector<long long>> sum(n+1, vector<long long>(n+1, 0LL));
    vector<vector<long long>> sumRow(n+1, vector<long long>(n+1, 0LL));
    vector<vector<long long>> sumCol(n+1, vector<long long>(n+1, 0LL));
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        sum[i][j] = a[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        sumRow[i][j] = a[i-1][j-1] * i + sumRow[i-1][j] + sumRow[i][j-1] - sumRow[i-1][j-1];
        sumCol[i][j] = a[i-1][j-1] * j + sumCol[i-1][j] + sumCol[i][j-1] - sumCol[i-1][j-1];
      }
    }

    while (q--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      long long l = y2 - y1 + 1;

      long long ans = 0LL;
      ans += l * getSum(x1, y1, x2, y2, sumRow);
      ans += getSum(x1, y1, x2, y2, sumCol);
      ans -= (l * x1 + (y1 - 1)) * getSum(x1, y1, x2, y2, sum);

      cout << ans << ' ';
    } 
    cout << '\n';
  }

  return 0;
}