#include <iostream>

using namespace std;

int main()
{
    int t,j,a=0,b=0,x,y,k=0,temp=1,d,key=1,r=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        cin>>x>>y;
        j=0;
        a=0;
        b=0;
        while(j<s.size())
        {
            if(s[j]=='a')
                a++;
            else
                b++;
            j++;
        }
        k=1;
        if((a>x)||(b>y))
        {
            if((a/x)>=(b/y)){
                    if((b/(a/x))==0){
                            j=0;
                        while(j<s.size())
                        {
                                while(k<=x&&a>0)
                                {
                                    cout<<"a";
                                    --a;
                                    k++;
                                    j++;
                                }
                            k=1;
                            if(j>=s.size())
                                break;
                            if(b!=0){
                                    cout<<"b";
                                    --b;
                                    j++;
                            }
                            else
                                cout<<"*";
                }
            }
            else
            {
                j=0;
                key=1;
                if(a%x!=0){
                    key=1;
                }
                else
                {
                    key=0;
                }
                        while(j<s.size())
                        {
                            if(key==1&&a/x>0)
                            {
                                d=b/((a/x)+1);
                            }
                            else{
                            if(a/x>0){
                                d=b/(a/x);
                            }
                            }
                            while(k<=x&&a>0)
                            {
                                cout<<"a";
                                --a;
                                k++;
                                j++;
                            }
                            k=1;
                            temp=1;
                            while(temp<=d&&b>0)
                            {
                                cout<<"b";
                                temp++;
                                b--;
                                j++;
                            }
                        }
            }
        }
        else
        {
                if((a/(b/y))==0){
                        j=0;
                        while(j<s.size())
                        {
                                while(k<=y&&y>0)
                                {
                                    cout<<"b";
                                    --b;
                                    k++;
                                    j++;
                                }
                            k=1;
                            if(j>=s.size())
                                break;
                            if(a!=0){
                                cout<<"a";
                                --a;
                                j++;
                            }
                            else
                                cout<<"*";
                }
            }
            else
            {
                key=1;
                int j=0;
                if(b%y!=0){
                    key=1;
                }
                else{
                    key=0;
                }
                 while(j<s.size())
                        {
                             if(key==1&&b/y>0){
                                d=a/(b/y);
                             }
                             else
                             {
                                 if(b/y>0){
                                d=a/((b/y)-1);
                                 }
                            }
                            while(k<=y&&b>0)
                            {
                                cout<<"b";
                                --b;
                                k++;
                                j++;
                            }
                            k=1;
                            temp=1;
                            while(temp<=d&&a>0)
                            {
                                cout<<"a";
                                temp++;
                                a--;
                                j++;
                            }
                        }
            }
        }
        }
        else
        {
            while(a>0)
            {
                cout<<"a";
                a--;
            }
            while(b>0)
            {
                cout<<"b";
                b--;
            }
        }
        cout<<"\n";
        s.clear();
        k=1;
        temp=1;
    }
    return 0;
}
