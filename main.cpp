#include <iostream>
#include <stdint.h>
#include "Int8Stack.h"

#define iArrayLength 10
int8_t i8Array[iArrayLength] = {24, 2, 84, 9, 10, 3, 29, 24, 9, 10};
int8_t i8Result[2] = {29, 84};

void return2Greatest()
{
    int ii = 0;
    bool firstFound = false, secondFound = false;
    while ((ii < iArrayLength) && (!firstFound || !secondFound)) {
        if(!firstFound && (i8Array[ii] == i8Result[0]) ) {
            printf("Found pos: %d\n", ii);
            firstFound = true;
        }
        if(!secondFound && (i8Array[ii] == i8Result[1])) {
            printf("Found pos: %d\n", ii);
            secondFound = true;
        }
        ++ii;
    }
}

uint8_t u8Minuend;
int8_t i8Subtrahend;

void ifTernario()
{
    int8_t i8ResultAux = 150;  //-106
    u8Minuend = 250;
    i8Subtrahend = 100;

    //printf("u8Minuend: %d.\n", u8Minuend);
    //printf("i8Subtrahend: %d.\n", i8Subtrahend);
    //printf("u8Minuend-i8Subtrahend: %d.\n", (u8Minuend-i8Subtrahend));
    //printf("i8Result: %d.\n", i8ResultAux);
    //printf("u8Minuend > i8Subtrahend: %d\n", (int8_t) (u8Minuend > i8Subtrahend));

    i8ResultAux = (u8Minuend > i8Subtrahend) ? (int8_t) (u8Minuend - i8Subtrahend) : i8ResultAux;
    //i8ResultAux = (int8_t) (u8Minuend - i8Subtrahend);
    //i8ResultAux = i8ResultAux;

    printf("The operation result is %d.\r\n", i8ResultAux);
    // 150-128 = 22
    // 128-22 = 106
}

int main()
{
    //return2Greatest();
    //ifTernario();

    Int8Stack s;

    s.init();
    s.push(24);
    s.push(42);
    s.pop();

    return 0;
}