#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define re(i, n) for(int i = 0; i < n; i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define MOD 1000000007

std::vector<ll> dp(1000005);

int solve(std::vector<int> v , int n)
{
	if(n == 0)
		return 0;
	if(dp[n] != 0)
		return dp[n];
	for(int i = 1 ; i < n ;i++)
		dp[i+1] = (dp[i] + dp[i] - dp[v[i+1]-1] + 2)%MOD;
	return dp[n];
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	si(n);
	std::vector<int> v(n+1);
	rep(i ,1 , n)
		si(v[i]);
	dp[1] = 2;
	cout << solve(v , n);	
	return 0;
}