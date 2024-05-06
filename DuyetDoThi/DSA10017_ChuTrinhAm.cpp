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

struct edge{
	int src, des, w;
};

int INF = (int)1e9;
int n, m;
vector<edge> edge_list;
int d[100005];

bool check(int s){
	d[s] = 0;
	for (int i = 1; i <= n - 1; i++){
		for (edge e : edge_list){
			int u = e.src, v = e.des, W = e.w;
			if (d[u] < INF){
				d[v] = min(d[v], d[u] + W);
			}
		}
	}
	
	for (edge e : edge_list){
		int u = e.src, v = e.des, W = e.w;
		if (d[u] < INF){
			if (d[v] > (d[u] + W)){
				return true;
			}
		}
	}
	
	return false;
}

bool negativeCycle(){
	fill(d + 1, d + n + 1, INF);
	bool res = false;
	for (int i = 1; i <= n; i++){ //Duyet n lan de tranh co nhieu tplt
		if (d[i] == INF){
			if (check(i)){
				res = true; break;
			}
		}
	}
	
	return res;
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y, z; cin >> x >> y >> z;
		edge_list.pb({x, y, z});
	}
	
	if (negativeCycle())
		cout << "1\n";
	else
		cout << "0\n";
	
	//free memory
	edge_list.clear();
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
Ta dùng bellman-ford, sau khi lặp n-1 lần để cập nhật d[v] rồi nếu như lần lặp thứ n
ta thấy lại tiếp tục cập nhất d[v] thì đồ thị đó tồn tại chu trình âm
Nếu đồ thị có nhiều tplt thì phải check chu trình âm ở tất cả các tplt

Cho đồ thị có trọng số G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số âm
hoặc dương. Hãy viết chương trình xác định xem đồ thị có chu trình âm hay không.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: 
	dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị; 
	|E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh 
	cùng với trọng số canh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra 1 hoặc 0 theo từng dòng của mỗi test tương ứng với đồ thị có hoặc không có chu trình âm.
     Ví dụ:

Input:
2
3  3
1  2 -1
2  3  4
3  1 -2
3  3
1  2 -1
2  3  2
3  1 -2

Output:
0
1
*/
