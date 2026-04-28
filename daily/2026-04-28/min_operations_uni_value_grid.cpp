/*■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■*

     ██╗ ██████╗ ███████╗        ██████╗ ███████╗███╗   ██╗
     ██║██╔═══██╗██╔════╝        ██╔══██╗██╔════╝████╗  ██║
     ██║██║   ██║███████╗        ██████╔╝█████╗  ██╔██╗ ██║
██   ██║██║   ██║╚════██║        ██╔══██╗██╔══╝  ██║╚██╗██║
╚█████╔╝╚██████╔╝███████║        ██████╔╝███████╗██║ ╚████║
 ╚════╝  ╚═════╝ ╚══════╝        ╚═════╝ ╚══════╝╚═╝  ╚═══╝

                         ── JB ──

■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■*/

// Author :: josephbenhind

class Solution {
public:
    int minOperations(vector<vector<int>>& a, int d) {
        int r = a.size(), c = a[0].size();
        vector<int> v;

        int mod = a[0][0] % d;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] % d != mod) return -1;
                v.push_back(a[i][j]);
            }
        }

        sort(v.begin(), v.end());
        int med = v[v.size() / 2];

        int res = 0;
        for (int x : v) {
            res += abs(x - med) / d;
        }

        return res;
    }
};