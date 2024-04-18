#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define pb push_back
#define sz size()
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>

int mod=1e9+7;
int n,S,a[1000],X[1000],res=-1e9;
int w[1000];
int v[1000];
// void xuly(){
//  int totalWeight=0;
//  int totalValue=0;
//  for(int i=1;i<=n;i++){
//      if(X[i]){
//          totalWeight+=w[i];
//          totalValue+=v[i];
//      }
//  }
//  if(totalWeight<=S){
//      res=max(res,totalValue);
//  }

// }
// void ql(int i){
//  for(int j=0;j<=1;j++){// chi co the nhan gia tri la 0 va 1
//      X[i]=j;
//      if(i==n){
//          xuly();
//      }
//      else {
//          ql(i+1);
//      }
//  }
// }
void ql(int i,int totalWeight,int totalValue){
    if(totalWeight>S){
        return ;
    }
    for(int j=0;j<=1;j++){
        X[i]=j;
        if(i==n){
          if(X[i]==1){
            if(totalWeight+w[i]<=S){
                res=max(res,totalValue+v[i]);
            }
          }
          else{
            if(totalWeight<=S){
                res=max(res,totalValue);
            }
          }
        }
        else {
            if(X[i]==1){
                ql(i+1,totalWeight+w[i],totalValue+v[i]);
            }
            else {
                ql(i+1,totalWeight,totalValue);
            }
        }
    }
}
int main(){
    faster();
    cin>>n>>S;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    ql(1,0,0);
    cout<<res;


} 