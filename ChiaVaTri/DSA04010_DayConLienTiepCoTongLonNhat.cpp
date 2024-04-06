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

ll crossingSum(int *a, int L, int mid, int R){
	ll sumLeft = 0, maxSumLeft = 0;
	ll sumRight = 0, maxSumRight = 0;
	
	for (int i = mid; i >= L; i--){
		sumLeft += a[i];
		maxSumLeft = max(maxSumLeft, sumLeft);
	}
	
	for (int i = mid + 1; i <= R; i++){
		sumRight += a[i];
		maxSumRight = max(maxSumRight, sumRight);
	}
	
	return (maxSumLeft + maxSumRight);
}

ll maxSum(int *a, int L, int R){
	if (L == R)
		return a[L];
	int mid = (L + R) / 2;
	return max({
		maxSum(a, L, mid),
		maxSum(a, mid + 1, R), 
		crossingSum(a, L, mid, R)
	});
}

void solve(){
	int n; cin >> n;
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	cout << maxSum(a, 0, n - 1) << EL;
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
Cho mảng A[] gồm N số có cả các số âm và số dương. 
Nhiệm vụ của bạn là tìm mảng con liên tục có tổng lớn nhất của mảng. 
Ví dụ với mảng A[]={-2, -5, 6, -2,-3, 1, 5, -6} ta có kết quả là 7 tương ứng với 
dãy con {6, -2, -3, 1, 5}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. 
Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào hai số N tương ứng với số phần tử của 
mảng; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤100; -100≤A[i] ≤100.
Output:

Đưa ra tổng con liên tục lớn nhất của mỗi test theo từng dòng.
Ví dụ:

Input

Output

1
8
-2 -5 6 -2 -3 1 5 -6

7
*/
