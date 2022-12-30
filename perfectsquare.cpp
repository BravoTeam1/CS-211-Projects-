#include <iostream>
#include <cmath>
using namespace std;

int main(){
  for (int i = 1; i > 0; i++){
    int num = i*i;
    int a = num % 10;
    int b = (num % 100) / 10;
    
    if (a % 2 !=0 && b % 2 != 0){
    cout << num << endl;
      break;
    }
    if (i < 100){
      cout << "No such number is found." << endl;
      break;
    }
  }
  return 0;
}
  

