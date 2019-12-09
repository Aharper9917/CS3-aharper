#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include<algorithm>
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 

using namespace std;

void genNums(int numOfNums, string outfile){
    ofstream fout;
    fout.open(outfile);
    // fout << "Writing this to a file.\n";
    srand(time(0)); 

	for(int i = 0; i<numOfNums; i++) 
        fout << rand() << ' ';

    fout.close();
}

int main(void) 
{ 
    genNums(100000, "100k.txt");
    genNums(500000, "500k.txt");
    genNums(1000000,"1mil.txt");
    genNums(100, "100Test.txt");
} 
