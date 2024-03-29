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
	priority_queue<int>;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		pq.push(x);
	}	

	int res = 0;
	while (pq.size() > 1){
		int First  = pq.top(); pq.pop();
		int Second = pq.top(); pq.pop();
		res += First + Second;
		res %= MOD;
		pq.push(First + Second); //note: ko để % MOD trong phép push
	}
	cout << res << EL;
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
Chú ý ở bài này không để % MOD trong phép push(First + Second);
Vì ví dụ sau:
ta coi MOD = 100;
pq = [60 50 40 30]
khi ta lấy 2 cái lớn nhất cộng là đc: 110, nếu ta push ((First + Second) % MOD)
thì kết qua bị sai ngay vì lúc này pq trở thành
		pq[10, 40, 30] => ta sẽ chọn 30 và 40, nhưng đáng lẽ ra phải là 110 +  40
cho nên cần note ko để % MOD và phép push đổi với bài này;

Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. 
Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây 
là lớn nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài 
hai sợi dây A[i] và A[j].

Dữ liệu vào

Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. 
Dòng đầu tiên là số nguyên N (N ≤ 2*106).

Dòng tiếp theo gồm N số nguyên dương c[i] ( 1 ≤ A[i] ≤ 109).

Kết quả 

In ra đáp án của bộ test trên từng dòng, theo modulo 109+7.

Ví dụ:

Input:
1
7
2 4 1 2 10 2 3

Output
59
*/