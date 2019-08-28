/*
    this prog takes a 1 line input of ints seperated
    by spaces parses it recursivly and pushes it to a 
    vector then sorts then prints it
*/
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void split(string str, vector<int> &v){
    string str1;
    int found;

    if(str.find_last_of(" ") == str.length()-1){
        str = str.substr(0, str.find_last_of(" "));
    }
    if (str.find_last_of(" ") != -1){
        found = str.find_last_of(" ");
        str1 = str.substr(found+1, str.length());
        str = str.substr(0, found);
        v.push_back(stoi(str1.c_str()));
        return split(str, v);
    } else{
        v.push_back(stoi(str.c_str()));
    }
}

int main(){
    vector<int> v;
    string nums;

    cin.ignore();
    getline(cin, nums);
    split(nums, v);

    sort(v.begin(), v.end(), greater<int>()); 
    cout << "Vector: ";
    for(int n : v){
        cout << n << " ";
    }
    return 0;
}