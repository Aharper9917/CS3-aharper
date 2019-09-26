/*
Author: Allen Harper
Date: 9/20/19
Description: Solution for kattis problem; https://open.kattis.com/problems/cd
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stdio.h>
#include <string.h>
using namespace std;

int solve(vector<int> n_vector, vector<int> m_vector){
    vector<int> ans;
    set_intersection(n_vector.begin(), n_vector.end(),
                        m_vector.begin(), m_vector.end(), back_inserter(ans));
/*
    for(auto z : intersected){
        n_vector.erase(find(n_vector.begin(), n_vector.end(), z));
        m_vector.erase(find(m_vector.begin(), m_vector.end(), z));
    }
    cout << n_vector.size() + m_vector.size() << endl;
    cout << ans.size() << endl;
*/
    return ans.size();
}

void test() {
    vector<int> n1 = {1,2,3}, m1 = {1,2,4};
    assert(solve(n1, m1) == 2);
    vector<int> n2 = {1,2,3}, m2 = {4,5,6};
    assert(solve(n2, m2) == 0);
    vector<int> n3 = {1,2,3}, m3 = {1,2,3};
    assert(solve(n3, m3) == 3);
    cout << "Tested. All passed...";
}

int main(int argc, const char** argv) {
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else{
        int n, m;

        while (cin >> n >> m && n != 0 && m != 0)
        { 
            vector<int> n_vector, m_vector, ans;
            int num;
            for (int i = 0; i < m; i++) {
                cin >> num;
                n_vector.push_back(num);
            }
            for (int i = 0; i < m; i++) {
                cin >> num;
                m_vector.push_back(num);
            }
        cout << solve(n_vector, m_vector) << endl;
        }
    }   
    return 0;
}

