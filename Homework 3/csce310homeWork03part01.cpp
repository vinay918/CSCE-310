#include <vector>
#include "csce310homeWork03part01.h"
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

double minimumST( vector< vector<double> > adjacencyMatrix ){

// initialize a boolean vector for whether all nodes are visited or not
  std::vector<bool> visited(adjacencyMatrix.size());
  for(int k=0;k<visited.size();k++){
    visited[k]=false;
  }
  //add first node to the MST
  visited[0]=true;

  double totalValue=0;

  while(hasNegative(visited)){
    double connectNode=-1;
    double currentValue=0;
   //for loops to connect the smallest edge from the MST to an unconnected node
    for(int i=0; i<visited.size();i++){
        if(visited[i]==true){ //for each of the currently connected nodes
            for(int j=0;j<visited.size();j++){
                //condition to check if node is unconnected, has a path and smaller than the current smallest edge available
                if( visited[j]==false && adjacencyMatrix[i][j] != 0 && (adjacencyMatrix[i][j]<currentValue || currentValue==0)){
                    connectNode=j;
                    currentValue=adjacencyMatrix[i][j];
                }
            }
        }
    }
    if(connectNode!=-1){
        visited[connectNode]=true;
        totalValue=totalValue+currentValue;
    }
  }
  return totalValue;
}

bool hasNegative(vector<bool> visited){
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            return true;
        }
    }
    return false;
}
