//https://leetcode.com/problems/as-far-from-land-as-possible/
//1162. As Far from Land as Possible
class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<int> dx = { 0,0,1,-1 };
		vector<int> dy = { 1,-1,0,0 };
		vector<vector<int>> dist(n, vector<int>(m, -1));
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					dist[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
		int ans = -1;
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[x][y] + 1;
				ans = max(ans, dist[nx][ny]);
				q.push({ nx,ny });
			}
		}
		return ans;
	}
};