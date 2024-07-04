#include <iostream>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char ElemType;
using namespace std;

typedef struct
{
	ElemType* base;
	ElemType* top;
	int stacksize;
}Sqstack;

void InitStack(Sqstack &s)
{
	s.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s.base) exit(OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
}
ElemType GetTop(Sqstack s, ElemType& e)
{
	if (s.base == s.top) return false;
	e = *(s.top - 1);
	return e;
}
int isEmpty(Sqstack s)//是空栈返回1，不是返回0
{
	if (s.base == s.top) return 1;
	return 0;
}
void Push(Sqstack& s, ElemType e)//压栈
{
	if (s.top - s.base >= s.stacksize)//如果栈满
	{
		s.base = (ElemType*)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(ElemType));
		//realloc:初始指针，（初始长度+增量）*sizeof（）.
		if (!s.base) exit(OVERFLOW);
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top++ = e;
}
ElemType Pop(Sqstack& s, ElemType& e)//取出栈顶元素
{
	if (s.base == s.top) return false;
	e = *(--s.top);
	return e;
}

//单个输入
int main()
{
	Sqstack s;
	InitStack(s);
	int flag = 1;
	char ch;
	char e = ' ';
	cin >> ch;
	while (ch != '#')//输入为#，或者栈空结束循环
	{
		if (ch == '(' || ch == '[')
		{
			Push(s, ch);
		}
		else if (ch == ')')
		{
			if (!isEmpty(s) && GetTop(s, e) == '(')
			{
				Pop(s, e);
			}
			else flag = 0;
		}
		else if (ch == ']')
		{
			if (!isEmpty(s) && GetTop(s, e) == '[')
			{
				Pop(s, e);
			}
			else flag = 0;
		}
		cin >> ch;
	}
	if (!isEmpty(s)) flag = 0;
	if (flag) cout << "匹配成功";
	else cout << "匹配失败";
}

/*
int main()
{
	Sqstack s;
	int i = 0;
	ElemType e = NULL;
	int flag = 1;
	InitStack(s);

	char q[100] = "((([[[]])))(([[]]))";//((([[[]]])))(([[]]))
	char j = '\0';
	if (j == q[5]) i = 39;
	Push(s, q[3]);
	cout<<i;
	char q[100] = "((([[]])))";
	while (q[i]!='\0')
	{
		if (q[i] == '(' || q[i] == '[')
		{
			Push(s, q[i]); i++;
		}
		if (q[i] == ')' )
		{
			i++;
			if (GetTop(s, e) == '(')
			{
				Pop(s, e);
			}
			else flag = 0;
		}
		else if (q[i] == ']')
		{
			i++;
			if (GetTop(s, e) == '[')
			{
				Pop(s, e);
			}
			else flag = 0;
		}
	}
	if (!isEmpty(s)) flag = 0;
	cout << flag;
	
}*/
//字符串直接进去

/*int main() {
		Sqstack S;
		InitStack(S);
		int flag = 1;
		char ch, a, b;
		scanf_s("%c", &ch);
		while (ch != '#' && flag) {
			if (ch == '[' || ch == '(')
				Push(S, ch);
			else if (ch == ')') {
				if (!isEmpty(S) && GetTop(S, a) == '(')
					Pop(S, b);
				else
					flag = 0;
			}
			else if (ch == ']')
			{
				if (!isEmpty(S) && GetTop(S, a) == '[')
					Pop(S, b);
				else
					flag = 0;
			}
			scanf_s("%c", &ch);
		}
		if (isEmpty(S) && flag == 1)
			printf("匹配成功\n");
		else
			printf("匹配失败\n");
		return 0;
	}*///
//&


//((([[[]]])))(([[]]))
//((([[])))