#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int cnt = 0;
int p[6], book[6];
void dfs(int step) {
  if (step == 6) {
    cout << p[1] << p[2] << p[3] << p[4] << p[5] << endl;
    int a = p[1], b = p[2], c = p[3], d = p[4], e = p[5];
    int n1 = a * 10 + b, n2 = c * 100 + d * 10 + e, n3 = a * 100 + d * 10 + b,
        n4 = c * 10 + e;
    if (n1 * n2 == n3 * n4) {
      cnt++;
    }
    return;
  }
  for (int i = 1; i <= 9; i++) {
    if (book[i] == 0) {
      p[step] = i;
      book[i] = 1;
      dfs(step + 1);
      book[i] = 0;
    }
  }
  return;
}
int main() {
  memset(book, 0, sizeof(int) * 5);
  dfs(1);
  cout << cnt << endl;
  return 0;
}