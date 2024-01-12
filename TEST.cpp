int bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		if (cur == end) return depth[cur];
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (depth[nxt] == 0) {
				q.push(nxt);
				depth[nxt] = depth[cur] + 1;
			}
		}
	}
	return -1;
}