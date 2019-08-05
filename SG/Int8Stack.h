//
// Created by diglett on 5/08/19.
//

#ifndef UNTITLED1_INT8STACK_H
#define UNTITLED1_INT8STACK_H

#include <iostream>
#include <stdint.h>

#define MAX_STACK_LENGTH 16

class Int8Stack {
public:
    static void init(void);
    static void push(int8_t i8Elem);
    static int8_t pop(void);

private:
    static int8_t i8Array[MAX_STACK_LENGTH];
    static int iIndex;

};

int8_t Int8Stack::i8Array[MAX_STACK_LENGTH];
int Int8Stack::iIndex;

void Int8Stack::init(void)
{
    printf("Init\n");
    iIndex = -1;
    for(int ii = 0; ii < MAX_STACK_LENGTH; ++ii) {
        i8Array[ii] = 0;
    }
}

void Int8Stack::push(int8_t i8Elem)
{
    printf("Push: %d\n", i8Elem);
    i8Array[++iIndex] = i8Elem;
}

int8_t Int8Stack::pop(void)
{
    int8_t aux = i8Array[iIndex--];
    printf("Pop: %d\n", aux);
    return aux;
}


#endif //UNTITLED1_INT8STACK_H
