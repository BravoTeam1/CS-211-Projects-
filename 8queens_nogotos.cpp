#include <iostream>
using namespace std;

bool ok (int q[], int c){ 
  for (int i = 0; i < c; i++){
    if ((q[i] == q[c]) || ((c - i) == abs(q[c] - q[i]))){
      return false;
    }
  }
  return true;
}

void backtrack (int & c){
  c --; 
  if (c == -1){
    exit(0);
  }
}

void print (int q[]){
  static int numSolutions = 1; // starts at 1 and will later increment until it hits #92 possible solutions 
  cout << "Configuration #" << numSolutions++ << ":";
  cout << endl;
  //print array 
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(q[i] == j){ 
        cout << "Q ";
      }
      else { 
        cout << "_ ";
      } 
    }
    cout << endl;
  }
  cout << endl;
}

int main(){
  int q[8] = {}; //intitialize the array to 0
  int c = 0; // first row, first col
  q[0] = 0;

  while (c >= 0){ // loop ends if you backtrack from the first col
    c++; // move to the next col 

    if (c == 8){ // reached the last col
      print(q); // call the print function and backtrack 
      backtrack(c);
    }
    else{ 
      q[c] = -1;
    }

    while (c >= 0){
      q[c]++; // move to the next row

      if (q[c]== 8){ // reach the last col, so backtrack
        backtrack(c);
      }
      else { // call the ok function. if returns true, go back to the beginning of the outer loop
        if (ok(q, c) == true){
          break;
        }
      }
    }
  }
  return 0;
}