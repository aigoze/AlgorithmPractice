//
//  Stack.cpp
//  Algorithms
//
//  Created by Jiandong Huang on 20/3/2019.
//  Copyright © 2019 Jiandong Huang. All rights reserved.
//

#include "Stack.hpp"
#include <stdlib.h>

class Stack{
    struct ArrayStack {
        int top;
        int capacity;
        int *array;
    };
    struct ArrayStack *CreateStack(){
        struct ArrayStack *S = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
        if (!S) {
            return nullptr;
        }
        S->capacity = 1;
        S->top = -1;
        S->array = (int*)malloc(S->capacity * sizeof(int));
        if (!S) {
            return nullptr;
        }
        return S;
    }
    
    int IsEmptyStack(struct ArrayStack *S){
        return S->top == -1;
    }
    
    int IsFullStack(struct ArrayStack *S){
        return (S->top) == (S->capacity -1);
    }
    
    void Push(struct ArrayStack *S, int data){
        if (IsFullStack(S)) {
            printf("Stack overflow\n");
            return;
        }else{
            S->array[++S->top] = data;
        }
    }
    
    int Pop(struct ArrayStack *S){
        if (IsEmptyStack(S)) {
            printf("Stack is empty\n");
            return 0;
        }else{
            return S->array[S->top --];
        }
    }
    
    void DeleteStack(struct ArrayStack *S){
        if (S) {
            if (S->array) {
                free(S->array);
            }
            free(S);
        }
    }
};
