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

vector <string> v(100000);
int j =0;

bool comp(string s1 , string s2)
{
	if(s1 > s2)
		return 0;
	else
		return 1;
}

void sub(string s , int st , int i , string temp)
{
	if(i == s.length()-1)
	{
		v[j++] = temp;
		temp += s[i];
		v[j++] = temp;
		return;
	}
		sub(s , st , i+1 , temp);
		temp += s[i];
		sub(s , st , i+1 , temp);
}

int main()
{
	int n;
	string s;
	string temp = "";
	si(n);
	re(i , n)
	{
		cin >>s;
		sub(s , 0 , 0 , temp);
		sort(v.begin() , v.begin()+j , comp);
		re(k , j)
			cout << v[k] <<"\n";
		j = 0;
	}
	return 0;
}