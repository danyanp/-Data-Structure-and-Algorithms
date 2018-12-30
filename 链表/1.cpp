#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define ERROR 1
typedef int Position;
typedef struct SNode
{
	ElementType *Data; /* 存储元素的数组 */
	Position Top;	  /* 栈顶指针 */
	int MaxSize;	   /* 堆栈最大容量 */
} SNode, *Stack;
//创建一个空栈
Stack CreateStack(int MaxSize);
//判读栈是否以满
bool IsFull(Stack S);
//将元素压入栈
bool Push(Stack S, ElementType X);
//判断栈是否为空
bool IsEmpty(Stack S);
//删除并返回栈顶元素
ElementType Pop(Stack S);
int main()
{
	Stack s;
	s = CreateStack(10);
	for (int i = 0; i < 10; i++)
	{
		printf("入栈 %d\n", i);
		Push(s, i);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("出栈 %d\n", Pop(s));
	}
	return 0;
}
Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S)
{
	return (S->Top == S->MaxSize - 1);
}

bool Push(Stack S, ElementType X)
{
	if (IsFull(S))
	{
		printf("堆栈满");
		return false;
	}
	else
	{
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool IsEmpty(Stack S)
{
	return (S->Top == -1);
}

ElementType Pop(Stack S)
{
	if (IsEmpty(S))
	{
		printf("堆栈空");
		return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
	}
	else
		return (S->Data[(S->Top)--]);
}