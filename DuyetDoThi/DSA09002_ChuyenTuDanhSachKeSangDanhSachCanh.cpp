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

int n;

void solve(){
	cin >> n; 
	cin.ignore();
	for (int i = 1; i <= n; i++){
		string s; 
		getline(cin, s);
		stringstream ss(s);
		string token;
		while (ss >> token){
			if (i < stoi(token))
				cout << i << ' ' << token << "\n";
		}
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho đơn đồ thị G vô hướng liên thông được mô tả bởi danh sách kề. 
Hãy in ra danh sách cạnh tương ứng của G.

Input

Dòng đầu tiên ghi số N là số đỉnh (1<N<50)
N dòng tiếp theo mỗi dòng ghi 1 danh sách kề lần lượt theo thứ tự từ đỉnh 1 đến đỉnh N
Output: Ghi ra lần lượt từng cạnh của đồ thị theo thứ tự tăng dần.

Ví dụ

Input
3
2 3
1 3
1 2

Output
1 2
1 3
2 3
*/