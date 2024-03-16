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
int sum;
int a[100], x[100];
bool flag;



void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sum = 0;
	flag = false;
}

void display(int num){
	flag = true;
	cout << "[";
	for (int i = 1; i < num; i++)
		cout << x[i] << ' ';
	cout << x[num] << "] ";
}

void Try(int i, int pre_i){
	for (int j = pre_i; j <= n; j++){
		if (sum + a[j] <= k){
			sum += a[j];
			x[i] = a[j];
			if (sum == k){
				display(i);
			}
			else if (sum < k) {
				Try(i + 1,  j + 1);
				
			}
			sum -= a[j];
		}
	}
}

void solve(){
	Init();
	sort(a + 1, a + n + 1);
	Try(1, 1);
	if (!flag)
		cout << "-1";
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
Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K. Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho tổng các phần tử của dãy con đó đúng bằng K. Các phần tử của dãy số A[] được giả thuyết là nguyên dương và không có các phần tử giống nhau. Ví dụ với dãy con A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[] và số K; dòng tiếp theo đưa vào N phần tử của dãy số A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤10; 1≤ K, A[i] ≤100.
Output:

Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn yêu cầu bài toán theo thứ tự từ điển, trong đó mỗi dãy con được bao bởi các ký tự [, ]. Nếu không có dãy con nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.
Input
2
5 50
5  10 15 20  25
8  53
15  22  14  26  32  9  16  8

Output
[5 10 15 20] [5 20 25] [10 15 25]
[8 9 14 22] [8 14 15 16] [15 16 22]
*/