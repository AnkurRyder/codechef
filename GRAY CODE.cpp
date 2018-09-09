#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	std::vector<ll> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	ll a = 0;
	if(n <= 130)
	{
		for(int i = 0 ; i <n ; i ++)
		{
			for(int j = i+1 ; j < n ; j++)
			{
				for(int k = j +1 ; k < n ; k++)
				{
					for(int l = k+1 ; l < n ; l++){
						a = (v[i]^v[j]^v[k]^v[l]);
						if(a == 0)
						{
							cout << "Yes";
							return 0;
						}
					}
				}
			}
		}
		cout << "No";
	}
	else
		cout << "Yes";
	return 0;
}