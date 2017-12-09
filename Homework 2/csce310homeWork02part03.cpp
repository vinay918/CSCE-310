#include <vector>
#include "csce310homeWork02part03.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

int ourQuickSelect( vector<int> number , int position ){
    position=position-1;
    int comparisons=0;
    int left=0;
    int right=number.size()-1;
    int correctIndex=-1;
    tuple<int,int,vector<int>> output;

    while(correctIndex!=position && left<right){

        if(position>correctIndex){
            left=correctIndex+1;
        }else{
            right=correctIndex-1;
        }
        output=pivot(number,left,right);
        correctIndex=get<0>(output);
        comparisons=comparisons+get<1>(output);
        number=get<2>(output);
    }

    if(position==correctIndex){
        return comparisons;

    }
    return -1;

}

tuple<int,int,vector<int>> pivot(vector<int> number, int left, int right){
    int pivotIndex=left;
    int comparisons=0;
    for(int i=left+1;i<=right;i++){
        comparisons++;
        if(number[i]<number[pivotIndex]){
            int j=i;
            while(j>pivotIndex){
                int temp = number[j];
                number[j]=number[j-1];
                number[j-1]=temp;
                j--;
            }
            pivotIndex++;
        }
    }

    return std::make_tuple(pivotIndex,comparisons,number);
}


