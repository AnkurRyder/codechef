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

int dif(vector<int> &v)
{
	int min = INT_MAX;
	int n = v.size()  , m =0 , k;
	re(i , n)
		m += v[i];
	vector<vector<int> > dp(n+1 , vector<int> (m/2+1));
	re(i , n)
		dp[i+1][v[i]]++;
	rep(i, 1, n)
	{
		rep(j,1 , m/2)
		{
			if(dp[i-1][j]){
				dp[i][j]++;
			if(min > abs(m-2*j))
				min = abs(m-2*j);
			}
			if(j-v[i-1] >= 0)
				if(dp[i-1][j-v[i-1]]){
					dp[i][j]++;
				if(min > abs(m-2*j))
					min = abs(m-2*j);
				}
		}
	}
	return min;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t , n;
	si(t);
	while(t--)
	{
		si(n);
		std::vector<int> v(n);
		re(i , n)
			cin >> v[i];
		cout << dif(v) <<"\n";
	}
	return 0;
}
