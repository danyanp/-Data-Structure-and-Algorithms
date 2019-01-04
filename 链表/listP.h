/**
 * name listP.h
 * ������ͷ�ļ�
 * 2019.1.4
*/
//#include<iostream>

#include <stddef.h>
// assert���������ּ�����ʽ expression�������ֵΪ�٣���Ϊ0������ô������stderr��ӡһ��������Ϣ
#include <assert.h>

//using namespace std;

typedef int listItemType;
struct listNode;
typedef listNode* ptrType;
class listClass{
    private:
        //list����
        int Size;
        //Head
        ptrType Head;
        
        ptrType PtrTo(int Position) const;
 
    public:
        //���캯��
        listClass();
        listClass(const listClass &L);
        //��������
        ~listClass();
        //������
        //list�Ƿ�Ϊ��
        bool ListIsEmpty() const;
        //list�ĳ���
        int ListLenght() const;

        //����
        void ListInsert(int NewPosition,listItemType NewItem,bool& Success);
        //ɾ��
        void ListDelete(int Position,bool &Success);
        
        void ListRetrieve(int Position,listItemType &DataItem,bool& Success) const;
};


/**
 * name listP.cpp
 * ����ʵ����
 * 2019.1.4
 */
//���ݶ���
struct listNode{
    //������
    listItemType Item;
    //ָ����
    ptrType Next;
};
//��ʼ��
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
//����ָ���� 
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


