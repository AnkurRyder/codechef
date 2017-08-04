#include <iostream>

using namespace std;

int main()
{
    int n,x,k=0,j;
    cin>>n;
    int a[n];
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        cin>>x;
        j=0;
        while(s[j+x-1]!='\0')
        {
            cout<<"  "<<j<<endl;
            if(s[j]=='-')
            {
                s[j]='+';
                s[j+1]='+';
                s[j+2]='+';
                k++;
            }
            j++;
        }
        j=0;
        while(s[j]!='\0')
        {
            cout<<s[j];
            if(s[j]!='+')
            {
                a[i]=-1;
                break;
            }
            j++;
        }
        if(s[j]=='\0')
            a[i]=k;
            k=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        if(a[i]!=-1)
            cout<<a[i];
        else
            cout<<"IMPOSIBLE";
        cout<<"\n";
    }
    return 0;
}
