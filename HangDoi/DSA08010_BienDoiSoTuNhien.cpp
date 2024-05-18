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

int BFS(int n){
	queue<pii> q;
	set<int> SE;
	q.push({n, 0});
	SE.insert(n);
	while (!q.empty()){
		int u = q.front().fi;
		int len = q.front().se;
		q.pop();
		if (u == 1)
			return len;
		//n - 1
		if (u > 1 && SE.find(u - 1) == SE.end()){
			q.push({u - 1, len + 1});
			SE.insert(u - 1);
		}
		
		//n = max(u, v)
		for (int i = 2; i <= sqrt(u); i++){
			if (u % i == 0){
				int v1 = i, v2 = u / i;
				int tmp = max(v1, v2);
				if (SE.find(tmp) == SE.end()){
					q.push({tmp, len + 1});
					SE.insert(tmp);
				}	
			}
		}
	}
	return -1;
}

void solve(){
	int n; cin >> n;
	cout << BFS(n) << EL;
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
Note: 
	ở vòng lặp kiểm tra ước ta chỉ cần chạy đến sqrt(n) mà k cần đến n / 2
	Bởi vì trong khoảng từ [sqrt(n), n/2] n ko chia hết cho số nào cả

Cho số tự nhiên N (N<10^9) và hai phép biến đổi (a), (b) dưới đây.

Thao tác (a): Trừ N đi 1 (N=N-1). Ví dụ N=17, thao tác (a) biến đổi N = N-1 =16.
Thao tác (b): N = max(u,v) nếu u*v =N (u>1, v>1). Ví dụ N=16, thao tác (b) có thể biến đổi N = max(2, 8)=8 hoặc N=max(4, 4)=4.
Chỉ được phép sử dụng hai thao tác (a) hoặc (b), hãy biến đổi N thành 1 sao số các thao tác (a), (b) được thực hiện ít nhất. 
Ví dụ với N=17, số các phép (a), (b) nhỏ nhất biến đổi N thành 1 là 4 bước như sau:

	Thao tác (a): N = N-1 = 17-1 = 16
	Thao tác (b): 16 = max(4,4) = 4
	Thao tác (b): 4 = max(2,2) = 2
	Thao tác (a): 2 = 2-1 = 1

Input:
Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số N.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 

Input
3
17
50
100

Output
4
5
5
*/
