//use to caluculate minimum no of coins need to pay certain amount n.
//links for similar type of problems
//https://codeforces.com/problemset/problem/1061/A
//https://www.codechef.com/CYOC2018/problems/LNOC
//https://www.hackerrank.com/contests/justcode/challenges/minimum-number-of-coins-for-possible-sum
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
  return 0;
}