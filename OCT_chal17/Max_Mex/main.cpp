#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int t,k,n,temp;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        bool *a;
        a=(bool*)calloc(200000,sizeof(bool));
        for(int j=0;j<n;j++)
        {
            cin>>temp;
            a[temp]=1;
        }
        int j=0;
        if(k==0)
        {
            while(a[j]!=0)
            {
                j++;
            }
            cout<<j<<"\n";
        }
        else
        {
            k++;
            while(k>0)
            {
                if(a[j]==0)
                {
                    k--;
                }
                j++;
            }
            cout<<--j<<"\n";
        }
        free(a);
    }
    return 0;
}
