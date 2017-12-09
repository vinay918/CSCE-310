#include "csce310homeWork04part03.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

bool makeThreeGroups( vector<int> numbers ){
    std::sort(numbers.begin(),numbers.end());
    std::reverse(numbers.begin(), numbers.end());
    float total = calSum(numbers);
    float sum = total/3;

    //automatic fail tests
    if(fmod(total,3)!=0){
        return false;
    }
    int ald=1;
    for(int iteration = 1 ; iteration <=2 ; iteration++){
        //creating table
        std::vector< std::vector<bool> > myTable(numbers.size()+1,std::vector<bool>(sum+1, false));

        //set base cases
        for(int i = 0; i<=numbers.size(); i++){
            myTable[i][0] = true;
        }

        //general cases
        for(int j=1;j<myTable.size();j++){
            for(int k=numbers[j-1];k<=sum;k++){
                if(k==numbers[j-1]){
                    myTable[j][k]=true;
                    for(int l=j;l<myTable.size();l++){
                        myTable[l][k]=true; //the whole column would then be true
                    }
                }else if(k>numbers[j-1] && myTable[j][k]==false && myTable[j-1][k-numbers[j-1]]==true){
                    myTable[j][k] = true;
                    for(int l=j;l<myTable.size();l++){
                        myTable[l][k]=true; //whole column would be true as well
                    }
                }
            }
        }

     //  for(int q=0;q<myTable.size();q++){
      //      for(int t=0;t<myTable[0].size();t++){
       //         std::cout<< myTable[q][t];
        //        std::cout<<",";
       //     }
       //     std::cout<<endl;
       // }

    // to check the last item in table and retrieve values if true
        if(myTable[myTable.size()-1][myTable[0].size()-1] == false )
            return false;
        else{
            int row=myTable.size()-1;
            int column=myTable[0].size()-1;
            std::vector<double> selectedPlayers;
            bool insufficient = true;
            while(insufficient){
                while(row-1>0 && myTable[row-1][column]==true){
                    row=row-1;
                }
                if(row!=0){
                    selectedPlayers.push_back(numbers[row-1]);
                    column = column - numbers[row-1];
                    numbers[row-1]=0; //remove this option now, possible !FIXME
                }
                if(row == 1){
                    insufficient=false;
                }
            }
          //  for(int ll=0;ll<selectedPlayers.size();ll++){
          //  std::cout<<selectedPlayers[ll];
          //  std::cout<<",";
          //  }
          // std::cout<<"list";
          // std::cout<<ald<<endl;
          // ald++;
        }
    }
    return true;
}

double calSum(vector<int> numbers){
    double tempSum=0;
    for(int i=0;i<numbers.size();i++){
        tempSum=tempSum+numbers[i];
    }
    return tempSum;
}
