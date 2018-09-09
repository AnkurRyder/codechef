#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll MOD = 1000000007;
ll p = 1000000006;
vector <bool> posi(10005);
vector <ll> pos(10005);
int n ,k;
ll powered(int a , ll b)
{
    ll res = 1;
    while(b > 0)
    {
        if(b&1)
            res = (res*a)%MOD;
        a = a*a;
        b = b>>1;
    }
    return res;
}

ll Find(ll key , int max , int min)
{
    ll maxi = key , mini = key , p = 1;
    int i = 0 , j = 0 , start = min+1 , end = max;
    while((mini > 0 || maxi > 0) && (max >= start-1) && (min <= end))
    {
        if(mini > 0 && posi[min])
        {
            pos[min] = pos[min] - mini;
            mini = mini*(n - i-k)/(n-1-i);
            i++;
        }
        if(maxi > 0 && posi[max])
        {
            pos[max] = pos[max]- maxi;
            maxi = maxi*(n - j - k)/(n-1-j);
            j++;
        }
        max--;
        min++;
    }
    for(start ; start < end ; start++)
    {
        if(posi[start])
        {
            p = ((p % MOD) * (powered(start , pos[start]) % MOD)) % MOD;
        }
    }
    return p;
}

ll nCrModpDP(int n, int r)
{
    ll C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

ll nCrModpLucas(int n, int r)
{
   // Base case
   if (r==0)
      return 1;

   // Compute last digits of n and r in base p
   int ni = n%p, ri = r%p;
   return (nCrModpLucas(n/p, r/p) * // Last digits of n and r
           nCrModpDP(ni, ri)) % p;  // Remaining digits
}

int main() {
    int t , mini = 10009 , maxi = 0 ,temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        temp = min((k-1) , ((n-1)-(k-1)));
        ll key = nCrModpLucas(n-1 , temp);
        for(int i = 0 ;i < n; i++){
            cin >> temp;
            posi[temp] = 1;
            pos[temp] = key;
            if(mini > temp)
                mini = temp;
            if(maxi < temp)
                maxi = temp;
        }
        cout << Find(key , maxi , mini) << "\n";
        mini = 100009;
        maxi = 0;
    }
    return 0;
}
