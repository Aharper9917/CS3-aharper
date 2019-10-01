/*
Author: Allen Harper
Date: 9/20/19
Description: Solution for kattis problem; https://open.kattis.com/problems/putovanje
https://docs.google.com/document/d/1ATmHqwDpr81xYQ5ytg-dmLFyXsXpbafoHxfF5B67xa8/edit
*/

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int solve(){

}

void test() {

    cout << "Tested. All passed...";
}

int main(int argc, const char** argv) {
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else
        solve();
    
    // Pull data in
    vector<int> food_found;
    int num_of_food, stomach_size, temp;
    cin >> num_of_food >> stomach_size;
    for (int i = 0; i < num_of_food; i++)
    {
        cin >> temp;
        food_found.push_back(temp);
    }

    // print input
    cout << "food_found: ";
    for(auto z : food_found){
        cout << z << ' ';
    }
    cout << "\nnum_of_food: " << num_of_food << endl
         << "stomach_size: " << stomach_size << endl;

    return 0;
}

