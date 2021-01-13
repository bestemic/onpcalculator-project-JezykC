#include "stack.hpp"

std::stack<double> stos;

int Operation(string slowo)
{
    char* p;
    double zmienna = strtod(slowo.c_str(), &p);         //konwersja i sprawdzenie czy podane słowo jest liczbą
    if(*p)
    {
        //jeśli nie liczba sprawdzenie czy to nazwa operacji i wykonanie niej
        if(slowo == "add")
        {
            return add();
        }
        else if(slowo == "sub")
        {
            return sub();
        }
        else if(slowo == "mul")
        {
            return mul();
        }
        else if(slowo == "div")
        {
            return divide();
        }
        else if(slowo == "pow")
        {
            return power();
        }
        else if(slowo == "neg")
        {
            return neg();
        }
        else if(slowo == "abs")
        {
            return absolut();
        }
        else if(slowo == "sin")
        {
            return sinus();
        }
        else if(slowo == "cos")
        {
            return cosinus();
        }
        else if(slowo == "log")
        {
            return logarytm();
        }
        else if(slowo == "exp")
        {
            return exponenta();
        }
        else if(slowo == "min")
        {
            return minimum();
        }
        else if(slowo == "max")
        {
            return maksimum();
        }
        else if(slowo == "gamma")
        {
            return gama();
        }
        else if(slowo == "bc")
        {
            return BinCoeff();
        }
        else if(slowo == "?" || slowo == "h" || slowo == "help")
        {
            cout<<"Operacje arytmetyczne:"<<endl;
            cout<<"add, sub, mul, div, pow, neg, abs, sin, cos, log, exp, min, max, gamma, bc"<<endl;
            cout<<"Inne:"<<endl;
            cout<<"?, h, help, q, quit, =, pstack, dup, exch"<<endl;
            return 0;
        }
        else if(slowo == "q" || slowo == "quit")
        {
            if(StackSize()==0)
            {
                cout<<"Stos jest pusty nie mozna wypisac"<<endl;
                exit(0);
            }
            else
            {
                StackPeek(StackSize());
                exit(0);
            } 
        }
        else if(slowo == "=")
        {
            if(StackSize()==0)
            {
                cout<<"Stos jest pusty"<<endl;
                return -1;
            }
            else
            {
                StackPeek(0);
                return 0;
            }  
        }
        else if(slowo == "pstack")
        {
            if(StackSize()==0)
            {
                cout<<"Stos jest pusty"<<endl;
                return -1;
            }
            else
            {
                StackPeek(StackSize());
                return 0;
            }   
        }
        else if(slowo == "dup")
        {
            return dup();
        }
        else if(slowo == "exch")
        {
            return exch();
        }
        else
        {
            if(StackSize()>0) StackPeek(StackSize());
            cout<<"Niewlasciwy operator"<<endl;
            return -1;
        }  
    }
    else 
    {
        StackPush(zmienna);     //jeśli liczba to wrzucenie jej na stos
        return 0;
    }
        
}

void StackPush(double x)
{
    stos.push(x);
}

int StackSize()
{
    return stos.size();
}

double StackPop()
{
    double liczba = stos.top();
    stos.pop();
    return liczba;
}

void StackPeek(int n)
{
    stack<double> pom;
    double pom1;
    if(n==0)
    {
        cout<<stos.top()<<endl;
    }
    else
    { 
        for(int i=0; i<n; i++)
        {
            pom1 = StackPop();
            pom.push(pom1);
        }
        while(!pom.empty())
        {
            pom1 = pom.top();
            cout<<pom1<<" ";
            StackPush(pom1);
            pom.pop();
        }
        cout<<endl;
    }
}

int add()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(b+a);
        return 0;
    }
    
}

int sub()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(b-a);
        return 0;
    }
    
}

int mul()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(b*a);
        return 0;
    }
    
}

int divide()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        if(a==0)
        {
            StackPush(a);
            StackPeek(StackSize());
            cout<<"Nie mozna dzielic przez 0"<<endl;
            return -1;
        }
        else
        {
            b = StackPop();
            StackPush(b/a);
            return 0;
        }
    }
    
}

int power()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(pow(b, a));
        return 0;
    }
}

int neg()
{
    double a; 
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(a*(-1));
        return 0;
    }
    
}

int absolut()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(fabs(a));
        return 0;
    }  
}

int sinus()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(sin(a));
        return 0;
    }  
}

int cosinus()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(cos(a));
        return 0;
    }  
}

int logarytm()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        if(a<=0)
        {
            StackPush(a);
            StackPeek(StackSize());
            cout<<"Nie mozna obliczyc logarytmu z liczy niedodatniej"<<endl;
            return -1;
        }
        else
        {
            StackPush(log(a));
            return 0;
        }       
    }  
}

int exponenta()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(exp(a));
        return 0;
    }  
}

int minimum()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        if(a<=b)
        {
            StackPush(a);
        }
        else StackPush(b);
        return 0;
    }
    
}

int maksimum()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        if(a>=b)
        {
            StackPush(a);
        }
        else StackPush(b);
        return 0;
    }
    
}

int gama()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        a = tgamma(a);
        if(isnan(a)==1 || isinf(a)==1)
        {
            cout<<"Niepoprawne dane"<<endl;
            return -1;
        }
        else
        {
            StackPush(a);
            return 0; 
        }     
    }  
}

int BinCoeff() 
{
    double j = 1;
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        b = StackPop();
        a = StackPop();
        if(a<b)
        {
            cout<<"Niepoprawne dane"<<endl;
            StackPush(a);
            StackPush(b);
            StackPeek(StackSize());
            return -1;
        }
        else
        {
            int i = a;
	        if(b < a - b) {
	            while(i >= a - b + 1) {
		            j = j * i / (a - i + 1);
		            i--;
	            }
    	    }
	        else if(b >= a - b) {
	            while(i >= b + 1) {
	          	    j = j * i / (a - i + 1);
		            i--;
	            }
    	    }
        }
        StackPush(j);
        return 0;
    }
}

int dup()
{
    double a;
    if(StackSize()<1)
    {
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        StackPush(a);
        StackPush(a);
        return 0;      
    }  
}

int exch()
{
    double a, b;
    if(StackSize()<2)
    {
        if(StackSize()==1) StackPeek(StackSize());
        cout<<"Za malo elementow na stosie"<<endl;
        return -1;
    }
    else
    {
        a = StackPop();
        b = StackPop();
        StackPush(a);
        StackPush(b);
        return 0;
    }
}








