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
	string s1, s2; cin >> s1 >> s2;
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
Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây:

Insert: chèn một ký tự bất kỳ vào str1.
Delete: loại bỏ một ký tự bất kỳ trong str1.
Replace: thay một ký tự bất kỳ trong str1.
Nhiệm vụ của bạn là đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi hai xâu str1 và str2.
T, str1, str2 thỏa mãn ràng buộc: 1≤T≤100;  1≤length(str1),length(str2) ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input
1
geek gesek

Output
1
*/