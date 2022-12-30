#include <iostream>
using namespace std;

bool ok(int q[], int c){
  static int adj[8][5] = {
  {-1}, //0       
  {0, -1}, //1           
  {0, 1, -1}, //2       
  {0, 2, -1}, //3      
  {1, 2, -1}, //4          
  {1, 2, 3, 4, -1}, //5   
  {2, 3, 5, -1}, //6      
  {4, 5, 6, -1} //7         
  };

  for (int i = 0; i < c; i++){
    if (q[i]==q[c]){
      return false;
    }
    
    for (int i = 0; adj[c][i] != -1; i++){
      if (q[adj[c][i]] +1 == q[c] || q[adj[c][i]] -1 == q[c]){
        return false;
      }
    }
  }
  return true;
}

void printCross(int q[]){
  static int sol = 1; 
  cout << "Solution #" << sol++ << ": " << endl;
  cout << " " << q[1] << q[4] << endl;
  cout << q[0] << q[2] << q[5] << q[7] << endl;
  cout << " " << q[3] << q[6] << endl;
  cout << endl;
}

void next(int q[], int c){
  if (c == 8){
    printCross (q);
  }
  else for (q[c] = 1; q[c] < 9; q[c]++){
    if (ok(q, c))
      next (q, c+1);
  }
}

int main(){
  int q[8];
  next (q, 0);
  return 0;
}

