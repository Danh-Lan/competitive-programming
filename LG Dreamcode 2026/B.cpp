#include<bits/stdc++.h>
 
using namespace std;

const int MOD = 1e9 + 7;

long long fact(int n, int mod = MOD) {
  long long res = 1ll;
  for (int x = 2; x <= n; x++) res = (res*x) % MOD;
  return res;
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
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> freq(n, 0);
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      x--; y--;

      freq[x]++;
      if (y < n-1) {
        freq[y+1]--;
      }
    }

    map<int, int> mp;
    mp[freq[0]]++;
    for (int i = 1; i < n; i++) {
      freq[i] += freq[i-1];
      mp[freq[i]]++;
    }

    sort(a, a+n, greater<int>());
    int idx = 0;

    long long count = 1ll;
    long long sum = 0ll;
    
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
      int fq = it->first;
      int c = it->second;

      long long s = 0ll;
      for (int k = idx; k < idx+c; k++) {
        s += a[k];
      }
      idx += c;

      // calcluation
      count = (count * fact(c)) % MOD;
      sum += s * fq;
    }

    cout << sum <<  ' ' << count << endl;
  }

  return 0;
}