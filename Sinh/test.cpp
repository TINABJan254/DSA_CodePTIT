#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EL "\n"
#define pb push_back
#define sz size()

vector<ll> v;
int n;
string s;
bool final;

void Init(){
    final = false;
    s = "";
    for (int i = 0; i < n; i++)
        s += "0";
    s[n - 1] = '9';
}

void genNext(){
    int i = n - 1;
    while (i >= 0 && s[i] == '9'){
        s[i] = '0';
        --i;
    }

    if (i == -1){
        final = true;
    }
    else {
        s[i] = '9';
    }
}

void solve(){
    n = 19;
    Init();
    while (!final){
        v.pb(stoll(s));
        genNext();
    }

    ll ans[305];
    for (int i = 1; i <= 300; i++){
        for (auto x : v){
            if (x % i == 0){
                ans[i] = x;
                break;
            }
        }
    }

    int t; cin >> t;
    while (t--){
        int m;
        cin >> m;
        cout << ans[m] << EL;
    }


}

int main(){
    solve();
    return 0;
}

/*

*/
