# Data-Structure-and-Algorithms
## 数据结构与算法

## 线性表
- 顺序表
    - 数据对象集
        ```
        typedef struct Node{
            ElemType data[MAXSIZE];
            int last;
        }Node,*bitNode;
        ```
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

- 链表

