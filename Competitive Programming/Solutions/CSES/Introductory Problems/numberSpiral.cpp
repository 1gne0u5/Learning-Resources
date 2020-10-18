#include <iostream>
 
using namespace std;
 
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int x,y,mini,maxi,ans;
        cin>>y>>x;
        mini=min(x,y);
        maxi=max(x,y);
        if(maxi%2==0)
        {
            if(mini==x)
                ans=maxi*maxi-mini+1;
            else
                ans=(maxi-1)*(maxi-1)+mini;
        }
        else
        {
             if(mini==x)
                ans=(maxi-1)*(maxi-1)+mini;
             else
              ans=maxi*maxi-mini+1;
        }
         cout<<ans<<endl;
    }
    return 0;
}
