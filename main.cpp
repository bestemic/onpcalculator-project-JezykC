#include <iostream>  
#include "stack.hpp"
#include <sstream>

using namespace std; 
  
int main() 
{ 
    string linia, slowo;
    
    cout<<"Type '?', 'h' or 'help' for help."<<endl;
    cout<<"["<<StackSize()<<"] ";
    while(getline(cin, linia))          //pobieranie danych 
    {
        istringstream iss(linia);       //dzielenie linni na poszczególne "słowa"
        while(iss >> slowo)
        {
            if(Operation(slowo)==-1)    //sprawdzenie czy podczas obsługi stosu nie pojawił się błąd
            {
                break; 
            }
        }
        cout<<"["<<StackSize()<<"] ";
    }
      
    return 0; 
}