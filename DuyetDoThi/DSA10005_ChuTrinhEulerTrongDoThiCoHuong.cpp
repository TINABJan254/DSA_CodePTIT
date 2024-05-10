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
	int n, m; cin >> n >> m;
	int degc[1005] = {0}, degt[1005] = {0};
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		degc[x]++;
		degt[y]++;
	}
	
	int cnt = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++){
		cnt += (abs(degc[i] - degt[i]) == 1);
		if (cnt > 2 || abs(degc[i] - degt[i]) > 1 || !degc[i] || !degt[i]){
			flag = true;
			break;
		}
	}
	
	if (!flag)
		cout << "1\n";
	else
		cout << "0\n";
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
Đồ thị có hướng có:
	Chu trình Euler nếu liền thông yếu và tồn tại đúng 2 đỉnh có deg+ - deg- = 1 
Cho đồ thị có hướng liên thông yếu G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
Hãy kiểm tra xem đồ thị có chu trình Euler hay không?

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| 
tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh 
của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra 1, 0 kết quả mỗi test theo từng dòng tương ứng với đồ thị có chu trình Euler và 
trường hợp không tồn tại đáp án.

Ví dụ:
Input:
2
6  10  
1 2 2 4 2 5 3 1 3 2 4 3 4 5 5 3 5 6 6 4
3 3
1 2 2 3 1 3

Output:
1
0
*/
