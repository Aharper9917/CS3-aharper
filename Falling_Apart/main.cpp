#include <iostream>
#include <vector>
#include <string>
//#include <bits/stdc++.h> 
#include <algorithm>
#include <cassert>
using namespace std;

string run(vector<int> v){
    int a=0, b=0;
    sort(v.rbegin(), v.rend());

    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 == 0){
            a += v[i];
        }
        else{
            b += v[i];
        }
    }
    string out = to_string(a) + ' ' + to_string(b);
    return out;
}

void test(){
    vector<int> t = {2,4,24,51,51,2};
    assert(run(t) == "77 57");
    vector<int> t1 = {3,1,2};
    assert(run(t1) == "4 2");
    vector<int> t2 = {1,2,2,1};
    assert(run(t2) == "3 3");
}

int main(){
    test();
    int n;

    cin >> n;
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }
    string ans = run(v);
    cout << ans;
    return 0;
}
