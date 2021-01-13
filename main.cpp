#include <iostream>  
#include "stack.hpp"
#include <sstream>
#include <fstream>

using namespace std; 

void konw(string linia)
{
    string slowo;
    istringstream iss(linia);       //dzielenie linni na poszczególne "słowa"
    while(iss >> slowo)
    {
        if(Operation(slowo)==-1)    //sprawdzenie czy podczas obsługi stosu nie pojawił się błąd
        {
            break; 
        }
    }
}
  
int main(int argc, char *argv[]) 
{ 
    string linia;
    if(argc==2)                              //obsługa jeśli dane podane w pliku
    {
        fstream plik;
        plik.open(argv[1]);
        while(getline(plik, linia))          //pobieranie danych 
        {
            konw(linia);
        }
        plik.close();
    }
    else
    {
        cout<<"Type '?', 'h' or 'help' for help."<<endl;
        cout<<"["<<StackSize()<<"] ";
        while(getline(cin, linia))          //pobieranie danych 
        {
            konw(linia);
            cout<<"["<<StackSize()<<"] ";
        }  
    }
    return 0; 
}
