#include "csce310homeWork01part02.h"
#include <string>
#include <iostream>

using namespace std;

void printPermutations( string word , int permutations )
{
int k;
int j;
int left;
int right;

  for( int i = 0; i < permutations; i++ ){

     k=word.length()-2;
     j=k+1;


     //first permutation is the string itself
        cout << word << endl;


     //find the index where word(k)<word(k+1)
        while(k>0 && word.at(k)>=word.at(k+1) ){
            k=k-1;
        }

     //find index where word(j)>word(i)
        while(word.at(j)<=word.at(k) && j>0){
            j=j-1;
        }


     //validation and then swapping
        if(word.at(k)<word.at(k+1) && word.at(j)>word.at(k)){
            std::swap(word[k], word[j]);
        }


     //to reverse the remaining items

        left=k+1;
        right=word.length()-1;


        word=reverseIndex(left,right,word);

  }
  return;
}

string reverseIndex(int index1, int index2, string word)
{
    while(index1<index2){
        std::swap(word[index1], word[index2]);
        index1=index1+1;
        index2=index2-1;
    }
    return word;
}
