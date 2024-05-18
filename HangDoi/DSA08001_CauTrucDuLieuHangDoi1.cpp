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
	deque<int> dq;
	int n; cin >> n;
	while (n--){
		int x; cin >> x;
		if (x == 1)
			cout << dq.sz << EL;
		else if (x == 2){
			if (dq.empty())
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if (x == 3){
			int m; cin >> m;
			dq.push_back(m);
		}
		else if (x == 4){
			if (!dq.empty())
				dq.pop_front();
		}
		else if (x == 5){
			if (!dq.empty())
				cout << dq.front() << EL;
			else
				cout << "-1\n";
		}
		else if (x == 6){
			if (!dq.empty())
				cout << dq.back() << EL;
			else
				cout << "-1\n";
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
Ban đầu cho một queue rỗng. Bạn cần thực hiện các truy vấn sau:

Trả về kích thước của queue
Kiểm tra xem queue có rỗng không, nếu có in ra “YES”, nếu không in ra “NO”.
Cho một số nguyên và đẩy số nguyên này vào cuối queue.
Loại bỏ phần tử ở đầu queue nếu queue không rỗng, nếu rỗng không cần thực hiện.
Trả về phần tử ở đầu queue, nếu queue rỗng in ra -1.
Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.
Dữ liệu vào

Dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ theo dạng sau.

Dòng đầu tiên chứa số nguyên n - lượng truy vấn (1 ≤ n ≤ 1000)

N dòng tiếp theo, mỗi dòng sẽ ghi loại truy vấn như trên, với truy vấn loại 3 sẽ có thêm một số nguyên, không quá 106.

Kết quả: In ra kết quả của các truy vấn..

Ví dụ:

Input

1
14
3 1
3 2
3 3
5
6
4
4
4
4
4
3 5
3 6
5	
1

Output	
1
3
5
2
*/
