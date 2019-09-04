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

std::vector<int> memo(100005 , 1);

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	si(n);
	std::vector<int> v(n);
	re(i , n)
		si(v[i]);
	int temp = 0;
	re(i , n)
	{
		re(j , i)
		{
			if(v[j] < v[i])
			{
				temp = memo[j] + 1;
			}
			memo[i] = max(memo[i] , temp);
		}
	}
	cout << *max_element(memo.begin() , memo.begin()+n);
	return 0;
}