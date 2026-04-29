// https://codeforces.com/contest/2044/problem/F

// We track the set of (sumA - a[i]) and (sumB - b[i]), only keep those whose absolute value is in range of x, that is [-2e5, 2e5]
// Then for each query we factorize and iterate over the divisors d to match with the 2 set
// There's 4 cases to check the match: (d, x/d), (x/d, d), (-d, -x/d), (-x/d, -d)
// We use memoization to optimize, since the query value may repeat

#include<bits/stdc++.h>

using namespace std;

const int N = 200000;
vector<bool> is_prime(N+1, true);
vector<int> primes;

void sieve() {
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);

      for (long long j = 1LL * i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

bool exist(int d, set<int>& s) {
  return (s.find(d) != s.end());
}

bool match(int d1, int d2, set<int>& sa, set<int>& sb) {
  if (exist(d1, sa) && exist(d2, sb)) return true;
  if (exist(d2, sa) && exist(d1, sb)) return true;
  if (exist(-d1, sa) && exist(-d2, sb)) return true;
  if (exist(-d2, sa) && exist(-d1, sb)) return true;

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout); 
  #endif

  sieve();

  int tt = 1;
  // cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int n, m, q;
    cin >> n >> m >> q;

    int a[n], b[m];
    long long sumA = 0LL, sumB = 0LL;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sumA += a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      sumB += b[i];
    }

    set<int> sa, sb;
    for (int i = 0; i < n; i++) {
      long long restA = sumA - a[i];
      if (restA <= N && restA >= -N) sa.insert(restA);
    }
    for (int i = 0; i < m; i++) {
      long long restB = sumB - b[i];
      if (restB <= N && restB >= -N) sb.insert(restB);
    }

    map<int, bool> memo;
    while (q--) {
      int x; cin >> x;
      if (memo.count(x)) {
        cout << (memo[x] ? "YES\n": "NO\n");
        continue;
      }

      vector<pair<int,int>> factors;
      int cur = abs(x);
      for (auto p: primes) {
        if (cur % p == 0) {
          int count = 0;
          while (cur % p == 0) {
            count++;
            cur /= p;
          }

          factors.push_back({p, count});
        }

        if (cur == 1) break;
      }

      vector<int> divisors = {1};
      for (auto it: factors) {
        int p = it.first, e = it.second;
        int sz = divisors.size();
        int cur = 1;

        for (int i = 1; i <= e; i++) {
          cur *= p;
          for (int j = 0; j < sz; j++) {
            divisors.push_back(divisors[j] * cur);
          }
        }
      }

      bool flag = false;
      for (auto d: divisors) {
        if (match(d, x/d, sa, sb)) {
          flag = true;
          break;
        }
      }

      memo[x] = flag;
      cout << (flag ? "YES\n" : "NO\n");
    }
  }

  return 0;
}