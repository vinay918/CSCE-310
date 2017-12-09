#include <vector>
#include "csce310homeWork03part03.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int hornersRule( vector<int> coeffs , int value ){

  double tempSum=coeffs[0];
  for(int i=1;i<coeffs.size();i++){
    tempSum=value*tempSum+coeffs[i];
  }
  return tempSum;
}
