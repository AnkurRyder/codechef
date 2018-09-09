#include <iostream>

using namespace std;

int main()
{
    int t,n;
    long long temp,last,large=4294967296;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        temp=large/(n+1);
        for(int j=1;j<n;j++)
            cout<<temp<<" ";
        last=(large-temp*(n-1))/2;
        cout<<last+5<<" ";
        cout<<"\n";
    }
    return 0;
}
