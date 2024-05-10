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

int parent[200005];
int degree[200005];
int inc[200005];
ll val[200005];
int n;

void Init(){
	cin >> n;
	for (int i = 2; i <= n; i++){
		int x; cin >> x;
		degree[x]++;
		parent[i] = x;
	}
	
	parent[1] = 0;
	fill(val, val + n + 1, 1);
	fill(inc, inc + n + 1, 1);
	for (int i = 1; i <= n; i++){
		if (degree[i] == 0){
			val[i] = 1; //leaf
		}
	}
}

void calc(){
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (degree[i] == 0)
			q.push(i);
	
	while (!q.empty()){
		int u = q.front(); q.pop();
		val[parent[u]] += (val[u] + inc[u]);
		inc[parent[u]] += inc[u];
		--degree[parent[u]];
		if (degree[parent[u]] == 0)
			q.push(parent[u]);
	}
}

void solve(){
	Init();
	calc();
	for (int i = 1; i <= n; i++)
		cout << val[i] << ' ';
}

int main(){
	faster();
	solve();
	return 0;
}
/*
Ta sẽ dùng thuật toán Kahn, xóa dần đỉnh tức là đi tổng hợp từ từng nút là về
nhưng chú ý ở đây là giá trị dinh dưỡng của mỗi nút là khi truyền ni sang một nút khác sẽ được tăng lên 1
sau đó tiếp tục truyền đi lại được tăng lên 1 
	vd: nút là 4 có giá trị 1 -> truyền đến nút 3 sẽ có giá trị 2
	tiếp tục nó -> truyền đến nút 2 sẽ có giá trị 3 tiếp tục -> truyền đến nút 1 sẽ có giá trị 4
	đó là riêng nút lá 4 truyền đến 1 là nút 1 đã có giá trị 4 rồi, còn các nút khác nữa.

Cho một cây có N đỉnh và gốc tại đỉnh 1. Mỗi nút lá có chức năng tổng hợp chất dinh dưỡng, 
đồng thời lan truyền năng lượng cũng như các chất dinh dưỡng cho nút cha của nó để thực hiện quá trình tổng hợp.

Quá trình lan truyền năng lượng sẽ làm tăng giá trị dinh dưỡng lên 1. 
Tức là nếu một nút tổng hợp được giá trị dinh dưỡng bằng V, 
sẽ giúp cho nút cha của nó sẽ tổng hợp được giá trị dinh dưỡng bằng V+1. 
Nếu một nút cha có nhiều nút con, giá trị dinh dưỡng của nó bằng tổng của giá trị dinh dưỡng của 
các nút con gửi lên.

Biết rằng mỗi nút lá ban đầu tổng hợp được chất dinh dưỡng có giá trị 1. 
Nhiệm vụ của bạn là hãy xác định xem mỗi nút của cây tổng hợp được bao nhiêu giá trị dinh dưỡng?

Input:

Dòng đầu tiên là số lượng đỉnh N (N <= 200 000).

Dòng tiếp theo gồm N-1 số nguyên, a[2], a[3], …, a[N] lần lượt là cha của các nút 2, 3, …, N.

Output: 

In ra N số nguyên, số nguyên thứ i cho biết giá trị dinh dưỡng mà nút i tổng hợp được.

 

Test ví dụ:

Test 1
Input:
3
1 1
Output:
5 1 1

Test 2
Input:
5
1 2 2 4
Output:
13 8 1 3 1
*/