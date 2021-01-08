// generating a random sequence of distinct elements
//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(3, 10);
    printf("%d\n", n);
    set<int> used_x;
    /* set<int> used_y; */
    for(int i = 0; i < n; ++i) {
        int x;
        x = rand(0, 10);
        /* do {
            x = rand(0, 10);
        } while(used_x.count(x)||used_y.count(y)); */
        if(i==n-1)
        {
            printf("%d",x);
        }
        else
        {
            printf("%d ", x);
        }
        /* used_x.insert(x); */
        /* used_y.insert(y); */
    }
    puts("");
}