/**
 * name listP.h
 * 链表类头文件
 * 2019.1.4
*/
//#include<iostream>

#include <stddef.h>
// assert的作用是现计算表达式 expression，如果其值为假（即为0），那么它先向stderr打印一条出错信息
#include <assert.h>

//using namespace std;

typedef int listItemType;
struct listNode;
typedef listNode* ptrType;
class listClass{
    private:
        //list长度
        int Size;
        //Head
        ptrType Head;
        
        ptrType PtrTo(int Position) const;
 
    public:
        //构造函数
        listClass();
        listClass(const listClass &L);
        //析构函数
        ~listClass();
        //操作集
        //list是否为空
        bool ListIsEmpty() const;
        //list的长度
        int ListLenght() const;

        //插入
        void ListInsert(int NewPosition,listItemType NewItem,bool& Success);
        //删除
        void ListDelete(int Position,bool &Success);
        
        void ListRetrieve(int Position,listItemType &DataItem,bool& Success) const;
};


/**
 * name listP.cpp
 * 链表实现类
 * 2019.1.4
 */
//数据对象集
struct listNode{
    //数据域
    listItemType Item;
    //指针域
    ptrType Next;
};
//初始化
listClass::listClass():Size(0),Head(NULL){}
listClass::listClass(const listClass& L):Size(L.Size){
    if(L.Head==NULL){
        Head=NULL;
    }else{
        Head = new listNode;
        assert(Head!=NULL);
        Head->Item=L.Head->Item;
        ptrType Newptr = Head;
        for(ptrType OrigPtr=L.Head->Next;OrigPtr!=NULL;OrigPtr=OrigPtr->Next){
            Newptr -> Next =new listNode;
            assert(Newptr->Next!=NULL);
            Newptr=Newptr->Next;
            Newptr->Item - OrigPtr->Item;
        }
        Newptr -> Next = NULL;
    }
}

listClass::~listClass(){
    bool Success;
    while(!ListIsEmpty())
        ListDelete(1,Success);
}

bool listClass::ListIsEmpty() const{
    return bool(Size==0);
}

int listClass::ListLenght()const{
    return Size;
}
//返回指针域 
ptrType listClass::PtrTo(int Position) const {
    if((Position<1)||(Position>ListLenght())){
        return NULL;
    }else{
        ptrType Cur = Head;
        for(int skip=1;skip<Position;skip++){
        	 Cur = Cur -> Next;
        } 
        return Cur;
    }
}

void listClass::ListInsert(int NewPostion,listItemType NewItem,bool& Success){
    int NewLenght = ListLenght() + 1;
    Success = bool((NewPostion>=1)&&(NewPostion<=NewLenght));
    if(Success){
        ptrType Newptr = new listNode;
        Success = bool(Newptr!=NULL);
        if(Success){
            Size = NewLenght;
            Newptr->Item = NewItem;
            if(NewPostion==1){
                Newptr->Next = Head;
                Head = Newptr;
            }else{
                ptrType prev = PtrTo(NewPostion-1);
                Newptr->Next = prev->Next;
                prev->Next = Newptr;
            }
        }
    }
}

void listClass::ListDelete(int Position, bool& Success) {
    ptrType Cur;
    Success = bool((Position>=1)&&(Position<=Size));
    if(Success){
        Size--;
        if(Position==1){
            Cur = Head;
            Head = Head->Next;
        }else{
        	
            ptrType prev = PtrTo(Position-1);
            Cur  = prev->Next;
            prev->Next = Cur->Next;
			
        }
        delete Cur;
        Cur = NULL;
    }
}

void listClass::ListRetrieve(int Position, listItemType& DataItem, bool& Success) const {
    Success = bool((Position>=1)&&(Position<=Size));
    if(Success){
        ptrType Cur = PtrTo(Position);
        DataItem = Cur ->Item;
    }
}


