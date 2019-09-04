#include <bits/stdc++.h>
using namespace std;

string s;

int palin()
{
    int n = s.length();
    int l;
    vector<vector<bool> > p(n , vector<bool> (n));
    vector<int> no(n);
    for(int i = 0 ; i < n ; i++)
        p[i][i] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        for(int j =0 ; j <= n-i ; j++)
        {
            l = j+i-1;
            if(i == 2)
                p[j][l] = (s[j] == s[l]);
            else
                p[j][l] = (p[j+1][l-1])&&(s[j] == s[l]);
        }
    }
    for(int i = 0 ; i < n ;i++)
    {
        if(p[0][i] == 1)
            no[i] = 0;
        else
        {
            no[i] = INT_MAX;
            for(int j = 0 ; j < i ; j++)
            {
                if(p[j+1][i] == true && ((1 + no[j]) < no[i]))
                    no[i] = no[j]+1;
            }
        }
    }
    return no[n-1];
}


int main() {
    int t;
    cin >> t;
    while(t--){
          cin >> s;
          cout << palin();
    }
}
