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

bool check(int *a, int *b, int n){
	for (int i = 0; i < n; i++){
		if (b[i] != a[i] && b[i] != a[n - i - 1])	
			return false;
	}
	return true;
}

void solve(){
	int n; cin >> n;
	int a[n + 5], b[n + 5];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	if (check(a, b, n))
		cout << "Yes\n";
	else
		cout << "No\n";
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
Theo nguyên tắc sắp xếp của đề bài
Ta có các phần tử trong mảng chỉ có thể nằm tại 1 trong hai chỗ
	1. tại vị trí i
	2. tại vi trí n - i - 1
=> Ta chỉ cần đi so sánh mảng được sắp xếp với mảng đề cho
Với mảng đã được sắp xếp ta xét từng vị trí i của mảng (i = 1..n)
	sorted_a[i] == a[i] || a[n - i - 1] thì phần tử tại vị trí i oke
	ngược lại thì sai

PROB:
Cho mảng A[] gồm N số và thực hiện các thao tác theo nguyên tắc dưới đây:

Ta chọn một mảng con sao cho phần tử ở giữa của mảng con cũng là phần tử ở giữa của mảng A[] (trong trường hợp N lẻ).
Đảo ngược mảng con đã chọn trong mảng A[]. Ta được phép chọn mảng con và phép đảo ngược mảng con bao nhiêu lần tùy ý.
Ví dụ với mảng A[] = {1, 6, 3, 4, 5, 2, 7} ta có câu trả lời là Yes vì: ta chọn mảng con {3, 4, 5} và đảo ngược để nhận được mảng A[]={1, 6, 5, 4, 3, 2, 7}, chọn tiếp mảng con {6, 5, 4, 3, 2} và đảo ngược ta nhận được mảng A[]={1, 2, 3, 4, 5, 6, 7}. Hãy cho biết ta có thể sắp xếp được mảng A[] bằng cách thực hiện các thao tác kể trên hay không?

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N ≤50; 0≤A[i]≤1000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input
2
7
1 6 3 4 5 2 7
7
1 6 3 4 5 7 2

Output
Yes
No
*/