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

vector<ll> v(100005);

ll build(int n)
{
	vector<ll> dp(n+1);
	dp[1] = max(dp[0] , v[1]);
	rep(i ,2, n)
	{
		dp[i] = max(dp[i-1] , i*v[i] + dp[i-2]);
	}
	return dp[n];
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n , temp  , max  = 0;
	si(n);
	re(i , n){
		si(temp);
		v[temp]++;
		if(max < temp)
			max = temp;
	}
	cout << build(max) << "\n";	
	return 0;
}