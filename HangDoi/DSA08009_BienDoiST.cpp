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

int BFS(int s, int t){
	queue<pii> q;
	q.push({s, 0});
	set<int> SE;
	SE.insert(s);
	while (!q.empty()){
		int u = q.front().fi;
		int len = q.front().se;
		q.pop();
		if (u == t)
			return len;
		if (u > 1 && SE.find(u - 1) == SE.end()){
			q.push({u - 1, len + 1});
			SE.insert(u - 1);
		}
			
		if (u * 2 <= 10000 && SE.find(u * 2) == SE.end()){
			q.push({u * 2, len + 1});
			SE.insert(u * 2);
		}
	}
	return -1;
}

void solve(){
	int s, t; cin >> s >> t;
	cout << BFS(s, t) << EL;
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
Để tránh việc lặp lại các số đã sinh ra trước đó, ta dùng set để làm việc này
Và đồng thời chú ý trường hợp số <= 1, nếu số này trừ đi 1 sẽ thành âm nên ta
cần kiểm tra
Chú ý trường hợp *2 lớn hơn 10000, nên ta chỉ push những số *2 <= 10000 thôi

Cho hai số nguyên dương S và T (S, T<10000) và hai thao tác (a), (b) dưới đây:

Thao tác (a): Trừ S đi 1  (S = S-1) ;

Thao tác (b): Nhân S với 2 ( S = S*2);

Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác (a), (b) là ít nhất. Ví dụ với    S =2, T=5 thì số các bước ít nhất để dịch chuyển S thành T thông qua 4 thao tác sau:

Thao tác (a): 2*2 = 4;

Thao tác (b): 4-1 = 3;

Thao tác (a): 3*2 = 6;

Thao tác (b): 6-1 = 5;

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một bộ đôi S và T.
          Output: Đưa ra kết quả mỗi test theo từng dòng.

         

          Ví dụ:
Input
3
2 5
3 7
7 4

Output
4
4
3
*/
