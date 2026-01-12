/* //// QUESTION ////
Consider a money system consisting of n coins. Each coin has a positive integer value.
 Your task is to calculate the number of distinct ordered ways you can produce a
 money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 9
2 3 5

Output:
3
*/
// HINT-1
//  The issue is that we have to consider the same combination
//  even with different order as a single way
// Hint -2
// Try to pick all Ci before C1+1
// HINT -3
// Try to know the req sum and the coins which can still be picked
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 + 7;

void run()
{
  int n, x;
  cin >> n, x;

  // constructing coins array
  vector<int> coins(n);
  for (auto &it : coins)
    cin >> it;

  // Hint-4
  // We have 2 choices of picking each coin(pick or skip)

  // Defining the state
  // dp[i][k] = No. of ways to get k such that all coins from i Ci to Cn are pickable and
  // all the coins before Ci are skipped
  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  //  Base case
  for (int i = 0; i < n; i++)
  {
    // Construct a sum of 0 such that all the coins from i to n-1 are pickable
    dp[i][0] = 1;
  }

  // dp[i][k] -> dp[i][k-some value], dp[i+1][k]

  for (int i = n - 1; i >= 0; i--)
  {
    for (int sum = 1; sum <= x; sum++)
    {
      // Find dp[i][sum]= dp[i+1][sum]
      int skipping = dp[i + 1][sum];

      // when we pick i
      int picking = 0;
      if (coins[i] <= sum)
        picking = dp[i][sum - coins[i]];

      // transition
      dp[i][sum] = (skipping + picking) % M;
    }
  }
  // Final subproblem
  cout << dp[0][x] << "\n";
}

int main()
{
  run();
}