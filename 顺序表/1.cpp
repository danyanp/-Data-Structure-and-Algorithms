#include<iostream>
#define MAXSIZE 10
#define ElemType int
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//���ݶ��� 
typedef struct Node{
    ElemType data[MAXSIZE];
    int last;
}Node,*bitNode;
//������
//��ʼ�� L 
bitNode InitNode();
//����λ��k����Ԫ�� 
void FindKth(bitNode L,int k);
//�����Ա�L�ڣ�����X���ֵĵ�һ��λ��
int Find(bitNode L,int X);
//��λ��iǰ�����һ����Ԫ��X
bool Insert( bitNode L, ElemType X, int P);
//ɾ��ָ��λ���Ԫ��
bool Delete(bitNode L,int P);
//�Ż�˳�����
int Lengh(bitNode L); 
void print(bitNode L); 
int main()
{
	bitNode L;
	L = InitNode();
	Insert(L,1,0); 
	Insert(L,2,1);
	Insert(L,3,2);
	Insert(L,4,3);
	print(L);
	printf("\n");
	printf("λ���ڣ�%d \n",Find(L,3));
	printf("ɾ��λ��2��\n");
	Delete(L,2);
	print(L);
    return 0;
}
/* ��ʼ�� */
bitNode InitNode()
{
	bitNode L;
    L = (bitNode)malloc(sizeof(struct Node));
    L->last = -1;
    return L;
}
 
/* ���� */
#define ERROR -1
 
int Find(bitNode L, ElemType X)
{
    int i = 0;
 
    while( i <= L->last && L->data[i]!= X )
        i++;
    if ( i > L->last )  return ERROR; /* ���û�ҵ������ش�����Ϣ */
    else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}
 
/* ���� */
/*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Insert( bitNode L, ElemType X, int P ) 
{ /* ��L��ָ��λ��Pǰ����һ����Ԫ��X */
    int i;
    if ( L->last == MAXSIZE-1) {
        /* ��ռ����������ܲ��� */
        printf("����"); 
        return false; 
    }  
    if ( P<0 || P>L->last+1 ) { /* ������λ�õĺϷ��� */
        printf("λ�ò��Ϸ�");
        return false; 
    } 
    for( i=L->last; i>=P; i-- )
        L->data[i+1] = L->data[i]; /* ��λ��P���Ժ��Ԫ��˳������ƶ� */
    L->data[P] = X;  /* ��Ԫ�ز��� */
    L->last++;       /* Last��ָ�����Ԫ�� */
    return true; 
} 
 
/* ɾ�� */
/*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Delete( bitNode L, int P )
{ /* ��L��ɾ��ָ��λ��P��Ԫ�� */
    int i;
    if( P<0 || P>L->last ) { /* ���ձ�ɾ��λ�õĺϷ��� */
        printf("λ��%d������Ԫ��", P ); 
        return false; 
    }
    for( i=P+1; i<=L->last; i++ )
        L->data[i-1] = L->data[i]; /* ��λ��P+1���Ժ��Ԫ��˳����ǰ�ƶ� */
    L->last--; /* Last��ָ�����Ԫ�� */
    return true;   
}
int Lengh(bitNode L){
	return L->last;
} 
void print(bitNode L){
	if(L->last==-1){
		printf("����Ϊ��");
	}else{
		for(int i=0;i<=L->last;i++){
			printf("%d ",L->data[i]);
		}
	}
	
}
