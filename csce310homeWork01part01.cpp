#include "csce310homeWork01part01.h"

using namespace std;

unsigned long long int oddDigits( unsigned long long int digits ){

  int spaces = 0;
  int oddNumbers=0;
  double n=digits;

  //To determine the number of digits
  while(n>=1){
    spaces+=1;
    n=n/10;
  }

  unsigned long long int quotient=1;
  //isolate individual digits and check if odd
  for(int i=0;i<spaces;i++){
    int temp = digits/quotient % 10;
    quotient=quotient*10;
    if(temp==1||temp==3||temp==5||temp==7||temp==9){
        oddNumbers+=1;
    }
  }

  return oddNumbers;
}
