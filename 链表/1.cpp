 #include<stdio.h>
 #include<stdlib.h>
 #define ElemType int
 typedef struct LNode{
    //������
    ElemType data;
    //ָ����
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
 		printf("��ʼ��ʧ�ܣ�����");
 	}
 }
 void AddLNode(bitLNode &L,ElemType a){
 	bitLNode s;
    //�����ڵ㣬Ȼ����뵽ͷ���֮��
    //sָ��������Ľڵ�
    s = (LNode*)malloc(sizeof(LNode));
    //������s->data = c1 ��ֵ
    s->data = a;
    //��ʼ��
    s->next = NULL;
    s->next = L->next;
    L->next = s;

	printf("��ӳɹ�");
 } 
 //Ϊ�շ���true 
 bool isEnpty(bitLNode L){
 	if(L->next!=NULL){
 		return false;
 	}
 	return true;
 }
 
 void print(bitLNode L){
 	LNode *p;
	if(isEnpty(L)==false){
 		printf("�����������Ϊ��");
 		while(L->next!=NULL){
 			printf("%d ",L->data);	
 		} 
 	}else{
 		printf("������Ϊ�գ�����");
 	}
 }
