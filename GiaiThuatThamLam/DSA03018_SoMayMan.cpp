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
	int sum; cin >> sum;
	int d4 = -1, d7 = -1;
	for (d7 = sum/7; d7 >= 0; d7--){
		if ( (sum - d7*7) % 4 == 0){
			d4 = (sum - d7*7) / 4;
			break;
		}
	}
	
	if (d4 != -1){
		for (int i = 0; i < d4; i++)
			cout << 4;
		for (int i = 0; i < d7; i++)
			cout << 7;
		cout << EL;
	}
	else {
		cout << "-1\n";
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
Muốn là số bé nhất thì nó phải ngắn nhất, đồng thời các số 7 ít nhất
và nằm ở cuối

PROB:
Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu biểu diễn 
thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. 
Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. 
Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. 
Hãy giúp anh ấy

Dữ liệu vào: Dòng đầu ghi số bộ test, mỗi bộ test có một dòng chứa số 
nguyên n (1 < 10^6) — tổng các chữ số của số may mắn cần tìm.

Kết quả: In ra trên 1 dòng số may mắn bé nhất, mà tổng các chữ số bằng n. 
Nếu không tồn tại số thỏa mãn, in ra -1.

Ví dụ:

Input
2
11
10

Output
47
-1
*/