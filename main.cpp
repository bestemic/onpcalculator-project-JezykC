#include <iostream>  
#include "stack.hpp"
#include <sstream>

using namespace std; 
  
int main() 
{ 
    string linia, slowo;
    
    cout<<"Type '?', 'h' or 'help' for help."<<endl;
    cout<<"["<<StackSize()<<"] ";
    while(getline(cin, linia))
    {
        istringstream iss(linia);
        while(iss >> slowo)
        {
            if(Operation(slowo)==-1) 
            {
                break; 
            }
        }
        cout<<"["<<StackSize()<<"] ";
    }
      
    return 0; 
}