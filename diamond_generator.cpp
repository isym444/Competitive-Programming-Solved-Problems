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
    int n = rand(2, 10);
    int k = rand(0,100);
    printf("%i %i\n", n,k);
    for(int i = 0; i < n; ++i) {
        int x;
        x = rand(1, 15);
        if(i==n-1) printf("%i", x);
        else printf("%i\n", x);
    }
    puts("");
}