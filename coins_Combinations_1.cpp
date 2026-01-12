/* //// QUESTIONS ////
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

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
8
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Using const ll avoids TLE so take care from next time
const ll M = 1e9 + 7;
void run()
{
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (auto &it : coins)
    cin >> it;

  // dp[k] =  no. of ways to construct the sum of x
  // dp[k] = (dp[k-ci] + dp[];
  //  Initialising each sum as 0 meaning there are zero ways to get that
  vector<int> dp(x + 1, 0);

  //  Base case
  dp[0] = 1; // we can get 0 by only 1 way

  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i >= coins[j])
        dp[i] = (dp[i] + dp[i - coins[j]]) % M;
    }
  }

  cout << dp[x] << "\n";
}

int main()
{
  run();
}