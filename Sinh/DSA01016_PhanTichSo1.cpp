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
int x[1005];
bool final;
int cnt; // so luong phan tu cua x

void Init(){
	cin >> n;
	x[1] = n;
	cnt = 1;
	final = false;
}

void display(){
	cout << "(";
	for (int i = 1; i < cnt; i++)
		cout << x[i] << " ";
	cout << x[cnt] << ") ";
}

void genNext(){
	int i = cnt; 
	while (i >= 1 && x[i] == 1){ //di tim phan tu dau tien khac 1 de giam
		--i;
	}

	if (i == 0){
		final = true;
	}
	else{
		x[i]--; // giam phan tu tim duoc 1 dvi
		int d = cnt - i + 1; //luong dvi con thieu
		cnt = i; //cap nhat lai so luong phan tu hien tai
		//bieu dien phan con thieu thong qua x[i]
		int q = d / x[i];  //phan nguyen
		int r = d % x[i]; //phan du
		for (int j = 1; j <= q; j++){
			cnt++;
			x[cnt] = x[i];
		}
		if (r){
			++cnt;
			x[cnt] = r; 
		}
	}
}

void solve(){
	Init();
	while (!final){
		display();
		genNext();
	}
	cout << EL;
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
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. Phép hoán vị vủa một cách được xem là giống nhau. Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, n thỏa mãn ràng buộc: 1≤T, N≤10.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input

2
4
5

Output

(4) (3 1) (2 2) (2 1 1) (1 1 1 1)
(5) (4 1)  (3 2)  (3 1 1) (2 2 1)  (2 1 1 1)  (1 1 1 1 1)
*/