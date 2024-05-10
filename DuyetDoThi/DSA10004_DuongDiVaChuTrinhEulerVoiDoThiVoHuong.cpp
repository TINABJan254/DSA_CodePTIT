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

void solve(){
	int n, m;
	cin >> n >> m;
	int deg[1005] = {0};
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		deg[x]++;
		deg[y]++;
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (deg[i] % 2 != 0)
			++cnt;
	}
	if (cnt == 0)
		cout << "2\n";
	else if (cnt == 2)
		cout << "1\n";
	else
		cout << "0\n";
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Đồ thị vô hướng có:
	Chu trình euler nếu bậc của tất cả các đỉnh là bậc chẵn
	Đường đi Euler nếu chỉ tồn tại duy nhất 2 đỉnh bậc lẻ

Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
Hãy kiểm tra xem đồ thị có đường đi Euler hay chu trình Euler hay không?


Đường đi Euler bắt đầu tại một đỉnh, và kết thúc tại một đỉnh khác.

Chu trình Euler bắt đầu tại một đỉnh, và kết thúc chu trình tại chính đỉnh đó.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| 
tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh 
của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra 1, 2, 0 kết quả mỗi test theo từng dòng tương ứng với đồ thị có đường đi Euler, chu trình Euler và trường hợp không tồn tại.

Ví dụ:
Input:
2
6  10  
1 2 1 3 2 3 2 4 2 5 3 4 3 5 4 5 4 6 5 6
6 9  
1  2 1  3 2  3 2  4 2  5 3  4 3  5 4  5 4  6

Output:
2
1
*/
