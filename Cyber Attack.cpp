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
vector<pair<ll , pair<int,int> > > v;
vector<ll> incl; 
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
		cycl[bh] = a;
		t = 1;
	}
	return t;
}

bool comp(pair<ll , pair<int , int> > a , pair<ll , pair<int , int> > b)
{
	if(a.first >= b.first)
		return 1;
	return 0;
}

void spetree()
{
	sort(v.begin(), v.end() , comp);
	std::vector<int> cycl(n ,-1);
	std::vector<bool> visi(n);
	for(auto node : v)
	{
		if(checkcycl(cycl ,node.second.first ,node.second.second))
		{
			visi[node.second.first]  = 1;
			visi[node.second.second] = 1;
		}
		else
		{
			incl.push_back(node.first);
		}
	}
}

int main()
{
	ll m , a , b , w , s;
	si(n); si(m); sl(s);
	re(i , m)
	{
		si(a); si(b); sl(w);
		v.push_back(make_pair(w , make_pair(a-1, b-1)));
	}
	spetree();
	ll cap = 0;
	ll ans = 0;
	ren(i , incl.size()-1 , 0)
	{
		if(cap + incl[i] <= s){
			ans++;
			cap = cap + incl[i];
		}
		else
			break;
	}
	cout << ans <<" " << cap <<"\n";
	return 0;
}
