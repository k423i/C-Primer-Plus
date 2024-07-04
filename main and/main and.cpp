#include <iostream>
#include <stdlib.h>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASALBE -1
#define OVERFLOW -2

typedef struct {
	char* base;
	char* top;
	int stacksize;
}Sqstack;

int InitStack(Sqstack& S);
int StackEmpty(Sqstack S);
int StackLength(Sqstack S);
char GetTop(Sqstack S, char& e);
//char Push(Sqstack& S, char e);
char Pop(Sqstack& S, char& e);

int InitStack(Sqstack& S) {
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	printf("栈初始化成功\n");
	return OK;
}
int StackEmpty(Sqstack S) {
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}
int StackLength(Sqstack S) {
	return S.top - S.base;
}
char GetTop(Sqstack S, char& e) {
	if (S.top == S.base)  return ERROR;
	e = *(S.top - 1);
	return e;
}
void Push(Sqstack& S, char e) {
	if (S.top - S.base >= STACK_INIT_SIZE) {
		S.base = (char*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(char));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
}
char Pop(Sqstack& S, char& e) {
	if (S.top == S.base)  return ERROR;
	e = *--S.top;
	return e;
}

int main() {
	Sqstack S;
	InitStack(S);
	int flag = 1;
	char ch, a, b;
	scanf_s("%c", &ch);
	while (ch != '#' && flag) {
		if (ch == '[' || ch == '(')
			Push(S, ch);
		else if (ch == ')') {
			if (!StackEmpty(S) && GetTop(S, a) == '(')
				Pop(S, b);
			else
				flag = 0;
		}
		else if (ch == ']')
		{
			if (!StackEmpty(S) && GetTop(S, a) == '[')
				Pop(S, b);
			else
				flag = 0;
		}
		scanf_s("%c", &ch);
	}
	if (StackEmpty(S) && flag == 1)
		printf("匹配成功\n");
	else
		printf("匹配失败\n");
	return 0;
}
