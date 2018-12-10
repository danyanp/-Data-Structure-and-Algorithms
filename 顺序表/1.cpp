#include<iostream>
#define MAXSIZE 10
#define ElemType int
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//数据对象集 
typedef struct Node{
    ElemType data[MAXSIZE];
    int last;
}Node,*bitNode;
//操作集
//初始化 L 
bitNode InitNode();
//根据位序k返回元素 
void FindKth(bitNode L,int k);
//再线性表L内，查找X出现的第一次位置
int Find(bitNode L,int X);
//在位序i前面添加一个新元素X
bool Insert( bitNode L, ElemType X, int P);
//删除指定位序的元素
bool Delete(bitNode L,int P);
//放回顺序表长度
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
	printf("位置在：%d \n",Find(L,3));
	printf("删除位置2：\n");
	Delete(L,2);
	print(L);
    return 0;
}
/* 初始化 */
bitNode InitNode()
{
	bitNode L;
    L = (bitNode)malloc(sizeof(struct Node));
    L->last = -1;
    return L;
}
 
/* 查找 */
#define ERROR -1
 
int Find(bitNode L, ElemType X)
{
    int i = 0;
 
    while( i <= L->last && L->data[i]!= X )
        i++;
    if ( i > L->last )  return ERROR; /* 如果没找到，返回错误信息 */
    else  return i;  /* 找到后返回的是存储位置 */
}
 
/* 插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Insert( bitNode L, ElemType X, int P ) 
{ /* 在L的指定位置P前插入一个新元素X */
    int i;
    if ( L->last == MAXSIZE-1) {
        /* 表空间已满，不能插入 */
        printf("表满"); 
        return false; 
    }  
    if ( P<0 || P>L->last+1 ) { /* 检查插入位置的合法性 */
        printf("位置不合法");
        return false; 
    } 
    for( i=L->last; i>=P; i-- )
        L->data[i+1] = L->data[i]; /* 将位置P及以后的元素顺序向后移动 */
    L->data[P] = X;  /* 新元素插入 */
    L->last++;       /* Last仍指向最后元素 */
    return true; 
} 
 
/* 删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Delete( bitNode L, int P )
{ /* 从L中删除指定位置P的元素 */
    int i;
    if( P<0 || P>L->last ) { /* 检查空表及删除位置的合法性 */
        printf("位置%d不存在元素", P ); 
        return false; 
    }
    for( i=P+1; i<=L->last; i++ )
        L->data[i-1] = L->data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
    L->last--; /* Last仍指向最后元素 */
    return true;   
}
int Lengh(bitNode L){
	return L->last;
} 
void print(bitNode L){
	if(L->last==-1){
		printf("表内为空");
	}else{
		for(int i=0;i<=L->last;i++){
			printf("%d ",L->data[i]);
		}
	}
	
}
