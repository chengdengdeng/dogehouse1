//83.删除排序链表中重复元素

class Solution{
public:
	ListNode* deleteDuplicates(ListNode* head){
		if (!head){
			return head;
		}

		ListNode* cur = head;
		while(cur->next){
			if (cur->val == cur->next->val){
				cur->next = cur->next->next;
			}
			else{
				cur = cur->next;
			}
		}
		return head;
	}
};
