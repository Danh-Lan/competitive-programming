#include<bits/stdc++.h>
 
using namespace std;

string getScores(string s, unordered_map<char, pair<int,int>>& pos) {
  vector<int> row(3, 0), col(3, 0);
  int diag = 0, antiDiag = 0;
  bool diagCheck = false, antiDiagCheck = false;

  string scores = "";
  for (int i = 0; i < s.length(); i++) {
    pair<int,int> p = pos[s[i]];
    int x = p.first, y = p.second;
    int score = 0;

    row[x]++; col[y]++;
    if (row[x] == 3) score++;
    if (col[y] == 3) score++;

    if (x == y) {
      diag++;
      if (diag == 3) score++;
    }
    if (x+y == 2) {
      antiDiag++;
      if (antiDiag == 3) score++;
    }

    scores.append(to_string(score));
  }

  return scores;
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
    string s;
    cin >> s;

    unordered_map<char, pair<int,int>> pos;
    for (int i = 0; i < 3; i++) {
      string row; cin >> row;
      for (int j = 0; j < 3; j++) {
        pair<int,int> p = {i, j};
        pos[row[j]] = p;
      }
    }

    string scores = getScores(s, pos);
    string bestSeed = s;
    sort(s.begin(), s.end());

    do {
      if (getScores(s, pos) == scores) {
        bestSeed = s;
        break;
      }
    } while (next_permutation(s.begin(), s.end()));

    cout << scores << ' ' << bestSeed << '\n';
  }

  return 0;
}