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

std::vector<string> v(1000000);
int k = 0;

bool comp(string s1 , string s2)
{
	if(s1 < s2)
		return 1;
	else
		return 0;
}

void per(string s ,int ind)
{
	if(ind == s.length()-1)
	{
		v[k] = s;
		k++;
		return ;
	}
	rep(i , ind , s.length()-1){
		swap(s[ind] , s[i]);
		per(s , ind+1);
		swap(s[ind] , s[i]);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	per(s , 0);
	sort(v.begin() , v.begin()+k  , comp);
	cout << v[0] << "\n";
	rep(i , 1 , k)
	{
		if(v[i] != v[i-1])
			cout << v[i] <<"\n";
	}
	return 0;
}