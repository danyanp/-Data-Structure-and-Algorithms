#include <iostream>
using namespace std;
//链表的的结点
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class List_Node{
	private:	

	public:
         //创建一个单向链表
         ListNode* list_Create();
         //打印单向链表
         void list_Print(ListNode* pHead);
         //插入单向链表
         ListNode* list_Insert(ListNode* pHead, int x, int y);
         //删除单向链表中的值为data的结点
         ListNode* listDelete(ListNode* pHead, int data);
         //单向链表的销毁
         int listDestory(ListNode* pHead);
};
ListNode* List_Node::list_Create() {
  ListNode *pHead, *pCurrent, *pNew;
  int data;  // 不断输入的数据
  pHead = new ListNode(0);
  pCurrent = pHead;
  cin >> data;
  while (data != -1) {
    pNew = new ListNode(data);  // 1.创建新节点
    pCurrent->next = pNew;      // 2.插入新节点
    pCurrent = pNew;            // 3.让新节点变成当前节点
    cin >> data;
  }
  return pHead->next;  //因为上面代码中的头文件不是输入数据，只是为了方便操作
} 
void List_Node::list_Print(ListNode* pHead) {
  ListNode* tem;
  if (pHead == NULL) return;
  tem = pHead;  //养成好习惯：对传入的数据用另外一个临时变量接住
  while (tem) {
    cout << tem->val << "	";
    tem = tem->next;
  }
  cout << endl;
}
//在链表中值为x的结点后面插入y值的新节点
ListNode* List_Node::list_Insert(ListNode* pHead, int x, int y)  	
{
  if (pHead == NULL) return NULL;
  ListNode *pCurrent, *pNew;
  pCurrent = pHead;
  pNew = new ListNode(y);
  while (pCurrent) {
    if (pCurrent->val == x) break;
    pCurrent = pCurrent->next;
  }
  pNew->next =pCurrent->next;  //在单向链表中，一定要注意当前节点的位置存放在前面结点的next域中
  pCurrent->next =pNew;  //所以赋值的过程中是从后面的结点向前面的结点赋值的，而且指针指向谁，就赋给谁
  return pHead;
}
ListNode* List_Node::listDelete(ListNode* pHead, int data) {
  if (pHead == NULL) return NULL;
  ListNode *pPre, *pCurrent;
  pPre = pHead;
  pCurrent = pPre->next;
  // pNew = new ListNode(data);
  while (pCurrent) {
    if (pCurrent->val == data) break;
    pPre = pCurrent;
    pCurrent = pCurrent->next;
  }
  if (pCurrent == NULL)
    cout << "未能找到值为：" << data << "的结点" << endl;
  else {
    pPre->next = pCurrent->next;
    delete pCurrent;
  }
  return pHead;
}
int List_Node::listDestory(ListNode* pHead) {
  if (pHead == NULL) return 0;
  ListNode* tem = NULL;
  while (pHead) {
    tem = pHead->next;
    delete pHead;
    pHead = tem;
  }
  return 0;
}
int  main()
{
  //新建链表测试
  // ListNode* node = list_Create();
  //打印链表测试
  // list_Print(node);

  //插入链表测试
  // ListNode* node5 = list_Insert(node ,10,999);
  // list_Print(node5);

  //删除链表测试
  // ListNode* node6 = listDelete(node,20);
  // list_Print(node6);

  //销毁链表测试
  // int node7 = listDestory(node);

  return 0;
} 

