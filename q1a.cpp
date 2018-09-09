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



int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t ,n;
	si(t);
	int min;
	while(t--)
	{
		min = INT_MAX;
		si(n);
		vector<int> v(n);
		re(i ,n)
			si(v[i]);
		sort(v.begin() , v.end());
		re(i , n-1)
		{
			if(min > abs(v[i] - v[i+1]))
				min = abs(v[i] - v[i+1]);
		}
		cout << min << "\n";
	}
	return 0;
}