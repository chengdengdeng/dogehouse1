//21.合并两个有序链表

//迭代，依次比较两个链表中的最小节点
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else{
                prec->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        //将链表末尾指向未合并完成的链表
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};