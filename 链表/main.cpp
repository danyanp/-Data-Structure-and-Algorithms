#include <iostream>
#include "listP.h"
using namespace std;
class Solution {
 public:
  listClass addTwoNumbers(listClass l1, listClass l2) {
    bool Success;
    int DataItem;
    
    
    for (int i = 1; i <= l1.ListLenght(); i++) {
      l1.ListRetrieve(i,DataItem, Success);
      cout << DataItem << endl;
    }
    
	 for (int j = 1; j <= l2.ListLenght(); j++) {
      l2.ListRetrieve(j,DataItem, Success);
      cout << DataItem << endl;
    }
    return l1;
  }
};
int main() {
  //输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
  //输出：7 -> 0 -> 8
  //原因：342 + 465 = 807

  bool Success;
  //��̬����listClass L1;
  //��̬���� 
  listClass* L1 = new listClass();
  L1->ListInsert(1, 2, Success);
  L1->ListInsert(2, 4, Success);
  L1->ListInsert(3, 3, Success);
  listClass L2;

  L2.ListInsert(1, 5, Success);
  L2.ListInsert(2, 6, Success);
  L2.ListInsert(3, 4, Success);

  Solution s;
  s.addTwoNumbers(*L1, L2);
  return 0;
}

