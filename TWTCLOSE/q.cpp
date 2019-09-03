#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main()
{
    int n , k;
    cin >> n >> k;
    string s;
    set<int> st;
    int t;
    while(k--)
    {
        cin >> s;
        //cout << s <<"\n";
        if(s[2] == 'I'){
            cin >> t;
            // t = stoi(s.substr(6));
            if(st.find(t) == st.end())
            {
                //cout << t;
                st.insert(t);
            }
            else
            {
                st.erase(t);
            }
        }
        else
        {
            st.clear();
        }
        cout << st.size() <<"\n";
    }
}