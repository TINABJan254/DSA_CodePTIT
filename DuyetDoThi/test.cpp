//Dijkstra
int a[105][105], u, n, d[105], e[105], vs[105];
void DIJKSTRA(int u)
{
    // khởi tạo
    for (int v = 1; v <= n; v++) {
        d[v] = a[u][v]; e[v] = u;
    }
    // bắt đầu tìm kiếm từ đỉnh u d[u] = 0;
    e[u] = 0;
    vs[u] = 1;

    while (1){
        int s = 0, min = 100000;
        // tìm đỉnh s sao cho d[s] min và vs[s] = 0 
        for (int v = 1; v <= n; v++) {
            if (vs[v] == 0 && d[v] < min){
                min = d[v]; 
                s = v;
            }
        }
        if (s == 0) // nếu không tìm được đỉnh s thì kết thúc
            return;

        vs[s] = 1; // đánh dấu đỉnh s

        for (int v = 1; v <= n; v++){
            if (vs[v] == 0 && d[v] > d[s] + a[s][v]){
                d[v] = d[s] + a[s][v]; 
                e[v] = s;
            }
        }
    }
}


//Bellman-Ford
int n, s, a[100][100], d[100], e[100];

int BellmanFord(int s) {
    int dem, u, v;

    for (v = 1; v <= n; v++) {
        d[v] = a[s][v];
        e[v] = s;
    }
    d[s] = 0;
    e[s] = 0;

    int ok = 0;
    for (dem = 1; dem <= n - 1; dem++) {
        int ok = 1;
        for (v = 1; v <= n; v++) {
            for (u = 1; u <= n; u++) {
                if (d[v] > d[u] + a[u][v]) {
                    d[v] = d[u] + a[u][v];
                    e[v] = u;
                    ok = 0;
                }
            }
        }
        if (ok == 1) return 1;
    }
    return 0;
}


//Floyd
int n, a[100][100], d[100][100], e[100][100];

int Floyd() {
    int i, j, k;
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            d[i][j] = a[i][j];
            e[i][j] = i;
        }
    }

    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    e[i][j] = k;
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (d[i][i] < 0) return 0;
    }
    
    return 1;
}
//Kruskal

int n, m, d[10000], c[10000], ts[10000];
int vs[100], t[100];

void Kruskal() {
    // Sort edges by weight
    for (int i = 1; i <= m - 1; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (ts[i] > ts[j]) {
                swap(ts[i], ts[j]);
                swap(d[i], d[j]);
                swap(c[i], c[j]);
            }
        }
    }

    int wt = 0, k = 0;
    for (int i = 1; i <= n; i++) {
        vs[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        if (!(vs[d[i]] != 0 && vs[d[i]] == vs[c[i]])) {
            k++;
            t[k] = i;
            wt += ts[i];
            if (k == n - 1) {
                cout << wt << endl;
                for (int j = 1; j <= k; j++) {
                    cout << d[t[j]] << " " << c[t[j]] << endl;
                }
                return;
            }
            int u = d[i], v = c[i];
            if (vs[u] == 0 && vs[v] == 0) {
                vs[u] = k;
                vs[v] = k;
            } else if (vs[u] == 0 && vs[v] != 0) {
                vs[u] = vs[v];
            } else if (vs[u] != 0 && vs[v] == 0) {
                vs[v] = vs[u];
            } else if (vs[u] < vs[v]) {
                int tg = vs[v];
                for (int j = 1; j <= n; j++) {
                    if (vs[j] == tg) vs[j] = vs[u];
                }
            } else if (vs[v] < vs[u]) {
                int tg = vs[u];
                for (int j = 1; j <= n; j++) {
                    if (vs[j] == tg) vs[j] = vs[v];
                }
            }
        }
    }
}


//Prim
int n, a[100][100];
int vs[100], d[100], e[100];

void Prim(int s) {
    for (int v = 1; v <= n; v++) {
        vs[v] = 0;
        d[v] = a[s][v];
        e[v] = s;
    }

    vs[s] = 1;
    d[s] = 0;
    e[s] = 0;
    int wt = 0, dem = 1;

    while (dem < n) {
        int u = 0;
        int min = INT_MAX;

        for (int v = 1; v <= n; v++) {
            if (vs[v] == 0 && d[v] < min) {
                min = d[v];
                u = v;
            }
        }

        if (u == 0) {
            cout << "Khong co cay khung" << endl;
            return;
        }

        vs[u] = 1;
        wt += a[u][e[u]];
        dem++;

        for (int v = 1; v <= n; v++) {
            if (vs[v] == 0 && d[v] > a[u][v]) {
                d[v] = a[u][v];
                e[v] = u;
            }
        }
    }

    cout << wt << endl;
    for (int v = 1; v <= n; v++) {
        if (e[v] != 0) {
            cout << v << " " << e[v] << endl;
        }
    }

    return;
}
