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

ll count_sub(vector<vector<ll> >& dp , int a , int b)
{
	vector<bool> v(26);
	if(b < a)
		return 1;
	if(dp[a][b] != 0)
		return dp[a][b];
	rep(i , a , b)
	{
		if(!v[s[i]-65]){
			v[s[i]-65] = 1;
			dp[a][b] += count_sub(dp , i+1 , b);
		}
	}
	dp[a][b]++;
	return dp[a][b];
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	si(t);
	while(t--)
	{
		cin >> s;
		vector<vector<ll> > dp(10005 , vector<ll>(10005));
		cout << count_sub(dp , 0 , s.length()-1) << "\n";
	}
	return 0;
}