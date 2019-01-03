#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct LNode {
  //数据域
  ElemType data;
  //指针域
  struct LNode *next;
} LNode, *bitLNode;
void InitLNode(bitLNode &L);
void AddLNode(bitLNode &L, ElemType a);
void Insert(bitLNode L, ElemType pos);
bool isEnpty(bitLNode L);
void print(bitLNode L);
int main() {
  bitLNode L;
  InitLNode(L);
  AddLNode(L, 2);
  AddLNode(L, 2);
  AddLNode(L, 2);
  AddLNode(L, 2);
  AddLNode(L, 2);
  print(L);
  return 0;
}
void InitLNode(bitLNode &L) {
  L = (bitLNode)malloc(sizeof(LNode));
  L->next = NULL;
  if (L == NULL) {
    printf("初始化失败！！！");
  }
}
void AddLNode(bitLNode &L, ElemType a) {
  bitLNode s;
  //创建节点，然后插入到头结点之后
  // s指向新申请的节点
  s = (LNode *)malloc(sizeof(LNode));
  //数据域s->data = c1 赋值
  s->data = a;
  //初始化
  s->next = NULL;
  s->next = L->next;
  L->next = s;
}
void Insert(bitLNode L, ElemType pos) {
  if (pos < 0) {
    printf("位置不合法！！！");
  }
  while () {
  }
}
//为空返回true
bool isEnpty(bitLNode L) {
  if (L->next != NULL) {
    return false;
  }
  return true;
}

void print(bitLNode L) {
  bitLNode s;
  if (isEnpty(L) == false) {
    s = L->next;
    printf("该链表的数据为：");
    while (s != NULL) {
      printf("%d ", s->data);
      s = s->next;
    }
  } else {
    printf("该链表为空！！！");
  }
}
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define ERROR 1
typedef int Position;
typedef struct SNode {
  ElementType *Data; /* 存储元素的数组 */
  Position Top;      /* 栈顶指针 */
  int MaxSize;       /* 堆栈最大容量 */
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
int main() {
  Stack s;
  s = CreateStack(10);
  for (int i = 0; i < 10; i++) {
    printf("入栈 %d\n", i);
    Push(s, i);
  }
  for (int i = 0; i < 10; i++) {
    printf("出栈 %d\n", Pop(s));
  }
  return 0;
}
Stack CreateStack(int MaxSize) {
  Stack S = (Stack)malloc(sizeof(SNode));
  S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  S->Top = -1;
  S->MaxSize = MaxSize;
  return S;
}

bool IsFull(Stack S) { return (S->Top == S->MaxSize - 1); }

bool Push(Stack S, ElementType X) {
  if (IsFull(S)) {
    printf("堆栈满");
    return false;
  } else {
    S->Data[++(S->Top)] = X;
    return true;
  }
}

bool IsEmpty(Stack S) { return (S->Top == -1); }

ElementType Pop(Stack S) {
  if (IsEmpty(S)) {
    printf("堆栈空");
    return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
  } else
    return (S->Data[(S->Top)--]);
}