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
	int t , n , m;
	si(t);
	string c;
	int co , we;
	while(t--)
	{
		c = "";
		co = 0; we = 0;
		si(n); si(m);
		re(i , m)
			c += "1";
		std::vector<pair<bool , string> > v(n);
		vector<string> a(2);
		re(i , n)
		{
			cin >> a[0];
			cin >> a[1];
			if(a[0][0] == 'w')
				v[i] = make_pair(0 , a[1]);
			else
				v[i] = make_pair(1 , a[1]);
		}
		re(i ,n)
		{
			if(v[i].first)
			{
				if(c.compare(v[i].second) != 0){
					co = 1;
				}
			}
			else
			{
				if(c.compare(v[i].second) == 0 ){
					we = 1;
				}
			}
		}
		if(co){
			cout << "INVALID" <<"\n";
		}
		else{
			if(we)
				cout << "WEAK" <<"\n";
			else
				cout << "FINE" <<"\n";
		}
	}
	return 0;
}