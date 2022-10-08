//leetcode 83 未设置main函数
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        
        while(p!=nullptr)
        {
            ListNode *current=p;
            ListNode *p1=p->next;
            while (p1!=nullptr)
            {
                if(p1->val==p->val)
                {
                    ListNode *del=p1;
                    p1=p1->next;
                    current->next=p1;
                    
                    delete del;

                }
                else
                {
                    current=p1;
                    p1=p1->next;
                }
            }
            p=p->next;
        }
        return head;
    }
};