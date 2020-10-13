#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;



#define ll long long int
const ll mod = 1e9 + 7;

ll power(ll x, ll y, ll p)
{
    // (x^y) mod p
    ll res = 1;
    x %= p;
    while (y)
    {
        if (y & 1)
            res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}
ll fact(ll n){
    ll ans=1;
    for(int i=1; i<=n;i++){
        ans*=i;
    }
    return ans;
}

int num = 0;

void ways(string board[], int diag1[], int diag2[], int cols[], int r){
    if (r == 8){
        num++;
        return;
    }

    for (int c=0; c<8; c++){
        
        if (board[r][c]=='.'){
        if (cols[c]==0 && diag1[r+c]==0 && diag2[r-c+8-1]==0){
            
            cols[c]=diag1[r+c]=diag2[r-c+8-1]=1;
            ways(board, diag1, diag2, cols, r+1);
            cols[c]=diag1[r+c]=diag2[r-c+8-1]=0;
        }
    }
     }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string board[8];
    for (int i=0; i<8; i++){
        cin>>board[i];
    }
    int diag1[16], diag2[16];
    for (int i=0; i<16; i++){
        diag1[i]=0;
        diag2[i]=0;
    }
    int cols[8]={0};
    
    ways(board, diag1, diag2, cols, 0);
    cout<<num<<endl;
    
}