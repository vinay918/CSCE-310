#include <vector>
#include "csce310homeWork03part02.h"
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int i ){

    int rows=adjacencyMatrix.size();
    int columns=adjacencyMatrix[0].size();

    for(int j=0;j<i;j++){

        for(int k=0;k<rows;k++){

                for(int z=0;z<columns;z++){

                    if( adjacencyMatrix[k][j] !=-1 && adjacencyMatrix[j][z]!=-1 ){

                        if(adjacencyMatrix[k][z]!=-1){
                            adjacencyMatrix[k][z] = std::min(adjacencyMatrix[k][z],(adjacencyMatrix[k][j]+adjacencyMatrix[j][z]));
                        }else{
                            adjacencyMatrix[k][z]= adjacencyMatrix[k][j]+adjacencyMatrix[j][z];
                        }
                    }
                }

        }

    }
  return adjacencyMatrix;
}
