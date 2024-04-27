#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define pb push_back
#define sz size()
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>

int mod=1e9+7;
int n,X[1000],a[1000];
int s;
int ok;
void ql(int i,int start,int sum){
  if(ok){
    return;
  }
  for(int j=start;j<=n;j++){
    if(sum+a[j]<=s && ok==0){
        X[i]=a[j];
        sum+=a[j];
        if(sum==s){
            ok=1;
            break;
        }
        else if(sum<=s){
            ql(i+1,j+1,sum);
        }
        sum-=a[j];
    }
    else {
        return ;
    }
  }
}
int main(){
    faster();
    int t;
    cin>>t;
    while(t--){
        ok=0;
        cin>>n;
        s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s+=a[i];
        }
        sort(a+1,a+n+1);
        if(s%2!=0){
          cout<<"NO"<<endl;
        }
        else{
            s/=2;
            ql(1,1,0);
            if(ok){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}