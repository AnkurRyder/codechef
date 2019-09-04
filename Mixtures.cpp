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

vector<int> v(105);

int mix(int n)
{
	vector<vector<pair<int , int> > > dp(n+1 , vector<pair<int , int> > (n+1));
	re(i , n)
		dp[i][i] = make_pair(0 , v[i]);
	re(i , n){
		dp[i][i+1].first = dp[i][i].second*dp[i+1][i+1].second;
		dp[i][i+1].second = (dp[i][i].second + dp[i+1][i+1].second)%100;
	}
	rep(i , 2 , n-1)
	{
		rep(j ,0 ,n-i)
		{
			if((dp[j][j+i-1].first + dp[j][j+i-1].second*dp[j+i][j+i].second) == (dp[j+1][j+i].first + dp[j+1][j+i].second*dp[j][j].second))
			{
				if((dp[j][j+i-1].second + dp[j+i][j+i].second)%100 < (dp[j+1][j+i].second + dp[j][j].second)%100)
				{
					dp[j][j+i].first = dp[j][j+i-1].first + (dp[j][j+i-1].second * dp[j+i][j+i].second);
					dp[j][j+i].second = (dp[j][j+i-1].second + dp[j+i][j+i].second)% 100;
				}
				else
				{
					dp[j][j+i].first = dp[j+1][j+i].first + (dp[j+1][j+i].second*dp[j][j].second);
					dp[j][j+i].second = (dp[j+1][j+i].second + dp[j][j].second)% 100;
				}
			}
			else{
				if((dp[j][j+i-1].first + dp[j][j+i-1].second * dp[j+i][j+i].second) < (dp[j+1][j+i].first + dp[j+1][j+i].second*dp[j][j].second)){
					dp[j][j+i].first = dp[j][j+i-1].first + (dp[j][j+i-1].second * dp[j+i][j+i].second);
					dp[j][j+i].second = (dp[j][j+i-1].second + dp[j+i][j+i].second)% 100;
				}
				else
				{
					dp[j][j+i].first = dp[j+1][j+i].first + (dp[j+1][j+i].second*dp[j][j].second);
					dp[j][j+i].second = (dp[j+1][j+i].second + dp[j][j].second)% 100;
				}
			}
		}
	}
	return dp[0][n-1].first;
}

int main()
{
	int n;
	si(n);
	re(i , n)
		cin >> v[i];
	cout << mix(n) << "\n";
	return 0;
}