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
	int n , m , x , y,ans = 0;
	si(n);
	si(m);
	si(x);
	si(y);
	n = n - m/x;
	ans = ans + m/x;
	m = m%x;
	int start  , end , mid = 0;
	if(n > 1)
	{
		start = 0;
		end = n+2;
		mid = (start+end)/2;
		while(start <= mid && mid <= end)
		{
			if((mid*x - (m + (n-mid)*y)) > 0)
			{
				end = mid-1;
				mid = (start + end)/2;
			}
			else
			{
				start = mid+1;
				mid = (start+end)/2;
			}
		}
	}
	pi(ans+mid);
	return 0;
}