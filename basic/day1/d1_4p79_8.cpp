/**
 * 来自课本p79第8题:
 * 链表表头为ha，对链表进行重组 a0,an-1,a1,an-2,...
 * 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct ListNode {
    string data;
    ListNode *next;
    ListNode() : data("0"), next(nullptr) {}
    ListNode(string x) : data(x), next(nullptr) {}
    ListNode(string x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
    public:
    ListNode * Reset(ListNode *head)
    {

        vector<ListNode*>vec;
        ListNode *p=head->next;
        while(p)
        {
            vec.emplace_back(p);
            p=p->next;
        }
        ListNode *pre=nullptr;
        int i=0,j=vec.size()-1;
        while(i<=j)
        {
            vec[i]->next=vec[j];
            
            if(pre) pre->next=vec[i];//两句一起看--在上一个循环中,pre记录了当时的j,就指向了现在的i
            pre=vec[j];

            i++;j--;  
        }
        if(pre)pre->next=nullptr;   //在最后将next置null
        return head->next;
    }
};



int main()
{   
    ListNode *head=new ListNode("0"),*p;
    ListNode d1("0");
    ListNode d2("1");
    ListNode d3("2");
    ListNode d4("3");
    ListNode d5("4");
    p=head;
    p->next=&d1;
    p=p->next;
    p->next=&d2;
    p=p->next;
    p->next=&d3;
    p=p->next;
    p->next=&d4;
    p=p->next;
    p->next=&d5;

    Solution f;
    ListNode *pp=f.Reset(head);
    while(pp)
    {
        cout<<pp->data<<endl;
        pp=pp->next;
    }
    return 0;
}