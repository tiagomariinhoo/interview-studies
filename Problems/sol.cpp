#include <bits/stdc++.h>

using namespace std;



int main () {
  ofstream outdata;
  outdata.open("kkkkinfamy.text");
  for(int i = 1; i <= 3000; i++) {
    outdata << i << "," << endl;
  }
  outdata.close();

  return 0;
}