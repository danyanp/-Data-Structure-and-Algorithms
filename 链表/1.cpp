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
 void Insert(bitLNode L,ElemType pos);
 bool isEnpty(bitLNode L);
 void print(bitLNode L);
 int main(){
 	bitLNode L;
	InitLNode(L);
	AddLNode(L,2);
	AddLNode(L,2);
	AddLNode(L,2);
	AddLNode(L,2);
	AddLNode(L,2);	
	print(L); 
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
 } 
 void Insert(bitLNode L,ElemType pos){
 	if(pos<0){
 		printf("位置不合法！！！");
 	} 
 	while(){
 		
 	}
		
 }
 //为空返回true 
 bool isEnpty(bitLNode L){
 	if(L->next!=NULL){
 		return false;
 	}
 	return true;
 }
 
 void print(bitLNode L){
 	bitLNode s;
	if(isEnpty(L)==false){
		s = L->next; 
 		printf("该链表的数据为：");
 		while(s!=NULL){
 			printf("%d ",s->data);
			s = s->next;
 		} 
 	}else{
 		printf("该链表为空！！！");
 	}
 }
