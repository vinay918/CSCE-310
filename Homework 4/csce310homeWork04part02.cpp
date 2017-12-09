#include "csce310homeWork04part02.h"

using namespace std;

unsigned long long int pellNumber( unsigned long long int number ){
  unsigned long long int nm2=0;
  unsigned long long int nm1=1;
  unsigned long long int n=0;

  if(number==0){
    return 0;
  }
  else if(number==1){
    return 1;
  }

  for(unsigned long long int i = 2; i<=number; i++){
    n=(2*nm1)+nm2;
    nm2=nm1;
    nm1=n;

  }
  return n;
}

