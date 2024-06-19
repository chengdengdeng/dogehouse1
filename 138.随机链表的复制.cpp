// 138.随机链表的复制

// 1.回溯+哈希
class Solution{
public:
	unordered_map<Node*,Node*> cachedNode;

	Node* copyRandomList(Node* head){
		if (head == nullptr){
			return nullptr;
		}
		if (!cachedNode.count(head)){
			Node* headNew = new Node(head->val);
			cachedNode[head] = headNew;
			headNew->next = copyRandomList(head->next);
			headNew->random = copyRandomList(head->random);
		}
		return cachedNode[head];
	}
};

// 2.迭代+节点拆分
class Solution{
public:
	Node* copyRandomList(Node* head){
		if(head == nullptr){
			return nullptr;
		}
		for (Node* node = head;node != nullptr;node = node->next->next) {
			Node* nodeNew = new Node(node->val);
			nodeNew->next = node->next;
			node->next = nodeNew;
		}
		for (Node* node = head;node != nullptr;node = node->next->next) {
			Node* nodeNew = node->next;
			nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
		}
		Node* headNew = head->next;
		for (Node* node = head;node != nullptr;node = node->next) {
			Node* nodeNew = node->next;
			node->next = node->next->next;
			nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
		}
		return headNew;
	}
};