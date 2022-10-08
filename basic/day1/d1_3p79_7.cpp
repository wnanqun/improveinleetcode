/**
 * 来自课本p79第7题:
 * 链表含有三种数据，对链表进行分链
 * 要求:使用原链表空间，头结点可另辟
*/
#include <iostream>
#include <string>
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
    ListNode * Classify(ListNode *head,string name)
    {
        //制作附加头结点 共 int char string 三种
        ListNode *h1_int=new ListNode("0"),*p1;
        ListNode *h2_char=new ListNode("0"),*p2;
        ListNode *h3_string=new ListNode("0"),*p3;
        p1=h1_int;
        p2=h2_char;
        p3=h3_string;
        //进行分割
        ListNode *p=head->next;
        while(p)
        {
            if(!p->data.compare("int"))
            { p1->next=p; p1=p;}//cout<<"int"<<endl;
            else if(!p->data.compare("char"))
            { p2->next=p; p2=p;}//cout<<"char"<<endl;
            else if(!p->data.compare("string"))
            { p3->next=p; p3=p;}//cout<<"string"<<endl;
            //
            p=p->next;
        }
        //在尾巴处置null
        p1->next=nullptr;
        p2->next=nullptr;
        p3->next=nullptr;

        // //检验
        // p=h3_string->next;
        // while(p)
        // {
        //     cout<<p->data<<endl;
        //     p=p->next;
        // }
        
        
        //选择
        if(name=="int") return h1_int->next;
        if(name=="char") return h2_char->next;
        if(name=="string") return h3_string->next;
        else return h1_int->next; 
    }
};



int main()
{
    ListNode *head=new ListNode("0"),*p;
    ListNode d1("string");
    ListNode d2("char");
    ListNode d3("string");
    ListNode d4("int");
    ListNode d5("string");
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
    ListNode *pp=f.Classify(head,"string");
    while(pp)
    {
        cout<<pp->data<<endl;
        pp=pp->next;
    }
    return 0;
}