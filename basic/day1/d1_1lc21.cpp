//leetcode 21 未设置main函数
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//链接两个链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head=new ListNode(-1),*p;
    p=head;
    ListNode *p1=list1;
    ListNode *p2=list2;
    while(p1!=nullptr && p2!=nullptr)
    {
        if(p1->val<p2->val )
        {
            //链接
            p->next=p1;//注意，这里是next指针，所以最后也是要用next指针
            //链1向后延伸
            p1=p1->next;
        }
        else 
        {
            p->next=p2;
            //链2向后延伸
            p2=p2->next;
        }
        p=p->next;
    }

    p->next=p1==nullptr? p2:p1;
    return head->next;
    }
};















