#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
    int t,n,nd1,nd2,max1=0,min1,max2=0,min2;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        if(n==2)
        {
            cin>>nd1;
            vector<int> d1(nd1);
            max1=0;
            min1=1000000;
            for(int k=0;k<nd1;k++){
                cin>>d1[k];
                if(max1<d1[k])
                    max1=d1[k];
                if(min1>d1[k])
                    min1=d1[k];
            }
            max2=0;
            min2=1000000;
            cin>>nd2;
            vector<int> d2(nd2);
            for(int k=0;k<nd2;k++){
                cin>>d2[k];
                if(max2<d2[k])
                    max2=d2[k];
                if(min2>d2[k])
                    min2=d2[k];
            }
            if(abs(max1-min2)>abs(min1-max2))
                cout<<abs(max1-min2)<<"\n";
            else
                 cout<<abs(min1-max2)<<"\n";
        }
    }
    return 0;
}
