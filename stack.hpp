#include <stack>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef stack_hpp
#define stack_hpp

extern stack<double> stos;

void StackPush(double x);       //funkcja umieszczająca element na stosie
double StackPop();              //funkcja zdejmująca element ze stosu
void StackPeek(int n);          //funkcja wypisująca zadaną ilość elementów stosu
int StackSize();                //funkcja zwracająca zajęte miejsce na stosie

///poniższe funkcje zwracają 0 jeśli wykonają się poprawnie, w przeciwnym razie -1

int Operation(string slowo);    //funkcja obsługująca wpisane operacje

//funkcje wykonująca działania matematyczne 
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