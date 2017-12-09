#include <vector>
#include "csce310homeWork02part01.h"
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

bool sumToN( vector<int> number , int value ){
    std::map<int,int> table;
    for(int i=0;i<number.size();i++){
        if(table.find(value-number[i])!=table.end()){
            return true;
        }
        else{
            table[number[i]]=number[i];
        }
    }
  return false;
}
