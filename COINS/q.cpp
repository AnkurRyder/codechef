#include<bits/stdc++.h>

using namespace std;

vector<long long int> dp(1000000001);

long long int helper(int n)
{
    if(n < 12)
        return n;
    if(dp[n] != 0)
        return dp[n];
    return dp[n] = helper(n/2) + helper(n/3) + helper(n/4);
}

int main()
{
    int n;
    while(cin >> n)
        cout << helper(n) <<"\n";
    return 0;
}