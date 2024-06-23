// 133.克隆图

// 1.深度优先
class Solution{
public:
	unordered_map<Node*,Node*> visited;
	Node* cloneGraph(Node* node){
		if (node == nullptr){
			return node;
		}

		if (visited.find(node) != visited.end()){
			return visited[node];
		}

		Node* cloneNode = new Node(node->val);
		visited[node] = cloneNode;

		for (auto& neighbor: node->neighbors) {
			cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
		}
		return cloneNode;
	}
};

// 2.广度优先遍历
class Solution{
public:
	Node* cloneGraph(Node* node){
		if(node == nullptr){
			return node;
		}

		unordered_map<Node*,Node*> visited;
		queue<Node*> Q;
		Q.push(node);
		visited[node] = new Node(node->val);

		while(!Q.empty()){
			auto n = Q.front();
			Q.pop();
			for (auto& neighbor:n->neighbors) {
				if(visited.find(neighbor) == visited.end()){
					visited[neighbor] = new Node(neighbor->val);
					Q.push(neighbor);
				}
				visited[n]->neighbors.emplace_back(visited[neighbor]);
			}
		}
		return visited[node];
	}
};