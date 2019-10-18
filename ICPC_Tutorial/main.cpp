/*
Author: Allen Harper
Date: 10/16/19
Description: Solution for kattis problem: https://open.kattis.com/problems/tutorial
*/
#include <math.h>
#include <iostream>
#include <cassert>
#include <stdio.h>
#include <string.h>
using namespace std;

int solve(int m, int n, int t){
    int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
    return  t == 1 ? (n > 12 || factorials[n] > m) ? 0 : 1 :
            t == 2 ? pow(2,n) <= m:
            t == 3 ? pow(n,4) <= m:
            t == 4 ? pow(n,3) <= m:
            t == 5 ? pow(n,2) <= m:
            t == 6 ? log2(n)*n <= m:
                        n <= m;
}

void test() {
    assert(solve(100000000, 500, 3) == 0);
    assert(solve(100000000, 50, 3) == 1);
    assert(solve(100000000, 10001, 5) == 0);
    assert(solve(100000000, 10000, 5) == 1);
    assert(solve(19931568, 1000000, 6) == 0);
    assert(solve(19931569, 1000000, 6) == 1);
    cout << "Tested. All passed...";
}

int main(int argc, const char** argv) {
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else{
        // cin >> m >> n >> t;
        int m, n, t;
        scanf("%d %d %d",&m,&n,&t);
        printf(solve(m,n,t) ? "AC\n" : "TLE\n"); // if 1 print AC else print TLE

    }
    return 0;
}

