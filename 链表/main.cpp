#include "listP.h"
#include <iostream>
using namespace std;
class Solution {
public:
    listClass addTwoNumbers(listClass l1, listClass l2) {
        
    }
};
int main(){
	
    listClass L;
    listItemType DataItem;
    bool Success;
    L.ListInsert(1,10,Success);
    L.ListInsert(2,20,Success);
    L.ListInsert(3,30,Success);
    L.ListInsert(4,40,Success);
    L.ListInsert(5,50,Success);
    cout << L.ListLenght() << endl;
    for(int i=1;i<=L.ListLenght();i++){
        L.ListRetrieve(i,DataItem,Success);
        cout << DataItem << endl;
    }
    L.ListDelete(5,Success);
    cout << L.ListLenght() << endl;
    for(int i=1;i<=L.ListLenght();i++){
        L.ListRetrieve(i,DataItem,Success);
        cout << DataItem << endl;
    }
    Solution s;
	s.addTwoNumbers(L,L);
    return 0;
}

