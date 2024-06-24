// 433.最小基因变化

// 1.广度优先
class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> cnt;
		unordered_set<string> visited;
		char keys[4] = {'A', 'C', 'G', 'T'};
		for (auto & w : bank) {
			cnt.emplace(w);
		}
		if (start == end) {
			return 0;
		}
		if (!cnt.count(end)) {
			return -1;
		}
		queue<string> qu;
		qu.emplace(start);
		visited.emplace(start);
		int step = 1;
		while (!qu.empty()) {
			int sz = qu.size();
			for (int i = 0; i < sz; i++) {
				string curr = qu.front();
				qu.pop();
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 4; k++) {
						if (keys[k] != curr[j]) {
							string next = curr;
							next[j] = keys[k];
							if (!visited.count(next) && cnt.count(next)) {
								if (next == end) {
									return step;
								}
								qu.emplace(next);
								visited.emplace(next);
							}
						}
					}
				}
			}
			step++;
		}
		return -1;
	}
};

// 2.预处理
class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		int m = start.size();
		int n = bank.size();
		vector<vector<int>> adj(n);
		int endIndex = -1;
		for (int i = 0; i < n; i++) {
			if (end == bank[i]) {
				endIndex = i;
			}
			for (int j = i + 1; j < n; j++) {
				int mutations = 0;
				for (int k = 0; k < m; k++) {
					if (bank[i][k] != bank[j][k]) {
						mutations++;
					}
					if (mutations > 1) {
						break;
					}
				}
				if (mutations == 1) {
					adj[i].emplace_back(j);
					adj[j].emplace_back(i);
				}
			}
		}
		if (endIndex == -1) {
			return -1;
		}

		queue<int> qu;
		vector<bool> visited(n, false);
		int step = 1;
		for (int i = 0; i < n; i++) {
			int mutations = 0;
			for (int k = 0; k < m; k++) {
				if (start[k] != bank[i][k]) {
					mutations++;
				}
				if (mutations > 1) {
					break;
				}
			}
			if (mutations == 1) {
				qu.emplace(i);
				visited[i] = true;
			}
		}
		while (!qu.empty()) {
			int sz = qu.size();
			for (int i = 0; i < sz; i++) {
				int curr = qu.front();
				qu.pop();
				if (curr == endIndex) {
					return step;
				}
				for (auto & next : adj[curr]) {
					if (visited[next]) {
						continue;
					}
					visited[next] = true;
					qu.emplace(next);
				}
			}
			step++;
		}
		return -1;
	}
};