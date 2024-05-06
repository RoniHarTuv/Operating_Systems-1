#include <iostream>
#include<vector>
using namespace std;

int infinityRecursion(int a) {
   return infinityRecursion(a*2);

}
int main (){
  infinityRecursion(5);
  return 0;
}


//ddd ./ex1 core