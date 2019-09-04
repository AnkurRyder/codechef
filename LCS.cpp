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

vector<vector <int> > v(1005 ,vector<int> (1005 ,0));



int main()
{
	int n1 , n2 , m;
	si(n1); si(n2); si(m);
	vector<int> v1(n1);
	vector<int> v2(n2);
	re(i ,n1)
		cin >> v1[i];
	re(i ,n2)
		cin >> v2[i];
	rep(i ,1, n1)
	{
		rep(j ,1 , n2)
		{
			if(v1[i-1] == v2[j-1]){
				v[i][j] = v[i-1][j-1] +1;
			}
			else
				v[i][j] = max(v[i-1][j] , v[i][j-1]);
		}
	}
	if(n1 > n2) 
	{
		if(v[n1][n2] + m <= n2)
			cout << v[n1][n2] + m;
		else
			cout << (v[n1][n2] + m - (v[n1][n2] + m)%n2);
	}
	else
	{
		if(v[n1][n2] + m <= n1)
			cout << v[n1][n2] + m;
		else
			cout << (v[n1][n2] + m - (v[n1][n2] + m)%n1);
	}
	return 0;
}