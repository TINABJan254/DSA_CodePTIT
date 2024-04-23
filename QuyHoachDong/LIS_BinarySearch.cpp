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

int lengthOfLIS(int n, int *a){
	vector<int> ans;

	ans.pb(a[1]);

	for (int i = 2; i <= n; i++){
		if (a[i] > ans.back()){
			//If the current number is greater
            // than the last element of the answer
            // vector, it means we have found a
            // longer increasing subsequence.
            // Hence, we append the current number
            // to the answer vector.
			ans.pb(a[i]); 
		}
		else {
			// If the current number is not
            // greater than the last element of
            // the answer vector, we perform
            // a binary search to find the smallest
            // element in the answer vector that
            // is greater than or equal to the
            // current number.
            int firstPos = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[firstPos] = a[i];
		}		
	}

	// The length of the answer vector
    // represents the length of the
    // longest increasing subsequence.
	return ans.sz;
}

void solve(){
	int n; cin >> n;
	int a[n + 5];
	for (int i = 1; i <= n; i++) cin >> a[i];

	cout << lengthOfLIS(n, a);
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Complexity: O(nLogn)

ans[i] : lưu phần cuối cũng nhỏ nhất có thể của các dãy con có độ dài i + 1

với mỗi a[i] ta đi kiểm tra:
	- nếu a[i] > phần tử cuối của vector ans hay lớn hơn all phần tử trong ans thì ta 
	thêm a[i] vào cuối ans (tức là có thể mở rộng độ dài LIS)
	- th còn lại ta đi tìm phần tử đầu tiên >= a[i] và thay thế ans[pos] = a[i] 
	(a[i] là nghiệm tốt hơn)

Chú ý vector ans mục đích chỉ để lưu độ dài của LIS, ko phải dùng để lưu các phần tử của LIS

Với số n lên đến 10^5 thì phải áp dụng binary search để tối ưu với độ phức tạp là NlogN
Bạn được cung cấp một mảng chứa n số nguyên. Nhiệm vụ của bạn là xác định
dãy con dài nhất tăng dần trong mảng, tức là dãy con dài nhất mà mọi phần tử
đều lớn hơn phần tử trước đó. Một dãy con là một dãy có thể được dẫn xuất từ
mảng bằng cách xóa một số phần tử mà không làm thay đổi thứ tự của các phần
tử còn lại.
Input Format
	Dòng đầu tiên chứa số nguyên n: kích thước của mảng. Sau đó có n số nguyên
	x1, x2,..., xn: nội dung của mảng.
Constraints
	1≤n≤2⋅10^5; 1≤xi≤10^9;
Output Format
	In ra chiều dài của dãy con tăng dài nhất

Sample Input 0
6
1 2 4 1 5 2
Sample Output 0
4

Sample Input 1
5
1 1 1 1 1
Sample Output 1
1
*/