#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define pb push_back
#define sz size()
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>

int mod=1e9+7;
int main(){
    faster();
    queue<ll> q;
    vll v;
    q.push(1);
    while(!q.empty()){
    	ll u=q.front();
    	q.pop();
    	v.pb(u);
    	if(u<=1e19){
    		q.push(10*u);
		    q.push(10*u+1);
		}
	}
	int t;
	cin>>t;
	while(t--){
		int cnt=0;
		int n;
		cin>>n;
		for(ll x:v){
			if(x<=n){
				++cnt;
			}
			else{
				break;
			}
		}
		cout<<cnt<<endl;
	}
}
