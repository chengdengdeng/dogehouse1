// 19.删除链表倒数第n个节点

// 1.计算链表长度
class Solution{
public:
	int getLength(ListNode* head){
		int length = 0;
		while(head){
			length++;
			head = head->next;
		}
		return length;
	}

	ListNode* removeNthFromEnd(ListNode* head,int n){
		ListNode* dummy = new ListNode(0,head);
		int length = getLength(head);
		ListNode* cur = dummy;
		for (int i = 1; i < length - n + 1; ++i) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
		ListNode* ans = dummy->next;
		delete dummy;
		return ans;
	}
};

// 2.栈
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n){
		ListNode* dummy = new ListNode(0,head);
		stack<ListNode*> stk;
		ListNode* cur = dummy;
		while(cur){
			stk.push(cur);
			cur = cur->next;
		}
		for(int i = 0;i < n;i++){
			stk.pop();
		}
		ListNode* prev = stk.top();
		prev->next = pre->next->next;
		ListNode* ans = dummy->next;
		delete dummy;
		return ans;
	}
};

// 3.双指针
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head,int n){
		ListNode* dummy = new ListNode(0,head);
		ListNode* first = head;
		ListNode* second = dummy;
		for (int i = 0; i < n; ++i) {
			first = first->next;
		}
		while(first){
			first = first->next;
			second = second->next;
		}
		second->next = second->next->next;
		ListNode* ans = dummy->next;
		delete dummy;
		return ans;
	}
};