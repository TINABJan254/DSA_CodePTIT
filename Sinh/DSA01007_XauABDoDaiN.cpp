#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n;
int x[1005];
bool final;

void Init();
void display();
void genNext();
void solve();

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		x[i] = 0;
	final = false;
}

void display(){
	for (int i = 1; i <= n; i++){
		if (x[i] == 0)
			cout << "A";
		else
			cout << "B";
	}
	cout << " ";
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
Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc là ký tự ‘B’. Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6. Nhiệm vụ của bạn là hãy liệt kê tất cả các xâu AB có độ dài n.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.
T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤n≤10.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Mỗi xâu cách nhau 1 khoảng trống.
Input
2
2
3

Output
AA AB BA BB
AAA AAB ABA ABB BAA BAB BBA BBB
*/