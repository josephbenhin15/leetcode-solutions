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
    int maxPathScore(vector<vector<int>>& g, int k) {
        int m = g.size();
        int n = g[0].size(); 
        
        vector<vector<vector<int>>> d(
            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));
        
        d[0][0][0] = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (d[i][j][c] == INT_MIN) continue;
                    
                    if (i + 1 < m) {
                        int v = g[i + 1][j];
                        int w = (v == 0 ? 0 : 1);
                        
                        if (c + w <= k) {
                            d[i + 1][j][c + w] =
                                max(d[i + 1][j][c + w], d[i][j][c] + v);
                        }
                    }
                    
                    if (j + 1 < n) {
                        int v = g[i][j + 1];
                        int w = (v == 0 ? 0 : 1);
                        
                        if (c + w <= k) {
                            d[i][j + 1][c + w] =
                                max(d[i][j + 1][c + w], d[i][j][c] + v);
                        }
                    }
                }
            }
        }
        
        int a = INT_MIN;
        for (int c = 0; c <= k; c++) {
            a = max(a, d[m - 1][n - 1][c]);
        }
        
        return a < 0 ? -1 : a;
    }  
};