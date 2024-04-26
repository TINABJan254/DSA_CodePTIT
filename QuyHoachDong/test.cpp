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

bool cmp(string x, string y){
    if (x[0] != '-' && y[0] == '-')
        return true;
    if (x[0] == '-' && y[0] != '-')
        return false;
    if (x[0] == '-' && y[0] == '-'){
        if (x.sz != y.sz)
            return x.sz < y.sz;
        return x < y;
    }
    if (x.sz != y.sz)
        return x.sz > y.sz;
    return x > y;
}

void solve(){
    int n; cin >> n;
    string a[n + 5];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++){
        if (a[i][0] == '-'){
            sort(a[i].begin() + 1, a[i].end());
            if (a[i].sz > 2 && a[i][1] == '0'){
                int pos = 1;
                while (pos < (int)a[i].sz){
                    if (a[i][pos] != '0')
                        break;
                    ++pos;
                }
                swap(a[i][1], a[i][pos]);
            }
        }
        else{
            sort(a[i].begin(), a[i].end(), greater<char>());
        }
    }
    
    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

int main(){
    faster();
    solve();
    return 0;
}

/*

*/