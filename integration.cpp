#include <iostream>
#include <cmath>
using namespace std;

//FUNC represents functions of one variable that takes a double as input and returns a double
typedef double(*FUNC)(double);

double integrate(FUNC f, double a, double b){
  double sum = 0;
  for(double i = a; i <= b; i += 0.001){
    sum += (0.001) * f(i);
  }
  return sum;
}


//this is the function y=x
double line(double x) {
  return x;
}

//this is the function y=x^2
double square(double x) {
  return x*x;
}

//this is the function y=x^3
double cube(double x) {
  return x*x*x;
}

int main(){
  cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
  cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
  cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;
  return 0;
}