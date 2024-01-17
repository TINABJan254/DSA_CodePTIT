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
vi adj[1005];
bool visited[1005];
int  parent[1005];

bool BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for (int y : adj[x]){
            if (visited[y]){
                if (y != parent[x]){
                	cout << " this-> " <<y << ' ';
                    return true;
                }
            }
            else if (!visited[y]){
                parent[y] = x; 
                q.push(y);
                visited[y] = true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            if (BFS(i)){
                cout << "1";
                return;
            }
        }
    }

    cout << "0";
}

int main(){
    faster();
    solve();
    return 0;
}

/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy xác định xem đồ thị có tồn tại chu trình hay không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

Input Format

Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

Sample Input 0

10 11
10 5
10 4
10 1
10 3
5 2
5 4
10 8
5 3
5 1
10 6
10 9
Sample Output 0

1
*/