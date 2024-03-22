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

int n, k;
int a[100];
bool used[100];
int target_sum;
bool flag;

void Init(){
	cin >> n >> k;
	target_sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		target_sum += a[i];
	}
	memset(used, false, sizeof(used));
	flag = false;
}

void Try(int start, int cur_sum, int cnt){
	if (flag){
		return;
	}
	if (cnt == k + 1){
		flag = true;
		return;
	}
	for (int j = start; j <= n; j++){
		if (!used[j] && cur_sum + a[j] <= target_sum){
			used[j] = true;
			if (cur_sum + a[j] == target_sum){
				Try(1, 0, cnt + 1);
			}
			else {
				Try(j + 1, cur_sum + a[j], cnt);
			}
			used[j] = false;
		}
	}
}

void solve(){
	Init();
	if (target_sum % k != 0){
		cout << "0\n";
	}
	else {
		target_sum /= k;
		Try(1, 0, 1);
		if (flag)
			cout << "1\n";
		else
			cout<< "0\n";
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
Cho mảng các số nguyên A[] gồm N phần tử. 
Hãy chia mảng số nguyên A[] thành K tập con khác rỗng sao cho 
tổng các phần tử của mỗi tập con đều bằng nhau. 
Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong 
tất cả các tập con. Ví dụ với A[] = {2, 1, 4, 5, 6}, K =3 
ta có kết quả {2, 4}, {1, 5}, {6}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. 
Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và K; 
dòng tiếp theo đưa vào N số của mmảng A[]; 
các số được viết cách nhau một vài khoảng trống.
T, N, K, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N, K≤20, 0≤A[i]≤100.
Output:

Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, 
ngược lại đưa ra 0.
Input
2
5 3
2 1 4 5 6
5 3
2 1 5 5 6

Output
1
0
*/