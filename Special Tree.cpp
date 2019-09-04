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
vector<pair<int , pair<int,int> > > v;
int n;
bool checkcycl(vector<int>& cycl , int a , int b)
{
	bool t = 0;
	if(cycl[a] == -1 && cycl[b] == -1)
	{
		t = 1;
		cycl[a] = a;
		cycl[b] = a;
		return t;
	}
	if(cycl[a] == -1 || cycl[b] == -1)
	{
		t = 1;
		if(cycl[a] == -1)
			cycl[a] = b;
		else
			cycl[b] = a;
		return t;
	}
	int ah = a,bh = b;
	while(ah != cycl[ah])
		ah = cycl[ah];
	while(bh != cycl[bh])
		bh = cycl[bh];
	if(ah == bh)
		t = 0;
	else
	{
		cycl[bh] = ah;
		t = 1;
	}
	return t;
}

int spetree()
{
	int key = 0;
	sort(v.begin(), v.end());
	std::vector<int> cycl(n ,-1);
	std::vector<bool> visi(n);
	int weight = 0;
	for(auto node : v)
	{
		if(checkcycl(cycl ,node.second.first ,node.second.second))
		{
			key++;
			visi[node.second.first]  = 1;
			visi[node.second.second] = 1;
			weight += node.first;
		}
		if(key == n-1)
			break;
	}
	return weight;
}

int main()
{
	int m , a , b , w;
	si(n); si(m);
	re(i , m)
	{
		si(a); si(b); si(w);
		v.push_back(make_pair(w , make_pair(a-1, b-1)));
	}
	cout << spetree() << "\n";
	return 0;
}