 #include<stdio.h>
 #include<stdlib.h>
 #define ElemType int
 typedef struct LNode{
    //数据域
    ElemType data;
    //指针域
    struct LNode *next;
 }LNode,*bitLNode;
 void InitLNode(bitLNode &L);
 void AddLNode(bitLNode &L,ElemType a);
 bool isEnpty(bitLNode L);
 void print(bitLNode L);
 int main(){
 	bitLNode L;
	InitLNode(L);
	AddLNode(L,2);
	//print(L); 
 	return 0;
 } 
 void InitLNode(bitLNode &L){
 	L = (bitLNode)malloc(sizeof(LNode));
 	L->next = NULL;
 	if(L==NULL){
 		printf("初始化失败！！！");
 	}
 }
 void AddLNode(bitLNode &L,ElemType a){
 	bitLNode s;
    //创建节点，然后插入到头结点之后
    //s指向新申请的节点
    s = (LNode*)malloc(sizeof(LNode));
    //数据域s->data = c1 赋值
    s->data = a;
    //初始化
    s->next = NULL;
    s->next = L->next;
    L->next = s;

	printf("添加成功");
 } 
 //为空返回true 
 bool isEnpty(bitLNode L){
 	if(L->next!=NULL){
 		return false;
 	}
 	return true;
 }
 
 void print(bitLNode L){
 	LNode *p;
	if(isEnpty(L)==false){
 		printf("该链表的数据为：");
 		while(L->next!=NULL){
 			printf("%d ",L->data);	
 		} 
 	}else{
 		printf("该链表为空！！！");
 	}
 }
