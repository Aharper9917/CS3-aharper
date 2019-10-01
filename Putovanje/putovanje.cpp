/*
Author: Allen Harper
Date: 9/20/19
Description: Solution for kattis problem: https://open.kattis.com/problems/putovanje
https://docs.google.com/document/d/1ATmHqwDpr81xYQ5ytg-dmLFyXsXpbafoHxfF5B67xa8/edit
*/

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;


int solve(int stomach_size, vector<int> food_found){
    int b = 0;
    for (int i = 0; i < food_found.size(); i++){
        int t = 0;
        int m = 0;
        for(int j = i; j < food_found.size(); j++){
            if(t + food_found[j] <= stomach_size){
                t += food_found[j];
                m += 1;
            }
        }
        b = max(b, m);
    }
    return b;
}

void test() {
    int a1 = 5;
    vector<int> v1 = {3, 1, 2, 1, 1};
    int a2 = 5;
    vector<int> v2 = {1, 5, 4, 3, 2, 1, 1};
    int a3 = 10;
    vector<int> v3 = {3, 2, 5, 4, 3};

    assert(solve(a1, v1) == 4);
    assert(solve(a2, v2) == 3);
    assert(solve(a3, v3) == 3);
    cout << "Tested. All passed...";
}

int main(int argc, const char** argv) {
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else{
        // Pull data in
        vector<int> food_found;
        int num_of_food, stomach_size, temp;
        cin >> num_of_food >> stomach_size;
        for (int i = 0; i < num_of_food; i++)
        {
            cin >> temp;
            food_found.push_back(temp);
        }
        cout << solve(stomach_size, food_found);
    }
    
    return 0;
}

