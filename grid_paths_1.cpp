#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
void run()
{
  int n;
  cin >> n;
  string grid[n];
  for (int i = 0; i < n; i++)
  {
    cin >> grid[i];
  }

  vector<vector<int>> dp(n, vector<int>(n));
  // dp[i][j] = No ways to go from (i,j) to (n-1), (n-1)

  // Base Case
  if (grid[n - 1][n - 1] == '*')
    dp[n - 1][n - 1] = 0; // Impossible to reach with the last block being an obstacle
  else
    dp[n - 1][n - 1] = 1;

  // Finding the ways
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (i == n - 1 && j == n - 1)
        continue;
      if (grid[i][j] == '*')
        dp[i][j] = 0;
      else
      {
        int ans1 = i < n - 1 ? dp[i + 1][j] : 0;
        int ans2 = j < n - 1 ? dp[i][j + 1] : 0;
        // transition
        dp[i][j] = (ans1 + ans2) % M;
      }
    }
  }
  cout << dp[0][0] << "\n";
}

int main()
{
  run();
  return 0;
}