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
    int n = rand(1, 10);
    printf("%d\n", n);
    set<int> used_x;
    set<int> used_y;
    for(int i = 0; i < n; ++i) {
        int x,y;
        do {
            x = rand(1, 10);
            y = rand(1, 10);
        } while(used_x.count(x)||used_y.count(y));
        if(i==n-1) printf("%d %d", x,y);
        else printf("%d %d\n", x,y);
        used_x.insert(x);
        used_y.insert(y);
    }
    puts("");
}