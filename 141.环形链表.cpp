//141.环形链表

//哈希表
class Solution{
public:
	bool hasCycle(ListNode *head){
		unordered_set<ListNode*> seen;
		while(head != nullptr){
			if (seen.count(head)){
				return true;
			}
			seen.insert(head);
			head = head->next;
		}
		return false;
	}
};

//快慢指针（通用方法）
class Solution{
public:
	bool hasCycle(ListNode *head){
		if (head == nullptr || head->next == nullptr){
			return false;
		}
		ListNode* slow = head;
		ListNode* fast = head->next;
		while(slow != fast){
			if(fast == nullptr || fast ->next == nullptr){
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}
};
