#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define pb push_back
#define sz size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define vi vector<int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, k;
int x[1005];
bool final;

void genNext(){
    int i = k;
    while (i >= 1 && x[i] == n - k + i){
        --i;
    }
    if (i == 0){
        final = true;
    }
    else{
        x[i]++;
        for (int j = i + 1; j <= k; j++)
            x[j] = x[j - 1] + 1;
    }
}

void solve(){
	set<int> root;
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
        cin >> x[i];
        root.insert(x[i]);
	}
	final = false;
    genNext();
    if (final)
        cout << k << EL;
    else{
    	int res = 0;
	    for (int i = 1; i <= k; i++){
	    	if (root.count(x[i]))
	    		++res;
	    }
	    cout << k - res << EL;
    }
}

int main(){
	int TC; cin >> TC;
	while (TC--){
		solve();
	}
	return 0;
}

/*
Tại Malibu(Mai Lĩnh) Resort, vào nửa đêm, cả trung đội nhận lệnh tập trung ở sân. 
Mỗi chiến sỹ được đánh số từ 1 đến N. Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội 
ngũ và cứ lần lượt duyệt hết tất cả các khả năng chọn K người như vậy từ nhỏ đến lớn 
(theo số thứ tự). Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải tập đội ngũ, 
hãy tính xem trong lượt chọn K người tiếp theo thì mấy người trong nhóm cũ sẽ được nghỉ. 
Nếu đã là nhóm cuối cùng thì tất cả đều được nghỉ

Input Format

Dòng 1: hai số nguyên dương N và K; Dòng 2 ghi K số thứ tự của các chiến sỹ đang phải tập đội ngũ (viết từ nhỏ đến lớn)

Constraints

1<=K<=N<=1000;

Output Format

In ra số lượng chiến sỹ được nghỉ

Sample Input 0

8 3
4 6 7
Sample Output 0

1
*/

