#include<iostream>
#include<malloc.h>
using namespace std;
typedef int  Elemtype;

typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode,* Linklist;

void HCreatelist(LNode*& L, int n) //头插法
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	cout << "请输入" << n << "个链表元素" << endl;
	for (int i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void TCreatelist(LNode*& L, int n) //尾插法
{
	L = (LNode*)malloc(sizeof(LNode));
	LNode* r = L;;
	cout << "请输入" << n << "个链表元素" << endl;
	for (int i = 0; i < n; i++) {
		LNode* p = (LNode*)malloc(sizeof(LNode));

		cin >> p->data;
		p->next = NULL;

		r->next = p;
		r = p;
	}

}

Elemtype Getelem(LNode* L, int i) {
	LNode* p = L->next; int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;;;;;
	}
	return p->data;
}

void Insertlist(LNode*& L, int i, Elemtype e)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;

	LNode* p = L; int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		cout << "输入错误" << endl;
	else
	{
		s->next = p->next;
		p->next = s;
	}
}

void Deletelist(LNode* L, int i) {
	LNode* p = L; int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p)
		cout << "输入错误" << endl;
	else

		p->next = p->next->next;
}

void printlist(LNode* L)
{
	LNode* p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	LNode* s;
	TCreatelist(s, 4);
	printlist(s);
	Insertlist(s, 2, 9);
	printlist(s);
	Deletelist(s, 1);
	printlist(s);
}
