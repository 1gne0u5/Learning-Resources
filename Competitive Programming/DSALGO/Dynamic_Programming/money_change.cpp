//n is amount should be paid, m is diffferent type of coins available
//assume there are infinite no of coins availble in each type
//find minimum no of coins to pay the amount n.
#include<bits/stdc++.h>
using namespace std;
int main() {
  long long n,m,i,j;
  cin>>n>>m;
  long long a[n+1],c[m],d;
  for(i=0;i<m;i++)
  cin>>c[i];
  for(i=0;i<=n;i++)
    a[i]=INT_MAX;
  a[0]=0;
  for(i=1;i<=n;i++) {
    for(j=0;j<m;j++) {
      if(c[j]<=i) {
        d=a[i-c[j]];
        if(d!=INT_MAX && d+1<a[i])
          a[i]=d+1;
      }
    }
  }
  cout<<a[n];
}