#include <iostream>

using namespace std;

int main()
{
    int n,easy=0,hard=0,key=1;
    long long t,l,te,th,temp=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l>>t;
        te=t/2;
        th=t/10;
        easy=0;
        hard=0;
        for(int j=0;j<l;j++)
        {
            cin>>temp;
            if(temp>=te)
            {
                easy++;
            }
            else{
                if(temp<=th)
                {
                    hard++;
                }
            }
            if(easy>1||hard>2)
            {
                key=0;
            }
        }
        if(key==1)
        {
            if(easy<1||hard<2)
                cout<<"no"<<"\n";
            else
                cout<<"yes"<<"\n";
        }
        else
            cout<<"no"<<"\n";
        key=1;
    }
    return 0;
}
