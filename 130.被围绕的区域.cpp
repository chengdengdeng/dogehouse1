// 130.被围绕的区域

// 1.深度优先
class Solution{
public:
	int n ,m;
	void dfs(vector<vector<char>>& board,int x,int y){
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O'){
			return;
		}
		board[x][y] = 'A';
		dfs(board,x+1,y);
		dfs(board,x-1,y);
		dfs(board,x,y+1);
		dfs(board,x,y+1);
	}

	void solve(vector<vector<char>>& board){
		n = board.size();
		if (n == 0){
			return;
		}
		m = board[0].size();
		for (int i = 0; i < n; ++i) {
			dfs(board,i,0);
			dfs(board,i,m-1);
		}
		for (int i = 1; i < m - 1; ++i) {
			dfs(board,0,i);
			dfs(board,n-1,i);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'A'){
					board[i][j] = 'O';
				} else if (board[i][j] == 'O'){
					board[i][j] = 'X';
				}
			}
		}
	}
};

// 2.广度优先
class Solution{
public:
	const int dx[4] = {1,-1,0,0};
	const int dy[4] = {0,0,1,-1};

	void solve(vector<vector<char>>& board){
		int n = board.size();
		if(n == 0){
			return;
		}
		int m = board[0].size();
		queue<pair<int,int>> que;
		for (int i = 0; i < n; ++i) {
			if(board[i][0] == 'O'){
				que.emplace(i,0);
				board[i][0] = 'A';
			}
			if(board[i][m-1] == 'O'){
				que.emplace(i,m-1);
				board[i][m-1] = 'A';
			}
		}

		for (int i = 0; i < m-1; ++i) {
			if(board[0][i] == 'O'){
				que.emplace(0,i);
				board[0][i] = 'A';
			}
			if(board[n-1][i] == 'O'){
				que.emplace(n-1,i);
				board[n-1][i] = 'A';
			}
		}
		while(!que.empty()){
			int x = que.front().first, y = que.front().second;
			que.pop();
			for (int i = 0; i < 4; ++i) {
				int mx = x + dx[i],my = y + dy[i];
				if(mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O'){
					continue;
				}
				que.emplace(mx,my);
				board[mx][my] = 'A';
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if(board[i][j] == 'A'){
					board[i][j] = 'O';
				} else if(board[i][j] == 'O'){
					board[i][j] = 'X';
				}
			}
		}
	}
};