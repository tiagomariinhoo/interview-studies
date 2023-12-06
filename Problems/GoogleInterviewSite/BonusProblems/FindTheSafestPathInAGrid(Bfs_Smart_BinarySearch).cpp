class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> vec;
    int n, m;
    vector<pair<int, int> > aux;

    /**
     * https://leetcode.com/problems/find-the-safest-path-in-a-grid/submissions/
     * 
       We need to use BFS + Binary Search to solve this problem
        N² * Log (N*N)

        Firstly you need to fill the matrix with the closest thief for each cell. But there's a very smart trick for this part. Usually would be made a normal bfs where you could run a bfs using a single point to fill all the matrix. After that, you can start from another point, and fill out everything again. But it's not efficient since you're filling out the whole matrix again and again. 
        The smartest solution to fill out the whole matrix, is bfs'ing level by level.
        - At the first point, u'll put in a queue all the cells such as the grid[i][j] == 1. Current level == 1
        - After that, store how many cells you have and run a bfs just to fill out the adjacent cells
        - Go to the next level and run a bfs for all cells such as the current level == 2
        - Keep doing it until fill out the whole matrix

        After fill out the whole matrix with the closest thief for each cell, you just need to run a binary search to try to make a path with the current found Middle value. 
        - Try to make a path such as the cell value is always >= 4
        - Try to make a path such as the cell value is always >= 8...
    */

    bool can(int path, vector<vector<int>>& grid) {
        vector<vector<int>> vis(n, vector<int> (n, 0));
        queue<pair<int, int> > q;

        cout << path << endl;

        if (grid[0][0] >= path) {
            q.push({0, 0});
            vis[0][0] = 1;
        }


        while (!q.empty()) {
            auto current = q.front();
            if (current.first == n - 1 and current.second == m - 1) {
                return true;
            }
            q.pop();

            for (int i = 0; i < 4; i++) {
                int xx = current.first + dx[i];
                int yy = current.second + dy[i];

                if (xx >= 0 and xx < n and yy >= 0 and yy < m and grid[xx][yy] >= path and !vis[xx][yy]) {
                    q.push({xx, yy});
                    vis[xx][yy] = 1;
                }
            }
        }


        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // vec = &grid;
        n = grid.size();
        m = grid[0].size();

        queue<pair<int, int> > q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                } else grid[i][j] = INT_MAX;
            }
        }

        int level = 2;

        while(!q.empty()) {
            int nn = q.size();
            while (nn--) { // It will make a bfs for all the points with the current level
                auto current = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int xx = current.first + dx[i];
                    int yy = current.second + dy[i];

                    if (xx >= 0 and xx < n and yy >= 0 and yy < m and grid[xx][yy] > level) {
                        grid[xx][yy] = level;
                        q.push({xx, yy});
                    }
                }
            }
            level++;
        }

        int l = 0, r = n * n;
        int ans = 0;
        while (l < r) {
            int mid = l + (r - l) / 2; // We want to avoid l = mid r - (r - l) / 2, avoid r = mid
            if (can(mid, grid)) {
                l = mid + 1;
                ans = mid;
            } else r = mid;
        }

        return max(ans - 1, 0);
    }
};