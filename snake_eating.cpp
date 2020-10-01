#include<iostream>
#include<math.h>
#include<algorithm>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,nq;
        cin>>n>>nq;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);

        for(ll k=0;k<nq;k++)
        {
            ll c=0,q;
            ll i=0,j=n-1;
            cin>>q;
            while(i+1!=j || i!=j)
            {
                if(a[j]<q)
                {
                    if(a[j]+1>=q)
                    {
                        c++;
                    }
                    i++;
                    j--;
                }
                else
                {
                    c++;
                    j--;
                }
            }
            cout<<c<<'\n';
        }
    }
    return 0;

}
