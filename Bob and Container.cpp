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
	int n;
	ll max = 0;
	si(n);
	std::vector<int> v(n);	
	re(i ,n)
		si(v[i]);
	re(i ,n)
	{
		if(max >= (n-1 - i)*v[i])
			continue;
		ren(j ,n-1, i+1)
		{
			if(max < (j-i)*min(v[i] , v[j]))
				max = (j-i)*min(v[i] , v[j]);
			if(v[i] <= v[j])
				break;
		}
	}
	pl(max);
	return 0;
}