class UF {
public:
    vector<int> p, s;
    int n, c;

    UF(int N) : n(N), c(N), p(N), s(N, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int f(int x) { 
        return p[x] == x ? x : p[x] = f(p[x]);
    }

    void u(int a, int b) {
        if (s[a] < s[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
        --c;
    }

    bool m(int a, int b) {
        int x = f(a), y = f(b);
        if (x != y) {
            u(x, y);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& g) {
        int r = g.size(), c = g[0].size();
        UF d(r * c);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i > 0 && g[i][j] == g[i - 1][j]) {
                    if (!d.m(i * c + j, (i - 1) * c + j)) return true;
                }
                if (j > 0 && g[i][j] == g[i][j - 1]) {
                    if (!d.m(i * c + j, i * c + j - 1)) return true;
                }
            }
        }
        return false;
    }
};