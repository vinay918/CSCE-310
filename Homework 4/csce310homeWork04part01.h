#ifndef CSCE310HOMEWORK01PART01_H
#define CSCE310HOMEWORK01PART01_H
#include <vector>
using namespace std;

double optimalBST( vector<double> );

double mySum(int start, int to, vector<double> numbers);

double calcMin(int row, int col, std::vector< std::vector<double> > myTable);

void printTable(std::vector< std::vector<double> > myTable);
#endif

