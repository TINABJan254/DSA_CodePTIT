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
	int Q; cin >> Q;
	deque<int> dq;
	while (Q--){
		string s; cin >> s;
		if (s == "PUSHBACK"){
			int x; cin >> x;
			dq.push_back(x);
		}
		else if (s == "PUSHFRONT"){
			int x; cin >> x;
			dq.push_front(x);
		}
		else if (s == "PRINTFRONT"){
			if (!dq.empty())
				cout << dq.front() << EL;
			else
				cout << "NONE\n";
		}
		else if (s == "PRINTBACK"){
			if (!dq.empty())
				cout << dq.back() << EL;
			else
				cout << "NONE\n";
		}
		else if (s == "POPBACK"){
			if (!dq.empty())
				dq.pop_back();
		}
		else if (s == "POPFRONT"){
			if (!dq.empty())
				dq.pop_front();
		}
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:

“PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue (0 ≤ x ≤ 1000).

“PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”.

“POPFRONT”: Xóa phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả.

“PUSHBACK x”: Thêm phần tử x vào cuối của dequeue (0 ≤ x ≤ 1000).

“PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”.

“POPBACK”: Xóa phần tử cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.

Dữ liệu vào:

Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).

Mỗi truy vấn có dạng như trên.

Kết quả: 

Với mỗi truy vấn “PRINTFRONT” và “PRINTBACK”, hãy in ra kết quả trên một dòng.

Ví dụ:

Input
10
PUSHBACK 1
PUSHFRONT 2
PUSHBACK 3
PRINTFRONT
POPFRONT
PRINTFRONT
POPFRONT
PRINTBACK
POPFRONT
PRINTBACK

 
Output
2
1
3
NONE
*/
