#define MAXN 405
struct BipartiteGraph {

    int nx, ny;
    int delX, delY;
    bool used[MAXN], g[MAXN][MAXN];
    bool X[MAXN], Y[MAXN];
    int mx[MAXN], my[MAXN];

    void init(int nx, int ny) {
        this->nx = nx; this->ny = ny;
        memset(g, 0, sizeof(g));
    }

    void addEdge(int u, int v) {
        g[u][v] = true;
        //cout << u << " " << v << endl;
    }

    bool find(int u) {
        for (int v = 0; v < ny; v++) {
            if (!used[v] && g[u][v]) {
                used[v] = true;
                if (my[v] == -1 || find(my[v])) {
                    mx[u] = v;
                    my[v] = u;
                    return 1;
                }
            }
        }
        return 0;
    }

    int MaxMatch() {
        for (int i = 0; i < nx; i++)
            mx[i] = -1;
        for (int j = 0; j < ny; j++)
            my[j] = -1;
        int ret = 0;
        for (int i = 0; i < nx; i++) {
            memset(used, false, sizeof(used));
            if (find(i)) ret++;
        }
        return ret;
    }

    bool findY(int u) {
        for (int v = 0; v < ny; v++) {
            if (v != delY && !used[v] && g[u][v]) {//notice it's g[u][v]
                used[v] = 1;
                if (my[v] == -1 || findY(my[v]))
                    return 1;
            }
        }
        return 0;
    }

    bool findX(int u) {
        for (int v = 0; v < nx; v++) {
            if (v != delX && !used[v] && g[v][u]) {//notice it's g[v][u]
                used[v] = 1;
                if (mx[v] == -1 || findX(mx[v]))
                    return 1;
            }
        }
        return 0;
    }

    //X[i]=1 or Y[i]=1 means it's not a key vertex!!!
    void solve() {
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        for (int i = 0; i < nx; i++) {
            if (mx[i] == -1) {
                X[i] = 1;
            } else {
                delY = mx[i];
                memset(used, 0, sizeof(used));
                if (findY(i)) Y[delY] = 1;
            }
        }
        for (int j = 0; j < ny; j++) {
            if (my[j] == -1) {
                Y[j] = 1;
            } else {
                delX = my[j];
                memset(used, 0, sizeof(used));
                if (findX(j)) X[delX] = 1;
            }
        }
    }

}g;
