#include <iostream>
#include <string>
#include <cassert>
#include <map>

using namespace std;

string run(string str){
    map<string, string> testDict;
    testDict.insert(pair<string, string>("atcay", "cat"));
    testDict.insert(pair<string, string>("odgay", "god"));
    testDict.insert(pair<string, string>("ogday", "dog"));
    
    if (testDict.find(str) == testDict.end()){
        return "eh";
    } else {
        return testDict.find(str)->second;
    }
}

void test(){
    assert(run("atcay") == "cat");
    assert(run("ittenkay") == "eh");
    assert(run("ogday") == "dog");
}

int main(){
    test();
    map<string, string> dict;
    map<string, string>::iterator it1; 
    string in, a, b;

    while (getline(cin, in)) {   
        if (in.find(" ") == -1) {
            break;
        }
        a = in.substr(0, in.find(" "));
        b = in.substr(in.find(" ")+1, -1);
        
        dict.insert(pair<string, string>(b, a));
    }
    while (getline(cin, in)) {  
        if (dict.find(in) == dict.end()){
            cout << "eh" << endl;
        } else {
            cout << dict.find(in)->second << endl; 
        }
    }
    return 0;
}
