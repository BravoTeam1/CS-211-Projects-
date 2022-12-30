#include <iostream>
#include <iomanip>
using namespace std;

bool ok(int q[], int c){
  for (int i = 0; i < c; i++){
    if (q[i] == q[c] || (c-i) == abs(q[i] - q[c]))
      return false;
  }
  return true;
}

int nqueens(int n){
  int *q = new int[n]; // Dynamically declare an array of size n and initialize the first element to 0
  q[0] = 0;
  int c = 0, solutions = 0;    
  
  while (c >= 0) { 
    if (c == n-1) { 
      solutions++;
      c--;
    }
    else                  
      q[++c] = -1;
    while (c >= 0) {
      q[c]++;           
      if (q[c] == n)    
        c--;
      else if (ok(q, c)) 
        break;
    }
  }
  delete[] q;
  return solutions;
}

int main(){
  int n = 8;
  for(int i = 1; i <= n; i++)
    cout << "There are " << setw(2) << nqueens(i) << " solutions to the "  << i << " queens problem." << endl;
  return 0;
}

