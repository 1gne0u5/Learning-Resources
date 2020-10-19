#include <iostream>
#include <string>
#define ll long long int


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if (n==1){
        cout<<"1"<<endl;
    }
    else if (n<=3){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        for (int i = 2; i<n+1; i+=2){
            cout<<i<<" ";
        }
        for (int i = 1; i<n+1; i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    

}