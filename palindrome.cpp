#include <iostream>



using namespace std;

int l;

int check(string , int);

int main()

{

    cout<<"Enter the string.\n";

    string s;

    cin>>s;

    l=s.size()-1;

    cout<<check(s,0);

        return 0;

}



int check(string s,int i)

{

    if(i==l/2)

    {

        if(s[i]==s[l-i])

            return(1);

        else

            return(0);

    }

    else{

    if(check(s,i+1))

    {

        if(s[i]==s[l-i])

            return(1);

        else

            return(0);

    }

    }

    return(0);

}
