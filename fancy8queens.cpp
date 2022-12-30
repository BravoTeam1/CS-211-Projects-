#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
  for(int i = 0; i < c; i++){
    if(q[i] == q[c] || (c-i) == abs(q[c] - q[i]))
      return false; 
    }
  return true;
}


void print(int q[]){
  int i,j,k,l;

  typedef char box[5][7];

  box bb, wb, *board[8][8];
  box wq, bq;

  static int solution = 1;
  //fill in bb (black boxes) & wb (white boxes)
  for(i=0; i<5; i++)
    for(j=0; j<7; j++){
      wb[i][j]=' ';
      wq[i][j]= ' ';
      bq[i][j]= char(219);
      bb[i][j]= char(219);
    }
  wq[1][1] = char(219);
			   wq[2][1] = char(219);
			   wq[3][1] = char(219);
			   wq[3][2] = char(219);
			   wq[3][3] = char(219);
			   wq[3][4] = char(219);
			   wq[3][5] = char(219);
			   wq[2][3] = char(219);
			   wq[1][3] = char(219);
			   wq[1][5] = char(219);
			   wq[2][5] = char(219);
			   
	bq[1][1] = ' ';
			   bq[2][1] = ' ';
			   bq[3][1] = ' ';
			   bq[3][2] = ' ';
			   bq[3][3] = ' ';
			   bq[3][4] = ' ';
			   bq[3][5] = ' ';
			   bq[2][3] = ' ';
			   bq[1][3] = ' ';
			   bq[1][5] = ' ';
			   bq[2][5] = ' ';

  //fill board with pointers to bb and wb in alternate positions 
  for(i=0; i<8; i++)
    for(j=0; j<8; j++)
      if((i+j) %2 == 0)
        board[i][j]= &wb;
        else
        board[i][j]= &bb;

  for(i=0; i<8; i++){
    if((q[i] + i) % 2 == 0)
      board[i][q[i]] = &wq;
    else
      board[i][q[i]] = &bq;
  }

  cout << "Configuration #" << solution++ << ":" << endl;

  //first print upper border 
  cout << " ";
  for(i=0; i<7*8; i++)
    cout<< ' ';
  cout << endl;

  //print the board
for(i=0; i<7; i++)
  for(k=0; k<5; k++){
    cout << " " <<char(179); //print border
    for(j=0; j<8; j++)
      for(l=0; l<7; l++)
        cout << (*board[i][j])[k][l];
    cout << char(179) << endl; //end of the line print bar and then newline
  }

  //before exiting print lower border
  cout << " ";
  for(i=0; i<7*8; i++)
    cout << char(196);
  cout << endl;
  cout<< endl;
}

void next (int q[], int c){
  if(c == 8){
    print(q);
  }
  else for(q[c] = 0; q[c] < 8; q[c]++)
    if(ok(q,c))
      next(q, c+1);
}

int main(){
  int q[8];
  next(q, 0);
  return 0;
}
