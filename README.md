# Data-Structure-and-Algorithms
## 数据结构与算法

## 线性表
- ### 顺序表
    - 数据对象集
        ```
        typedef struct Node{
            ElemType data[MAXSIZE];
            int last;
        }Node,*bitNode;
        ```
        ![Image text](https://raw.githubusercontent.com/danyanp/Data-Structure-and-Algorithms/master/%E9%A1%BA%E5%BA%8F%E8%A1%A8/%E9%A1%BA%E5%BA%8F%E8%A1%A8.png)

     - 操作集
        ```
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
        //打印L
        void print(bitNode L); 
        ```
        

- ### 链表
     - 数据对象集
        ```
        typedef struct LNode{
            //数据域
            ElemType data;
            //指针域
            Node *next
        }LNode,*bitLNode;
        ```
       ![image text](
         https://raw.githubusercontent.com/danyanp/Data-Structure-and-Algorithms/master/%E9%93%BE%E8%A1%A8/%E5%8D%95%E9%93%BE%E8%A1%A8.png
     )
     - 操作集
        ```
        //初始化 L 
        bitLNode InitNode();
        //!!!!!坑坑坑，在初始化链表的时候，要LNode *&L双重引用
        //添加(在末尾添加)
        void AddLNode();
        //插入(在一个数后面差插入)
        void Insert();
        //删除
        void DeleteLNode();
        //查找
        void FindLNode();
        //判断是否为空(如果list是空的则返回true)
        bool isEepty();
        //长度
        void Length();
        //打印链表
        void print();
        ```
