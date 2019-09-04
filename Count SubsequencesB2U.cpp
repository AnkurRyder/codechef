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

string s;

ll count_sub(int n)
{
	vector<vector<ll> > dp(n+1 , vector<ll>(n, 1));
	vector<bool> v(26);
	re(i , n)
	{
		ren(j ,n-i-1 , 0)
		{
			rep(k , j, j+i)
			{
				if(!v[s[k]-65]){
					v[s[k] - 65] = 1;
					dp[j][j+i] += dp[k+1][j+i];
				}
			}
			re(l , 26)
				v[l] = 0;
			//dp[j][j+i]++;
		}
	}
	return dp[0][n-1];
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		cin >> s;
		cout << count_sub(s.length()) << "\n";
	}
	return 0;
}