// 117.填充每个节点下一个右侧节点

// 1.层次遍历
class Solution{
public:
	Node* connect(Node* root){
		if (!root){
			return nullptr;
		}
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			int n = q.size();
			Node *last = nullptr;
			for (int i = 1; i <= n; ++i) {
				Node *f = q.front();
				q.pop();
				if (f->left){
					q.push(f->left);
				}
				if (f->right){
					q.push(f->right);
				}
				if (i != 1){
					last->next = f;
				}
				last = f;
			}
		}
		return root;
	}
};

// 2.借助外力
class Solution{
public:
	void handle(Node* &last,Node* &p,Node* &nextStart){
		if(last){
			last->next = p;
		}
		if(!nextStart){
			nextStart = p;
		}
		last = p;
	}

	Node* connect(Node* root){
		if(!root){
			return nullptr;
		}
		Node *start = root;
		while(start){
			Node *last = nullptr,*nextStart = nullptr;
			for (Node *p = start;p != nullptr;p = p->next) {
				if(p->left){
					handle(last,p->left,nextStart);
				}
				if(p->right){
					handle(last,p->right,nextStart);
				}
			}
			start = nextStart;
		}
		return root;
	}
};