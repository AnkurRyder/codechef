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
#define MOD 1000000007

std::vector<int> S(10009);

int count(int m, int n )
{
    int i, j, x, y;
    ll table[n+1][m];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries in bottom 
    // up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = (x + y)%MOD;
        }
    }
    return table[n][m-1]%MOD;
}


int main()
{
	int t;
	cin >> (t);
	int n , m ;
	while(t--)
	{
		cin >> (n);
		re(i , n){
			cin >> S[i];
		}
		cin >> (m);
		cout << count(n , m) << "\n";
	}
	return 0;
}