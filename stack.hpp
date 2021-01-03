#include <stack>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef stack_hpp
#define stack_hpp

extern stack<double> stos;

void StackPush(double x);
double StackPop();
void StackPeek(int n);
int StackSize();
int Operation(string slowo);
int add();
int sub();
int mul();
int divide();
int power();
int neg();
int absolut();
int sinus();
int cosinus();
int logarytm();
int exponenta();

#endif