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
bool final;
int x[1005];

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		x[i] = 0;
	final = false;
}

bool check(){
	if (x[1] == 0 || x[n] == 1)
		return false;
	for (int i = 1; i < n; i++)
		if (x[i] == 1 && x[i + 1] == 1)
			return false;
	return true;
}

void display(){
	for (int i = 1; i <= n; i++){
		if (x[i] == 0)
			cout << 'A';
		else
			cout << 'H';
	}
	cout << "\n";
}

void genNext(){
	int i = n;
	while (i >= 1 && x[i] == 1){
		x[i] = 0;
		--i;
	}
	if (i == 0){
		final = true;
	}
	else{
		x[i] = 1;
	}
}

void solve(){
	Init();
	while (!final){
		if (check())
			display();
		genNext();
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
Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng khoái. Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.

Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:

Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
Không có hai chữ H nào liền nhau
Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.

Input

Dòng đầu ghi số bộ test T (không quá 10)
Mỗi bộ test ghi độ dài N (2 <= N < 16)
Output

Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, mỗi xâu viết trên một dòng.
Ví dụ

Input
2
2
4
Output
HA
HAAA
HAHA
*/