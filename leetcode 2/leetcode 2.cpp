#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <strstream>
#include <TextStor.h>
using namespace std;
 struct ListNode {
       int val;
       struct ListNode *next;
  };
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2,int n) {
    int sum1 = 0, sum2 = 0;//l1=2,4,3,结果是342
    int flag = 1;
    l1 = (ListNode*)malloc(sizeof(ListNode));
    //l1 = new ListNode;
    //l2 = new ListNode;
    l2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* l3;
    //l3 = new ListNode;
    l3 = (ListNode*)malloc(sizeof(ListNode));
    l1->next = NULL;
    l2->next = NULL;
    l3->next = NULL;
    for (int j = n; j > 0; j--)//初始化l1,输入3，4，2.链表中是243
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        //p->next = NULL;
        scanf_s("%d", &p->val);
        p->next = l1->next;
        l1->next = p;
    }

    for (int k = n; k > 0; k--)//初始化l2,输入4，6，5.链表中是564
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        //p->next = NULL;
        scanf_s("%d", &p->val);
        p->next = l2->next;
        l2->next = p;
    }
    ListNode* tll=l2;
    
    string s = "";
    ListNode* tol = l1;
    while (tol->next != NULL)
    {
        tol = tol->next;
        //cout << tol->val;
    }//l1里面是2，4，3
    tol = l1;/*
    while (tol->next != NULL)
    {
        tol = tol->next;
        string ch =to_string(tol->val);
        s += ch;
    }
    tol = l1;
    sum1= atoi(s.c_str());
    string b(s.rbegin(), s.rend());
    flag = 1;
    //cout << "sum=" << b;*/
    while (tol->next != NULL)
    {
        tol = tol->next;
        sum1 += flag * (tol->val);
        //cout << "val=" << tol->val;
        flag *= 10;
    }
    //cout << "sum1=" << sum1<<"==";
    flag = 1;
    while (tll->next != NULL)
    {
        tll = tll->next;
        sum2 += flag * (tll->val);
        //cout << "val=" << tll->val;
        flag *= 10;
    }
    //cout << "sum2="<<sum2<<"==";
    //cout << "shuzi="<< asdada;//正向sum=342*/
    //cout << "       " << sum1 << "        ";
    int tool = sum1;
    int toll = sum2;
    int cnt = 0;
    int cntt = 0;
    while (tool != 0)//l1求和的位数
    {
        tool /= 10;
        cnt++;
    }
    while (toll != 0)//l2求和的位数
    {
        toll /= 10;
        cntt++;
    }
    int tag = pow(10,cnt);
    int tga = pow(10, cntt);
    int sum = sum1 + sum2;
    int all = 0;
    //cout << "sum=" << sum;
    int sum0 = sum;
    while (sum0 != 0)//l2求和的位数
    {
        sum0 /= 10;
        all++;
    }//和的位数
    tag = pow(10, all-1);//总和的
    for (int i = all; i > 0; i--)
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        p->val = sum / tag;
        sum %= tag;
        tag /= 10;
        p->next = l3->next;
        l3->next = p;
    }/*
    ListNode* t = l3;
    while (t->next != NULL)
    {
        t = t->next;
        cout << "L3=" << t->val;
    }*/
    return l3;
}/*
for (int j = n; j > 0; j--)//初始化l1,输入3，4，2.链表中是243
{
    ListNode* p = new ListNode;
    //p->next = NULL;
    scanf_s("%d", &p->val);
    p->next = l1->next;
    l1->next = p;
}*/
int main()
{
    ListNode* L1 = 0;
    ListNode* L2 = 0;
    ListNode* l0 = addTwoNumbers(L1,L2, 3);
    while (l0->next != NULL)
    {
        l0 = l0->next;
        cout << l0->val;
    }
    delete L1;
    delete L2;
    delete l0;
}
