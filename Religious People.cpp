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
	int t , n , m, a ,b , u ,v;
	si(t);
	ll total = 0;
	while(t--)
	{
		si(n); si(m); si(a); si(b);
		vector<vector<int> > vi(n);
		re(i , m)
		{
			si(u); si(v);
			vi[u-1].push_back(v-1);
			vi[v-1].push_back(u-1);
		}
		if(a <= b)
		{
			pl(n*a);
			continue;
		}
		total = 0;
		vector<bool> visi(n);
		vector<ll> dist(n , INT_MAX);
		queue<int> q;
		int temp;
		re(i , n)
		{
			if(!visi[i])
			{
				q.push(i);
				total += a;
				dist[i] = 0;
				visi[i] = 1;
			}
			else
				continue;
			while(!q.empty())
			{
				temp = q.front();
				q.pop();
				for(int node : vi[temp])
				{
					if(!visi[node]){
						q.push(node);
						if(dist[node] > b)
							dist[node] = b;
						visi[node] = 1;
					}
				}
			}
		}
		ll ans = 0;
		re(i , n){
			ans += dist[i];
		}
		ans += total;
		pl(ans); 
	}
	return 0;
}