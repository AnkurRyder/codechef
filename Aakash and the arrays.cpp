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
	int n1 , n2 ,n3;
	si(n1); si(n2); si(n3);
	std::vector<int> v1(n1);
	std::vector<int> v2(n2);
	std::vector<int> v3(n3);
	re(i , n1)
		si(v1[i]);
	re(i , n2)
		si(v2[i]);
	re(i , n3)
		si(v3[i]);
	int i = 0 ,j = 0 ,k = 0;
	int minval = max(max(v1[i] , v2[j]), v3[k]) - min(min(v1[i] , v2[j]) , v3[k]);
	while(1)
	{
		if((i == n1-1) && (j == n2-1) && (k == n3-1))
			break;
		if(v1[i] <= v2[j])
		{
			if(v1[i] <= v3[k] && (i != n1-1))
				i++;
			else{
				if(k != n3-1)
					k++;
				else
					j++;
			}
		}
		else
		{
			if(v2[j] <= v3[k] && (j != n2-1))
				j++;
			else{
				if(k != n3-1)
					k++;
				else
					i++;
			}
		}
		if(minval > max(max(v1[i] , v2[j]), v3[k]) - min(min(v1[i] , v2[j]) , v3[k]))
			minval = max(max(v1[i] , v2[j]), v3[k]) - min(min(v1[i] , v2[j]) , v3[k]);
	}
	cout << minval;
	return 0;
}