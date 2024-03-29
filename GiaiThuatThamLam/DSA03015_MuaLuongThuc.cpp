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
	int n, s, m;
	cin >> n >> s >> m;
	int total_days = s - s/7; //so ngay toi da co the di mua luong thuc
	int require_food = m * s; //so luong thuc toi thieu can de toi tai
	if (total_days * n < require_food){
		cout << "-1\n";
		return;
	}
	//brute force tim x
	for (int i = 0; i <= total_days; i++){
		if (i * n >= require_food){
			cout << i << EL;
			return;
		}
	}
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
Số ngày phải sử dụng lương thực là s
=> Số ngày tối đa được đi mua lương thực là s - s/7 * 1
	(vì chủ nhật ko được đi mua, một tuần thì có 1 chủ nhật 
		=> số ngày cần chủ nhật chính là 1 * số tuần )
Số lương thực tối thiểu phải có để tồn tại trong s ngày là: m * s;

Gọi số ngày ít nhất cần đi mua lương thực là x
	=> x * n >= m * s

PROB:
Giả sử bạn là một người nghèo trong địa phương của bạn. 
Địa phương của bạn có duy nhất một cửa hàng bán lương thực. 
Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. 
Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:
	N : số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày.
	S : số lượng ngày bạn cần được sử dụng lương thực để tồn tại.
	M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.
Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại trong S ngày tới. 
Hãy cho biết số lượng ngày ít nhất bạn cần phải mua lương thực từ của hàng để 
tồn tại hoặc bạn sẽ bị chết đói trong S ngày tới.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ 3 số N, S, M được viết trên một dòng.
T, N, S, M thỏa mãn ràng buộc: 1≤T≤100;  1≤N, S, M ≤30.
Output:

Đưa ra số ngày ít nhất bạn có thể mua lương thực để tồn tại hoặc đưa ra -1 nếu bạn bị chết đói.
Ví dụ:

 
Input
2
16 10 2
20 10 30

Output
2
-1


*/