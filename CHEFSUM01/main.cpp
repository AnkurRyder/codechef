#include <iostream>
#include <vector>

 using namespace std;

int Find(vector<unsigned int> a)

int main()
{
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		vector <unsigned int> a(n);
		for(int j=0;j<n;j++)
			cin>>a[j];
		Find(a);
	}
	return 0;
}
 
int Find(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}
