#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int W, int n, int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    vector<int> dp(W+1);
 
    int ans = 0;
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
 
    return dp[W];
}
 
int main()
{
    int W  , n;
    cin >> n >> W;
    int val[n];
    int wt[n];
    for(int i = 0 ; i < n; i++)
        cin >> wt[i];
    for(int i = 0 ; i < n; i++)
        cin >> val[i];
 
    cout << unboundedKnapsack(W, n, val, wt);
 
    return 0;
}