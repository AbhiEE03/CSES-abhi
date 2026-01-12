/* //// QUESTIONS ////
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4

*/

#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;
// SC = O(n) //
/*
void run(int n)
{
  vector<int> dp(n + 1);
  // dp[i] = No. of ways to get a sum of i

  // base case
  dp[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= 6; j++)
    {
      if (j <= i)
        dp[i] = (dp[i] + dp[i - j]) % M;
    }
  }

  cout << dp[n] << "\n";
}
  */

// SC = O(6) //
void run()
{
  int n;
  cin >> n;
  vector<int> prev = {1};

  for (int i = 1; i <= n; i++)
  {
    // Finding dp[i] or no. of ways to make a sum of i
    // dp[i] = summation of all the previous states
    int curr = 0;
    for (auto j : prev)
      curr = (curr + j) % M;

    prev.push_back(curr);
    //  IF the size of prev becomes >6 then discard the first element
    if (prev.size() > 6)
      prev.erase(prev.begin());
  }

  cout << prev.back() << "\n";
}

int main()
{
  run();
}
