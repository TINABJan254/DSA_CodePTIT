#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, m;
vi adj[100005];
bool visited[100005];
int disc[100005], low[100005];
int Timer;
int maxE;
stack<int> st;

void Init(){
    memset(visited, false, sizeof(visited));
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    Timer = 0;
    maxE = -1;
}

void DFS(int u){
    disc[u] = low[u] = ++Timer;
    visited[u] = true;
    st.push(u);
    for (int v : adj[u]){
        if (!visited[v]){
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], disc[v]);
        }
    }

    if (disc[u] == low[u]){
        int tmp = 1;
        while (st.top() != u){
            ++tmp;
            st.pop();
        }
        st.pop();
        maxE = max(tmp, maxE);
    }
}

void freeMemory(){
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    Init();

    for (int i = 1; i <= n; i++){
        if (!visited[i])
            DFS(i);
    }

    //result
    cout << maxE << EL;

    freeMemory();
}

int main(){
    faster();
    int TC; cin >> TC;
    while (TC--){
        solve();    
    }
    
    return 0;
}

/*
Trường học X có N sinh viên, trong đó có M cặp là bạn bè của nhau. Bạn của bạn cũng là bạn, tức là nếu A là bạn của B, B là bạn của C thì A và C cũng là bạn bè của nhau.

Các bạn hãy xác định xem số lượng sinh viên nhiều nhất trong một nhóm bạn là bao nhiêu?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).

M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết sinh viên u là bạn của sinh viên v.

Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

INPUT
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 1
1 2
9 10
8 9

OUTPUT
3
7
*/