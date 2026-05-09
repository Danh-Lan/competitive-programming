// https://codeforces.com/contest/2137/problem/F

#include<bits/stdc++.h>
 
using namespace std;

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
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    long long ans = 0ll;
    vector<int> st;
    for (int i = 0; i < n ; i++) {
      if (a[i] == b[i]) {
        ans += 1ll * (i+1) * (n-i);
      } else {
        if (!st.empty()) {
          // find max j < i such that a[j] >= max(a[i], b[i])
          int need = max(a[i], b[i]);
        
          int l = 0, r = st.size()-1;

          while (l < r) {
            int mid = (l+r+1)/2;
            if (a[st[mid]] >= need) {
              l = mid;
            } else {
              r = mid-1;
            }
          }
          
          if (a[st[l]] >= need) { // such l may not exist
            ans += 1ll * (st[l]+1) * (n-i);
          }
        }
      }

      while (!st.empty() && a[st.back()] <= a[i]) {
        st.pop_back();
      }

      st.push_back(i);
    }

    cout << ans << '\n';
  }

  return 0;
}