#include "csce310homeWork04part01.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

double optimalBST( vector<double> numbers ){
  //create table
  std::vector< std::vector<double> > myTable(numbers.size()+1,std::vector<double>(numbers.size()+1, 0));

  //base case diagonal
  for(int row=0; row<myTable.size()-1; row++){
    myTable[row][row+1]=numbers[row];
  }

  //base cases for input of size 0 and 1
  if(numbers.size()==1){
    return numbers[0];
  }else if(numbers.size()==0){
    return 0;
  }

  bool rowFilled = false;
  int row=-1;
  int iteration=1;
  int col=1;
  while(!rowFilled){
    row=row+1;
    col=col+1;
    myTable[row][col] = (mySum(row,col-1,numbers) + calcMin(row,col,myTable));
    if(col==myTable[0].size()-1 && row==0){
        rowFilled=true;
  //      std::cout<<"rowFilled check true"<<endl;
    }
    if(!rowFilled && col==myTable[0].size()-1){
        row=-1;
        col=1+iteration;
        iteration++;
    }
   // printTable(myTable);
   // std::cout<<endl;
  }

  return myTable[0][myTable[0].size()-1];
}

double mySum(int start, int to, vector<double> numbers){
    double tempSum=0;
    for(int i=start; i<=to; i++ ){
        tempSum=tempSum+numbers[i];
    }
    return tempSum;
}

double calcMin(int row, int col, std::vector< std::vector<double> > myTable){
    double tempMin=std::numeric_limits<double>::infinity();
    int counter=1;
    for(int i=row;i<col;i++){
        tempMin=std::min(tempMin,myTable[row][i]+myTable[row+counter][col]);
        counter++;
    }
    return tempMin; //TO DO
}

void printTable(std::vector< std::vector<double> > myTable){
    for(int i=0;i<myTable.size();i++){
        for(int j=0;j<myTable[0].size();j++){
            std::cout<<myTable[i][j];
            std::cout<<",";
        }
        std::cout<<endl;
    }
}
