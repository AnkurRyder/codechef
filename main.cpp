#include <iostream>

using namespace std;

int main()
{
    int n,l,d,t=0,z=0,x=0;;
    cin>>n;
    int ans[n];
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        l=s.size();
        while(1)
        {
            x=0;
            for(int j=0;j<l-1;j++)
            {
             if(s[j]=='1'&&s[j+1]=='0')
             {
                 s[j]='0';
                 t++;
                 d=j+1;
                 while(s[d]!='1'&&d<l)
                    d++;
                 s[d-1]='1';
                 z=z+d-1-j;
                 j=d-1;
                 x=1;
             }
            }
            if(x==1)
                continue;
            if(x==0){
                ans[i]=t+z;
                break;
            }
    }
    t=0;
    z=0;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
    return 0;
}
