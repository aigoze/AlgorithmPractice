//
//  recursion.cpp
//  Algorithms
//
//  Created by Jiandong Huang on 7/3/2019.
//  Copyright © 2019 Jiandong Huang. All rights reserved.
//

#include "recursion.hpp"
//Calculates factorial of a positive integer
//n*(n-1)
int Fact(int n){
    if (n == 0) {
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return n * Fact(n-1);
    }
}
// Hannoi problems
void TowersOfHanoi(int n, char fromPeg, char toPeg, char auxPeg){
    if (n == 1) {
        printf("move disk 1 from %c Peg to %c Peg", fromPeg, toPeg);
    }
    TowersOfHanoi(n-1, fromPeg, auxPeg, toPeg);
    printf("move disk %d from %c Peg, to %c Peg, using %c", n, fromPeg, toPeg, auxPeg);
    TowersOfHanoi(n-1, auxPeg, toPeg, fromPeg);
}
//generate a total of n binary string
char A[100]; // for instance n = 100
void Binary(int n){
    if (n <= 1) {
        printf("%s", A);
    }
    A[n - 1] = 0;
    Binary(n - 1);
    A[n - 1] = 1;
    Binary(n - 1);
}

//Generate n strings with selection from k numbers(0,1,2...k-1)
void kstring(int n, int k){
    if (n < 1) {
        printf("%c", A);
    }
    for (int j = 0; j < k; j ++) {
        A[n-1] = j;
        kstring(n-1, k);
    }
}






