#include <vector>
#include "csce310homeWork02part02.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int overlappingIntervals( vector<int> start , vector<int> end1 ){
    int maxInterval=0;
    int currentInterval=0;
    int starts=0;
    int ends=0;
    std::string endpoint;
    std::map<string,int> endpoints;
    vector<int> allElements = start;
    allElements.insert(allElements.end(),end1.begin(),end1.end());
    sort(allElements.begin(),allElements.end());

    for(int j=0;j<end1.size();j++){
        endpoint=std::to_string(end1[j]);
        endpoints[endpoint]= end1[j];
    }

    for(int i=0;i<allElements.size();i++){
        if(endpoints.find(std::to_string(allElements[i]))==endpoints.end()){
            starts++;
            currentInterval=starts-ends;
        }
        else if(endpoints.find(std::to_string(allElements[i]))!=endpoints.end()){
            ends++;
            currentInterval=starts-ends;
        }
        if(currentInterval>maxInterval){
            maxInterval=currentInterval;
        }
    }
  return maxInterval;
}

