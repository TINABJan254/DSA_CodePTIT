#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define pb push_back
#define sz size()
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>

int mod=1e9+7;
int n,m,s,t;
vector<int> ke[1005];
int used[1005];
int parent[1005];
void nhap(){
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
        //adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
}

void bfs(int u){
    used[u]=1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int v:ke[x]){
            if(!used[v]){
                parent[v]=x;
                used[v]=1;
                q.push(v);
            }
        }
    }
}
int main(){
	freopen("inputf.txt", "r", stdin);
    faster();
    int tc;
    cin>>tc;
    while(tc--){
        for(int i=1;i<=n;i++){
            ke[i].clear();
        }
        memset(used,0,sizeof(used));
        
        nhap();
        bfs(s);
        if(!used[t]){
            cout<<-1<<endl;
        }
        else{
            vector<int> res;
            while(t!=s){
                res.push_back(t);
                t=parent[t];
            }
            res.push_back(t);
            reverse(res.begin(),res.end());
            for(int x:res){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
}
