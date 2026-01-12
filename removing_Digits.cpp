/* // QUESTION //
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 \le n \le 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.
*/
// TC = O(n*7) = O(n) (n can have at max 7 digits)
// SC = O(n)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 + 7;
void run()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1, 1e9);
  // No. of steps to convert i to zero
  // base case
  dp[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    string d = to_string(i);
    for (char &c : d)
    {
      int digit = c - '0';
      if (digit != 0)
        // Transition
        dp[i] = min(dp[i], dp[i - digit] + 1);
    }
  }
  // Final subproblem
  cout << dp[n] << "\n";
}

// Greedy approach
void run_greedy()
{
  int n;
  cin >> n;
  int steps = 0;
  while (n > 0)
  {
    int maxi = 0;
    string num = to_string(n);
    for (char c : num)
    {
      maxi = max(maxi, (c - '0'));
    }
    if (maxi != 0)
    {
      n -= maxi;
      steps++;
    }
  }
  cout << steps << "\n";
}

int main()
{
  run();
  // run_greedy();
}
